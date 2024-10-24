// C program for System calls - opendir(), readdir(), closedir()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir("D:");
    if (dir == NULL)
    {
        perror("Error in opening directory");
        return 1;
    }
    printf("Directory listing:\n");
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    if (closedir(dir) == -1)
    {
        perror("Close directory failed");
        return 1;
    }

    return 0;
}