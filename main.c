#include <stdio.h>

void swap(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void printf_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int steps_to_sort = 0;
void test_and_sort(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf_array(arr, arr_size);
            printf("Not sorted, continue...\n");
            steps_to_sort++;
            swap(arr, i, i + 1);
            test_and_sort(arr, arr_size);
        }
        else if (i == arr_size - 2)
        {
            printf_array(arr, arr_size);
            printf("Sorted! It took %d steps\n", steps_to_sort);
        }
    }
}

int main()
{
    int arr[] = {96, 106, 28, 6, 0, 3, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    test_and_sort(arr, arr_size);

    return (0);
}