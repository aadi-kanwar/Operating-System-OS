// Contiguous File Allocation
// 24.10.2024

#include <stdio.h>
#include <string.h>
#define MAX_FILES 50
typedef struct {
    int start;
    int length;
    char name[20];
} File;
File files[MAX_FILES];
int disk[100];
int totalblocks = 100;
int fileCount = 0;
void initializeDisk() {
    for (int i = 0; i < totalblocks; i++) {
        disk[i] = 0;
    }
}

void allocateFile()
{
    char name[20];
    int startblock, length;
    printf("Enter File Name: ");
    scanf("%s", name);
    printf("Enter Starting Block: ");
    scanf("%d", &startblock);
    printf("Enter file Length (number of blocks): ");
    scanf("%d", &length);
    if(startblock + length > totalblocks) {
        printf("Not enough space on disk\n");
        return;
    }
    for(int i = startblock; i < startblock + length; i++) {
        if(disk[i] == 1) {
            printf("Block %d is already allocated\n", i);
            return;
        }
    }
    for(int i = startblock; i < startblock + length; i++) {
        disk[i] = 1;
    }
    File newFile;
    newFile.start = startblock;
    newFile.length = length;
    strcpy(newFile.name, name);
    printf(newFile.name);
    files[fileCount++] = newFile;
    printf("File %s allocated from block %d to %d\n", name, startblock, startblock + length - 1);
}

void displayFiles()
{
    if(fileCount == 0) {
        printf("No files on disk\n");
        return;
    }
    printf("\nAllocated Files:\n");
    printf("File Name\tStart Block\tLength\n");
    for(int i = 0; i < fileCount; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].start, files[i].length);
    }
}

int main()
{
    int choice;
    initializeDisk();
    while(1)
    {
        printf("\nContiguous File Allocation\n");
        printf("1. Allocate File\n");
        printf("2. Display Files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                allocateFile();
                break;
            case 2:
                displayFiles();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}