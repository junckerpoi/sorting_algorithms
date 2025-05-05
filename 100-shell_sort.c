#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              with the Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate the initial gap using Knuth sequence */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        /* Print the array for each gap reduction */
        printf("Gap %lu: ", gap);
        print_array(array, size);

        /* Perform insertion sort for this gap size */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            
            /* Shift earlier gap-sorted elements up */
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }

        /* Reduce the gap according to Knuth sequence */
        gap = (gap - 1) / 3;
    }

    /* Print the final sorted array */
    printf("Gap 1: ");
    print_array(array, size);
}
