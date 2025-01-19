// #include <stdio.h>
// This code does'nt consider arrival time, but the code can be made so to consider arrival time
// int main()
// {
//     int processes[] = {1, 2, 3, 4, 5};
//     int priority[] = {1, 5, 3, 2, 4};
//     int burst_time[] = {4, 6, 8, 10, 6};

//     int highest_priority = 1;

//     printf("Non preemptive priority scheduling\n");
//     printf("Processes\t BurstTime\t Priority\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("P%d\t\t %d\t\t %d\n", processes[i], burst_time[i], priority[i]);
//     }

//     int gantt[10];
//     int waitingtime[10], tat[10];

//     for (int i = 0; i < 5; i++)
//     {
//         if (priority[i] == highest_priority)
//         {
//             waitingtime[i] = burst_time[i];
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main()
{
    int processes[] = {1, 2, 3, 4, 5};   // Process IDs
    int priority[] = {1, 5, 3, 2, 4};    // Process priorities
    int burst_time[] = {4, 6, 8, 10, 6}; // Burst time for each process

    int n = 5; // Number of processes
    // Practice Swap
    int waiting_time[5], turnaround_time[5];
    int total_wt = 0, total_tat = 0; // Total waiting and turnaround time
}
