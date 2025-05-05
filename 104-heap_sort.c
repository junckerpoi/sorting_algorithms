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
 * sift_down - Performs sift-down operation on a heap
 * @array: Array to sort
 * @start: Start index of heap
 * @end: End index of heap
 * @size: Size of the array (for printing)
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child, swap_idx;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;

        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;

        if (swap_idx == root)
            return;

        swap(&array[root], &array[swap_idx]);
        print_array(array, size);
        root = swap_idx;
    }
}

/**
 * heapify - Builds a max heap from an array
 * @array: Array to heapify
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
    ssize_t start;

    for (start = (size - 2) / 2; start >= 0; start--)
        sift_down(array, start, size - 1, size);
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (end = size - 1; end > 0; end--)
    {
        swap(&array[0], &array[end]);
        print_array(array, size);
        sift_down(array, 0, end - 1, size);
    }
}
