#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 8;

void FCFS(int array[], int head)
{
    int seek_count = 0;
    for (int i = 0; i < n; i++)
    {
        seek_count = seek_count + abs(head - array[i]);

        head = array[i];
    }

    printf("Total number of seek operations: %d\n", seek_count);

    printf("Seek sequence is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int sequence[8] = {176, 78, 66, 25, 48, 149, 15, 99};
    int head = 50;

    FCFS(sequence, head);
    return 0;
}