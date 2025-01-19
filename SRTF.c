#include <stdio.h>

void main()
{
    // Hard-coded arrays for processes, burst times, and arrival times
    int processes[] = {1, 2, 3, 4, 5}; // Process IDs
    int a[10] = {0, 2, 4, 6, 8};       // Arrival times (example values)
    int b[10] = {3, 6, 4, 5, 2};       // Burst times (example values)
    int x[10];                         // To store the original burst times for calculation
    int waiting[10], turnaround[10], completion[10];
    int remaining[10];                          // To track remaining burst times
    int gantt_chart[100];                       // To store the sequence of processes over time
    int gantt_time = 0;                         // Time counter for the Gantt chart
    int i, j, smallest, count = 0, time, n = 5; // Set number of processes (n) to 5 for example
    double avg = 0, tt = 0, end;

    // Array sizes are hard-coded, so 'n' is fixed here as 5
    for (i = 0; i < n; i++)
    {
        x[i] = b[i];         // Copy burst times to 'x'
        remaining[i] = b[i]; // Initialize remaining burst times
    }

    printf("\nStarting SRTF Scheduling...\n");

    // Main scheduling loop (SRTF)
    for (time = 0; count != n; time++)
    {
        smallest = -1;
        for (i = 0; i < n; i++)
        {
            // Find the process with the smallest remaining burst time that has arrived
            if (a[i] <= time && remaining[i] > 0 && (smallest == -1 || remaining[i] < remaining[smallest]))
            {
                smallest = i;
            }
        }

        if (smallest != -1)
        {
            remaining[smallest]--; // Decrease the remaining burst time of the selected process

            // Record the process in the Gantt chart at this time slice
            gantt_chart[gantt_time] = processes[smallest];
            gantt_time++;

            // Check if the process is finished
            if (remaining[smallest] == 0)
            {
                count++;
                end = time + 1;
                completion[smallest] = end;
                waiting[smallest] = end - a[smallest] - x[smallest];
                turnaround[smallest] = end - a[smallest];
            }
        }
    }

    // Output the result in a table
    printf("\npid \tarrival \tburst \twaiting \tturnaround \tcompletion\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d \t%d \t\t%d \t%d \t\t%d \t\t%d", processes[i], a[i], x[i], waiting[i], turnaround[i], completion[i]);
        avg += waiting[i];
        tt += turnaround[i];
    }

    // Printing average waiting time and average turnaround time
    printf("\nAverage waiting time = %.2lf\n", avg / n);
    printf("Average Turnaround time = %.2lf\n", tt / n);

    // Gantt chart visualization (with time slots)
    printf("\nGantt Chart (with time slots):\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Print the processes at the top
    for (i = 0; i < gantt_time; i++)
    {
        printf("| P%d\t ", gantt_chart[i]);
    }
    printf("|\n");

    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Print the time values at the bottom
    printf("0\t");
    for (i = 1; i <= gantt_time; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
}
