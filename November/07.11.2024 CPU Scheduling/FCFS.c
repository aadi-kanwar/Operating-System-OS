// Implement Disk scheduling algorithms using FCFS
//07.11.2024

#include <stdio.h>
#include <stdlib.h>
void FCFC(int requests[], int n, int head)
{
   int total_seek_time = 0;
   printf("Seek Sequence is: ");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", requests[i]);
      total_seek_time += abs(head - requests[i]);
      head = requests[i];
   }
   printf("End\n");
   printf("Total Seek Time: %d\n", total_seek_time);
   printf("Average Seek Time: %f\n", (float)total_seek_time / n);
}

int main()
{
   int n, head;
   printf("Enter the number of requests: ");
   scanf("%d", &n);
   int requests[n];
   printf("Enter the requests: ");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &requests[i]);
   }
   printf("Enter the head position: ");
   scanf("%d", &head);
   FCFC(requests, n, head);
   return 0;
}