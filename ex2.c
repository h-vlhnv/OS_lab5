#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n;
    if (argc != 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        if (fork() < 0) {
            perror("fork");
            return 1;
        }
        sleep(5);
    }

    return 0;
}