#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1]; // Waiting time = previous burst time + previous waiting time
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // Turnaround time = burst time + waiting time
    }
}

void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time
    findWaitingTime(processes, n, bt, wt);

    // Calculate turnaround time
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Print the Waiting Time and Turnaround Time for each process
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate and print average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("| P%d ", processes[i]);
    }
    printf("|\n");

    printf("-------------------------------------------------\n");
    printf("0");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d", tat[i]);
    }
    printf("\n");
}

int main()
{
    // Hardcoded process data
    int processes[] = {1, 2, 3, 4};                   // Process IDs
    int burst_time[] = {6, 8, 7, 3};                  // Burst times of the processes
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes

    // Calculate average times and display Gantt Chart
    findAverageTime(processes, n, burst_time);

    return 0;
}
