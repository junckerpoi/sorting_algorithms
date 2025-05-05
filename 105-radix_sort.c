#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - Gets the maximum value in an array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - Performs counting sort on array based on digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current digit exponent (1, 10, 100, ...)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    /* Store count of occurrences */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count to actual position */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i != (size_t)-1; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print array after sorting by current digit */
    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array using LSD radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort_radix(array, size, exp);
}
