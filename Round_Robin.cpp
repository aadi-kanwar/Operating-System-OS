// Round Robin Scheduling Algorithm

#include<stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n];
    findWaitingTime(n, bt, wt, quantum);
    findTurnAroundTime(n, bt, wt, tat);

    printf("Processes Burst Time Waiting Time Turn-Around Time\n");

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);
}

void rrScheduling(int processes[], int n, int bt[], int quantum)
{
    findavgTime(processes, n, bt, quantum);
}

int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8, 6};
    int quantum = 2;
    rrScheduling(processes, n, burst_time, quantum);
    return 0;
}