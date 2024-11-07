// SCAN Scheduling algorithm
// Created: 07.11.2024

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to sort the request array in ascending order
void sort(int arr[], int n)
{
   int t;
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (arr[i] > arr[j])
         {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
         }
      }
   }
}

// SCAN Disk Scheduling Implementation
void SCAN(int arr[], int n, int head, int dir)
{
   sort(arr, n);
   int total_seek_count = 0;
   int left = 0, right = 0;
   // Find closest request on left and right side of head
   for (int i = 0; i < n; i++)
   {
      if (arr[i] < head)
         left++;
      if (arr[i] > head)
         right++;
   }

   // Moving towards left
   if (dir == 0)
   {
      for (int i = left - 1; i >= 0; i--)
      {
         total_seek_count += abs(head - arr[i]);
         head = arr[i];
      }
      total_seek_count += abs(head - arr[0]);
      head = arr[0];
      for (int i = left; i < n; i++)
      {
         total_seek_count += abs(head - arr[i]);
         head = arr[i];
      }
   }

   // Moving towards right
   else if (dir == 1)
   {
      for (int i = right; i < n; i++)
      {
         total_seek_count += abs(head - arr[i]);
         head = arr[i];
      }
      total_seek_count += abs(head - arr[n - 1]);
      head = arr[n - 1];
      for (int i = right - 1; i >= 0; i--)
      {
         total_seek_count += abs(head - arr[i]);
         head = arr[i];
      }
   }
   printf("Total Seek Time: %d\n", total_seek_count);
}

int main()
{
   int n, head, dir, arr[MAX];
   printf("Enter the number of requests: ");
   scanf("%d", &n);
   printf("Enter the requests positions: ");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("Enter the current head position: ");
   scanf("%d", &head);
   printf("Enter the direction (0 for left, 1 for right): ");
   scanf("%d", &dir);
   printf("SCAN Disk Scheduling\n");
   SCAN(arr, n, head, dir);
   return 0;
}