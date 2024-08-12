// Priority Scheduling
// 12.08.2024

#include<stdio.h>
struct process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int waiting;
    int turnaround;
    int completion;
};

//Function to swap two processes
void swap(struct process *a, struct process *b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

//Function to sort the processes based on priority (and arrival time if priorities are same)
void sortByPriority(struct process proc[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(proc[j].priority < proc[i].priority || (proc[i].priority == proc[j].priority && proc[i].arrival > proc[j].arrival))
            {
                swap(&proc[i], &proc[j]);
            }
        }
    }
}

//Function to calculate completion, turnaround and waiting times
void calculateTimes(struct process proc[], int n)
{
    int currentTime = 0;
    for(int i=0; i<n; i++)
    {
        if(proc[i].arrival > currentTime)
        {
            currentTime = proc[i].arrival;
        }
        proc[i].completion = currentTime + proc[i].burst;
        proc[i].turnaround = proc[i].completion - proc[i].arrival;
        proc[i].waiting = proc[i].turnaround - proc[i].burst;
        currentTime = proc[i].completion;
    }
}

//Function to print Gantt Chart, process details and summary
void printGanttChart(struct process proc[], int n)
{
    printf("Gantt Chart:\n");
    for(int i=0; i<n; i++)
    {
        printf("|P%d\t", proc[i].pid);
    }
    printf("|\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", proc[i].completion);
    }

    printf("\nPID\tPriority\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d\t%d\t\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].priority, proc[i].arrival, proc[i].burst, proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process proc[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter Process ID, Arrival Time, Burst Time and Priority for Process %d: ", i+1);
        scanf("%d %d %d %d", &proc[i].pid, &proc[i].arrival, &proc[i].burst, &proc[i].priority);
    }
    sortByPriority(proc, n);
    calculateTimes(proc, n);
    printGanttChart(proc, n);
    return 0;
}
