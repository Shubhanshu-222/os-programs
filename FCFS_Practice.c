#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) // bt is burst time, wt is waiting time
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1]; // sum of previous bt and wt
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // sum of current bt and wt
    }
}

void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("Process\tWaiting Time\tBurst Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], wt[i], bt[i], tat[i]);
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }

    // Gant Chart
    printf("\nGantt Chart:\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("| P%d\t", processes[i]);
    }
    printf("|\n");
    printf("--------------------------------------------\n");
    printf("0\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", tat[i]);
    }

    printf("\n\nAverage Waiting time is %.2f\n", (float)total_wt / n);
    printf("Average turnaround time is %.2f", (float)total_tat / n);

    printf("\n");
}

int main()
{
    int processes[] = {1, 2, 3, 4};
    int burst_Time[] = {6, 4, 10, 12};
    int n = sizeof(processes) / sizeof(processes[0]); // very important line

    findAverageTime(processes, n, burst_Time);

    return 0;
}