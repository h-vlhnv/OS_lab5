#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t p1, p2;
    clock_t start, end;

    p1 = fork();

    if (p1 == 0) {
        start = clock();
        end = clock();
        printf("Child 1: PID = %d, PPID = %d, time = %.3f ms\n",
               getpid(), getppid(),
               (double)(end - start) * 1000 / CLOCKS_PER_SEC);
        return 0;
    }

    start = clock();

    p2 = fork();

    if (p2 == 0) {
        start = clock();
        end = clock();
        printf("Child 2: PID = %d, PPID = %d, time = %.3f ms\n", getpid(), getppid(), (double)(end - start) * 1000 / CLOCKS_PER_SEC);
        return 0;
    }

    end = clock();
    printf("Main:    PID = %d, PPID = %d, time = %.3f ms\n", getpid(), getppid(), (double)(end - start) * 1000 / CLOCKS_PER_SEC);

    wait(NULL);
    wait(NULL);

    return 0;
}
