#include <stdio.h>

void swap(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void printf_array(int array[], int stack_length)
{
    for (int i = 0; i < stack_length; i++)
    {
        printf("%d, ", array[i]);
    }
}

int steps_to_sort = 0;
void test_and_sort(int arr[], int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf_array(arr, array_size);
            printf("Not sorted, continue...\n");
            printf("\n");
            steps_to_sort++;
            swap(arr, i, i + 1);
            test_and_sort(arr, array_size);

            break;
        }
        else if (i == array_size - 2)
        {
            printf_array(arr, array_size);
            printf("Sorted! It took %d steps\n", steps_to_sort);
            break;
        }
    }
}

int main()
{
    int stack[] = {96, 106, 28, 6, 0, 3, 5};
    int stack_length = sizeof(stack) / sizeof(stack[0]);
    test_and_sort(stack, stack_length);

    return (0);
}