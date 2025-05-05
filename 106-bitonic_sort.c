#include "sort.h"
#include <stdio.h>

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
 * bitonic_merge - Merges a bitonic sequence
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index
 * @count: Number of elements to merge
 * @dir: Sorting direction (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                swap(&array[i], &array[i + k]);
                print_array(array, size);
            }
        }

        bitonic_merge(array, size, low, k, dir);
        bitonic_merge(array, size, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive helper for bitonic sort
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index
 * @count: Number of elements to sort
 * @dir: Sorting direction (1 for UP, 0 for DOWN)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n",
               count, size, dir ? "UP" : "DOWN");
        print_array(array + low, count);

        /* Sort first half in ascending order */
        bitonic_sort_recursive(array, size, low, k, 1);

        /* Sort second half in descending order */
        bitonic_sort_recursive(array, size, low + k, k, 0);

        /* Merge the whole sequence */
        bitonic_merge(array, size, low, count, dir);

        printf("Result [%lu/%lu] (%s):\n",
               count, size, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array using bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 0, size, 1);
}
