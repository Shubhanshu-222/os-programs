/*
 * Round Robin Scheduling Program in C
 */

#include <stdio.h>

int main()
{
    // Process and data initialization
    int n;
    int processes[5] = {1, 2, 3, 4, 5}; // Processes in correct order for the table
    int arr_time[5] = {0, 2, 4, 6, 8};
    int burst_time[5] = {3, 6, 4, 5, 2};
    int quantum_time = 4;

    n = sizeof(processes) / sizeof(processes[0]);

    int wait_time = 0, ta_time = 0, temp_burst_time[n];
    int x = n;

    // Copy burst times to temp_burst_time
    for (int i = 0; i < n; i++)
    {
        temp_burst_time[i] = burst_time[i];
    }

    // Variables for execution
    int total = 0, counter = 0, i;
    int completion_time[5] = {0}; // To store completion times

    // Gantt Chart setup
    printf("\nGantt Chart:\n");
    printf("|");

    for (total = 0, i = 0; x != 0;)
    {
        // Execute process if burst time fits within quantum
        if (temp_burst_time[i] <= quantum_time && temp_burst_time[i] > 0)
        {
            printf(" P%d (%d-%d) |", processes[i], total, total + temp_burst_time[i]);
            total = total + temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
            completion_time[i] = total;
        }
        else if (temp_burst_time[i] > 0)
        {
            printf(" P%d (%d-%d) |", processes[i], total, total + quantum_time);
            temp_burst_time[i] = temp_burst_time[i] - quantum_time;
            total += quantum_time;
        }

        // Process completion
        if (temp_burst_time[i] == 0 && counter == 1)
        {
            x--; // Decrement remaining processes, this is why you need to copy n
            counter = 0;
        }

        // Update index
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\n\nProcess\t ArrivalTime\t BurstTime\t Waiting Time\t Turnaround Time\n");
    // Display table in order of 1, 2, 3, 4, 5
    for (i = 0; i < n; i++)
    {
        int turnaround_time = completion_time[i] - arr_time[i];
        int waiting_time = turnaround_time - burst_time[i];
        printf("\nP%d \t\t%d \t\t%d \t\t%d \t\t%d", processes[i], arr_time[i], burst_time[i], waiting_time, turnaround_time);
        wait_time += waiting_time;
        ta_time += turnaround_time;
    }

    // Calculate and display averages
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    printf("\n\nAverage Waiting Time: %.2f", average_wait_time);
    printf("\nAvg Turnaround Time: %.2f", average_turnaround_time);

    return 0;
}
