#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    else
        *list = b;
    
    if (b->next)
        b->next->prev = a;
    
    a->next = b->next;
    b->prev = a->prev;
    b->next = a;
    a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        /* Forward pass */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
                current = current->prev; /* Adjust pointer after swap */
            }
        }
        
        if (!swapped)
            break;
            
        swapped = 0;
        /* Backward pass */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
                current = current->next; /* Adjust pointer after swap */
            }
        }
    }
}
