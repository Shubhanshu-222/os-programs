#include <stdio.h>

int main()
{
    int processes[] = {1, 2, 3, 4, 5};    // Process IDs
    int priority[] = {1, 5, 3, 2, 4};     // Process priorities (lower number = higher priority)
    int burst_time[] = {4, 6, 8, 10, 6};  // Burst times for each process
    int arrival_time[] = {0, 1, 2, 3, 4}; // Arrival times for each process

    int n = 5;                   // Number of processes
    int remaining_burst_time[5]; // Array to keep track of remaining burst times for preemptive scheduling
    int waiting_time[5], turnaround_time[5];
    int total_wt = 0, total_tat = 0; // Total waiting and turnaround time
    int time = 0;                    // Current time in the simulation
    int completed = 0;               // Number of completed processes

    // To track the Gantt chart execution
    int gantt_chart[100], gantt_index = 0; // Array to store the Gantt chart

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
    {
        remaining_burst_time[i] = burst_time[i];
    }

    // Preemptive Priority Scheduling Algorithm
    while (completed < n)
    {
        int highest_priority = 6; // Start with an impossible high value (lower number = higher priority)
        int selected_process = -1;

        // Find the process with the highest priority that has remaining burst time > 0 and has arrived
        for (int i = 0; i < n; i++)
        {
            if (remaining_burst_time[i] > 0 && arrival_time[i] <= time && priority[i] < highest_priority)
            {
                highest_priority = priority[i];
                selected_process = i;
            }
        }

        // If no process is ready to execute, increment time
        if (selected_process == -1)
        {
            time++;
            continue;
        }

        // Execute the selected process for 1 unit of time
        remaining_burst_time[selected_process]--;                 // Decrease remaining burst time
        gantt_chart[gantt_index++] = processes[selected_process]; // Add process to Gantt chart
        time++;                                                   // Increase the time

        // If the process finishes execution
        if (remaining_burst_time[selected_process] == 0)
        {
            completed++;                                                                                       // Increment completed processes
            turnaround_time[selected_process] = time - arrival_time[selected_process];                         // Turnaround time = current time - arrival time
            waiting_time[selected_process] = turnaround_time[selected_process] - burst_time[selected_process]; // Waiting time = turnaround time - burst time
        }
    }

    // Calculate total waiting and turnaround times
    for (int i = 0; i < n; i++)
    {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    // Print the results
    printf("Processes\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    // Gantt array is nice and simple
    //  Print Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_index; i++)
    {
        printf(" P%d |", gantt_chart[i]);
    }
    printf("\n");

    // Print average waiting and turnaround times
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
