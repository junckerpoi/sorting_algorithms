#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/*Comparison direction macros for bitonic sort*/
#define UP 0
#define DOWN 1

/*enum bool - Enumeration of boolean values*/
typedef enum bool
{
    false = 0,
    true
} bool;


typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/*Helper for swapping*/
void swap_ints(int *a, int *b);

/*Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Regular functions prototypes*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);



#endif
