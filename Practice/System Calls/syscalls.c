// C program for System calls - getpid(), getppid()
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    pid_t pid;
    // pid_t ppid;
    pid = getpid();
    printf("Process ID: %d\n", pid);

    // ppid = getppid();
    // printf("Parent Process ID: %d\n", ppid);
}