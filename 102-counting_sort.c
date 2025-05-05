#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, i, j;
    int *count = NULL, *output = NULL;
    size_t k;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (k = 0; k < size; k++)
    {
        if (array[k] > max)
            max = array[k];
    }

    /* Allocate memory for count and output arrays */
    count = malloc(sizeof(int) * (max + 1));
    output = malloc(sizeof(int) * size);
    if (count == NULL || output == NULL)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Store count of each element */
    for (k = 0; k < size; k++)
        count[array[k]]++;

    /* Print the counting array */
    for (i = 0; i <= max; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", count[i]);
    }
    printf("\n");

    /* Modify count array to store actual positions */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (j = size - 1; j >= 0; j--)
    {
        output[count[array[j]] - 1] = array[j];
        count[array[j]]--;
    }

    /* Copy the sorted elements back to original array */
    for (k = 0; k < size; k++)
        array[k] = output[k];

    /* Free allocated memory */
    free(count);
    free(output);
}
