#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Original array
 * @left: Left subarray
 * @left_size: Size of left subarray
 * @right: Right subarray
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, size_t left_size,
           int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];

    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
    free(temp);
}

/**
 * merge_sort - Sorts an array using top-down merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid = size / 2;
    int *left = array;
    int *right = array + mid;
    size_t left_size = mid;
    size_t right_size = size - mid;

    if (array == NULL || size < 2)
        return;

    /* Sort left half (smaller or equal size) */
    merge_sort(left, left_size);
    /* Sort right half */
    merge_sort(right, right_size);
    /* Merge the sorted halves */
    merge(array, left, left_size, right, right_size);
}
