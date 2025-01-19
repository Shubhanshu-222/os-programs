#include <stdio.h>

int main()
{
    int processes[] = {1, 2, 3, 4, 5};   // Process IDs
    int priority[] = {1, 5, 3, 2, 4};    // Process priorities
    int burst_time[] = {4, 6, 8, 10, 6}; // Burst time for each process

    int n = 5; // Number of processes
    int waiting_time[5], turnaround_time[5];
    int total_wt = 0, total_tat = 0; // Total waiting and turnaround time

    // Step 1: Sort processes by priority
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                // Swap priorities
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst times
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap process IDs
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Step 2: Calculate waiting time and turnaround time
    waiting_time[0] = 0; // First process doesn't have to wait
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    // Turnaround time is the sum of waiting time and burst time
    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate total waiting and turnaround time
    for (int i = 0; i < n; i++)
    {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    // Step 3: Print the table in sorted order
    printf("Processes\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    // Step 4: Print Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\tP%d", processes[i]);
    }
    printf("\n");
    printf("    0\t");

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += burst_time[i];
        printf("    %d\t", time);
    }
    printf("\n");

    // Step 5: Print average waiting and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
