```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char line[100];
    char *args[20];
    char path[100];
    int i;

    while (1) {
        printf("shell> ");
        fflush(stdout);

        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "exit\n") == 0)
            break;

        i = 0;
        args[i] = strtok(line, " \n");

        while (args[i] != NULL && i < 19) {
            i++;
            args[i] = strtok(NULL, " \n");
        }

        if (args[0] == NULL)
            continue;

        if (fork() == 0) {
            sprintf(path, "/bin/%s", args[0]);
            execve(path, args, NULL);

            sprintf(path, "/usr/bin/%s", args[0]);
            execve(path, args, NULL);

            printf("Command not found\n");
            exit(1);
        }
    }

    return 0;
}
```
