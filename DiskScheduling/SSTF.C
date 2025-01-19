#include <stdio.h>
#include <stdlib.h> // For abs() function

int size = 8; // Number of requests

// Function to find the SSTF (Shortest Seek Time First) Scheduling
void SSTF(int arr[], int head)
{
    int seek_count = 0;
    int visited[size]; // Array to keep track of visited requests
    int order[size];   // Array to store the order of requests processed
    int i, j;

    // Initially, all requests are unvisited
    for (i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    // Process all the requests - Main part
    for (i = 0; i < size; i++)
    {
        int min_distance = 9999; // Initialize with a large number
        int closest_request = -1;

        // Find the closest request (minimum seek time)
        for (j = 0; j < size; j++)
        {
            if (!visited[j])
            {
                int distance = abs(head - arr[j]);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    closest_request = j;
                }
            }
        }

        // Mark the request as visited
        visited[closest_request] = 1;

        // Store the order of processed requests
        order[i] = arr[closest_request];

        // Add the distance to the seek count
        seek_count = seek_count + min_distance;

        // Update the head position
        head = arr[closest_request];
    }

    // Outside of for loop

    // Print the total seek operations
    printf("Total number of seek operations: %d\n", seek_count);

    // Print the correct seek sequence (order of processed requests)
    printf("Seek Sequence is:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", order[i]);
    }
}

// Driver code
int main()
{
    int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    SSTF(arr, head);

    return 0;
}
