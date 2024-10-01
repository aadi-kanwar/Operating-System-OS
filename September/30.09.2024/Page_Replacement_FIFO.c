// Page Replacement Algorithm - FIFO
// 30.09.2024

#include<stdlib.h>
#include<stdio.h>
#define MAX_PAGES 12
#define FRAME_SIZE 3

void displayFrames(int frames[], int size)
{
    printf("Frames: ");
    for(int i=0; i<size; i++)
    {
        if(frames[i] != -1)
        {
            printf("%d ", frames[i]);
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
}

int main()
{
    // int pages[MAX_PAGES] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4}; // Use either one set of pages
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int frames[FRAME_SIZE];
    int pageFaults = 0;
    int time = 0; // To keep track of the order of page loading.
    for(int i=0; i<FRAME_SIZE; i++)
    {
        frames[i] = -1; // Initializes empty frames with -1
    }
    printf("Page Replacememnt String: ");
    for(int i=0; i<MAX_PAGES; i++)
    {
        printf("%d ", pages[i]);
    }
    printf("\n");
    //Process each page request
    for(int i =0; i<MAX_PAGES; i++)
    {
        int page = pages[i];
        int j;
        int found = 0;
        for(j=0; j<FRAME_SIZE; j++)
        {
            if(frames[j] == page)
            {
                found = 1;
                break;
            }
        }
        //If page is not found in frames, we have a page fault
        if(!found)  //Replace the oldest page with FIFO
        {
            pageFaults++;  
            frames[time%FRAME_SIZE] = page;     //Replace the page at the index
            time++;
            displayFrames(frames, FRAME_SIZE);
        }
        if(found)
        {
            printf("Page %d already in frames. No page fault\n", page);
        }
        else
        {
            printf("Page %d caused a page fault\n", page);
        }
    }
    printf("Total page faults: %d\n", pageFaults);
    return 0;
}