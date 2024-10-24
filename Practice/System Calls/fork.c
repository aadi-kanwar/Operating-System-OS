// C program for System calls - fork()
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    pid_t pid;
    pid = getpid();

    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }
    else
    {
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }
}