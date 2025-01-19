#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main()
{

    int array[10] = {155, 166, 50, 74, 58, 69, 45, 64};
    int size = 8;
    int head = 46;
    int temp;

    array[size] = head;
    size = size + 1;

    printf("Before sorting in order\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }

    // sorting the array
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\nAfter sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}