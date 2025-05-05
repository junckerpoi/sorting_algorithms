#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions array using Hoare scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array (for printing)
 * Return: Final partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare_recursive - Recursive helper for Hoare quick sort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of array (for printing)
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = hoare_partition(array, low, high, size);

        quick_sort_hoare_recursive(array, low, pi, size);
        quick_sort_hoare_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts array using Hoare partition scheme
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, 0, size - 1, size);
}
