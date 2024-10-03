// Optimal Page Replacement Algorithm
// 03.10.2024

#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50
int findOptimalPage(int pages[],int page_count, int frames[], int frame_count, int current_index)
{
    int i,j,farthest = current_index, replace_index = -1;
    // iterate through all the frames to find which one to replace
    for(i=0; i<frame_count; i++)
    {
        int found = 0;
        for(j=current_index; j<page_count; j++)
        {
            if(frames[i] == pages[j])
            {
                if(frames[i] == pages[j])
                {
                    found = 1;
                    if(j > farthest)
                    {
                        farthest = j;
                        replace_index = i;
                    }
                    break;
                }
            }
            if(!found)
            {
                return j;
            }
        }
    }
    return replace_index;
}

void optimalPageReplacement(int pages[], int page_count, int frame_count)
{
    int frames[MAX_FRAMES], i, j, faults = 0;
    for(i=0; i<frame_count; i++)
    {
        frames[i] = -1;
    }
    printf("Reference String: ");
    for(i=0; i<page_count; i++)
    {
        printf("%d ", pages[i]);
    }
    printf("\n");
    for(i=0; i<page_count; i++)
    {
        int page = pages[i];
        int found = 0;
        for(j=0; j<frame_count; j++)
        {
            if(frames[j] == page)
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int replace_index = findOptimalPage(pages, page_count, frames, frame_count, i);
            frames[replace_index] = page;
            faults++;

            printf("Page Faults : %d -> ",page);
            for(j=0; j<frame_count; j++)
            {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", faults);
}

int main()
{
    int pages[MAX_PAGES], page_count, frame_count, i;
    printf("Enter the number of pages: ");
    scanf("%d", &page_count);
    printf("Enter the reference string: ");
    for(i=0; i<page_count; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);
    optimalPageReplacement(pages, page_count, frame_count);
    return 0;
}