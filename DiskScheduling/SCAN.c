#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199 // Do not forget to set low and high

int main()
{
    // Hardcoded values for disk locations
    int queue[20] = {176, 79, 34, 60, 92, 11, 41, 114}; // Example disk locations (requests)
    int head = 50;                                      // Initial head position
    int q_size = 8;                                     // Number of disk requests
    int temp, sum = 0;
    int dloc; // location of disk (head) in the queue

    printf("SCAN Disk Scheduling Algorithm\n");

    // Add head position to queue
    queue[q_size] = head;
    q_size++;

    // Sort the queue
    for (int i = 0; i < q_size - 1; i++)
    {
        for (int j = i + 1; j < q_size; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Locate the head in the sorted queue
    for (int i = 0; i < q_size; i++)
    {
        if (head == queue[i])
        {
            dloc = i;
            break;
        }
    }

    // If head is closer to LOW, start moving towards LOW, otherwise move towards HIGH
    if (abs(head - LOW) <= abs(head - HIGH))
    {
        // Move towards LOW first
        for (int j = dloc; j >= 0; j--)
        {
            printf("%d --> ", queue[j]);
            if (j != 0)
                sum += abs(queue[j] - queue[j - 1]); // Accumulate movement
        }
        for (int j = dloc + 1; j < q_size; j++)
        {
            printf("%d --> ", queue[j]);
            if (j != dloc + 1)
                sum += abs(queue[j] - queue[j - 1]); // Accumulate movement
        }
    }
    else
    {
        // Move towards HIGH first
        for (int j = dloc + 1; j < q_size; j++)
        {
            printf("%d --> ", queue[j]);
            if (j != dloc + 1)
                sum += abs(queue[j] - queue[j - 1]); // Accumulate movement
        }
        for (int j = dloc; j >= 0; j--)
        {
            printf("%d --> ", queue[j]);
            if (j != 0)
                sum += abs(queue[j] - queue[j - 1]); // Accumulate movement
        }
    }

    printf("\nTotal movement of cylinders: %d\n", sum);

    return 0;
}