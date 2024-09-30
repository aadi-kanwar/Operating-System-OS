// Page Replacement LRU
// 30.09.2024

#include<stdio.h>
#include<stdlib.h>
int findLRU(int time[], int n)
{
    int minimum = time[0], pos = 0;
    for(int i=1; i<n; i++)
    {
        if(time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int no_of_frames, no_of_pages, frames[3], pages[13]={7,0,1,2,0,3,0,4,2,3,0,3,2}, counter =0, time[3], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter the page reference string: ");
    for(i=0; i<no_of_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    for(i=0; i<no_of_frames; i++)
    {
        frames[i] = -1;
    }
    for(i=0;i<no_of_pages;++i)
    {
        flag1 = flag2 = 0;
        for(j=0; j<no_of_frames; j++)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0)
        {
            for(j=0; j<no_of_frames; j++)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        // Display frames after each page reference
        printf("\nFrames:");
        for(j=0; j<no_of_frames; j++)
        {
            if(frames[j] == -1)
            {
                printf(" - ");
            }
            else
            {
                printf("%d", frames[j]);
            }
        }
        printf("\n\nTotal Page Faults = %d\n", faults);
        return 0;
    }
}