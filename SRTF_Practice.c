#include <stdio.h>

void main()
{
    int processes[] = {1, 2, 3, 4, 5}; // Process IDs
    int arrival[] = {0, 2, 4, 6, 8};   // Arrival times
    int burst[] = {3, 6, 4, 5, 2};     // Burst times
    int remaining[5], waiting[5], turnaround[5], completion[5];
    int gantt_chart[100], gantt_time = 0;
    int n = 5, time, count = 0;
    double avg_waiting = 0, avg_turnaround = 0;

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
    {
        remaining[i] = burst[i];
    }

    printf("\nStarting SRTF Scheduling...\n");

    // SRTF Scheduling algorithm
    for (time = 0; count < n; time++)
    {
        int smallest = -1;

        // Find the process with the smallest remaining burst time
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= time && remaining[i] > 0 && (smallest == -1 || remaining[i] < remaining[smallest]))
            {
                smallest = i;
            }
        }

        if (smallest != -1)
        {
            remaining[smallest]--;                           // Execute the process for 1 unit of time
            gantt_chart[gantt_time++] = processes[smallest]; // Record in Gantt chart

            // If the process finishes
            if (remaining[smallest] == 0)
            {
                count++;
                completion[smallest] = time + 1;
                waiting[smallest] = completion[smallest] - arrival[smallest] - burst[smallest];
                turnaround[smallest] = completion[smallest] - arrival[smallest];
            }
        }
    }

    // Output the result in a table
    printf("\npid \tarrival \tburst \twaiting \tturnaround \tcompletion\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d \t%d \t\t%d \t%d \t\t%d \t\t%d", processes[i], arrival[i], burst[i], waiting[i], turnaround[i], completion[i]);
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    // Print average waiting and turnaround times
    printf("\nAverage waiting time = %.2lf\n", avg_waiting / n);
    printf("Average Turnaround time = %.2lf\n", avg_turnaround / n);

    // Gantt chart visualization
    printf("\nGantt Chart (with time slots):\n");
    for (int i = 0; i < gantt_time; i++)
    {
        printf("| P%d\t ", gantt_chart[i]);
    }
    printf("|\n");

    printf("0\t");
    for (int i = 1; i <= gantt_time; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
}
