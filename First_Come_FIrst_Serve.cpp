// First Come First Serve Scheduling Algorithm

#include<stdio.h>
#include<conio.h>
void findWatiingTime( int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime( int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    findWatiingTime( n, bt, wt);
    findTurnAroundTime( n, bt, wt, tat);

    printf("Processes Burst Time Waiting Time Turn-Around Time\n");
    
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d\n", processes[i], bt[i], wt[i], tat[i]);
        // printf(" %d ", (i + 1));
        // printf(" %d ", bt[i]);
        // printf(" %d ", wt[i]);
        // printf(" %d\n", tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);
}

// Rearrange the processes according to the burst time
void sjfScheduling(int processes[], int n, int bt[])
{
    findavgTime(processes, n, bt);
}

int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {21, 3, 6, 2};
    sjfScheduling(processes, n, burst_time);
    return 0;
}