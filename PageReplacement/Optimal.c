#include <stdio.h>

#define FRAME_SIZE 3

int main()
{
    int reference_string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3}; // Example page reference string
    int page_faults = 0, frame[FRAME_SIZE] = {-1, -1, -1};   // Initialize frames to -1 (empty)
    int n = sizeof(reference_string) / sizeof(reference_string[0]);

    printf("Optimal Page Replacement Algorithm\n");

    for (int i = 0; i < n; i++)
    {
        int page = reference_string[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] == page)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            // Page fault occurs, replace the page using optimal strategy
            int farthest = -1, replace_index = -1;
            for (int j = 0; j < FRAME_SIZE; j++)
            {
                int next_use = -1;
                // Find when each page will be used next
                for (int k = i + 1; k < n; k++)
                {
                    if (reference_string[k] == frame[j])
                    {
                        next_use = k;
                        break;
                    }
                }
                if (next_use == -1)
                {
                    replace_index = j;
                    break;
                }
                else if (next_use > farthest)
                {
                    farthest = next_use;
                    replace_index = j;
                }
            }
            frame[replace_index] = page;
            page_faults++;
        }

        // Display the current state of frames
        printf("Reference: %d\tFrames: ", page);
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d\n", page_faults);
    return 0;
}
