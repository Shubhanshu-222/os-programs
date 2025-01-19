#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size = 8;

void FCFS(int arr[], int head)
{
    int seek_count = 0;

    // Iterate through the request array
    for (int i = 0; i < size; i++)
    {
        // Directly calculate the absolute distance
        seek_count += abs(head - arr[i]);

        // Move the head to the current track
        head = arr[i];
    }

    // Print the total seek operations
    printf("Total number of seek operations: %d\n", seek_count);

    // Print the seek sequence
    printf("Seek Sequence is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// Driver code
int main()
{
    int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    FCFS(arr, head);

    return 0;
}
