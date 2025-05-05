#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * card_value - Gets the numerical value of a card
 * @value: String value of the card
 * Return: Numerical value (Ace=0, King=12)
 */
int card_value(const char *value)
{
    static const char *values[] = {
        "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
    };
    for (int i = 0; i < 13; i++)
        if (strcmp(value, values[i]) == 0)
            return i;
    return -1;
}

/**
 * compare_cards - Comparison function for qsort
 * @a: First card to compare
 * @b: Second card to compare
 * Return: Negative if a < b, positive if a > b, 0 if equal
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = *(const card_t **)a;
    const card_t *card_b = *(const card_t **)b;

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;
    return card_value(card_a->value) - card_value(card_b->value);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    card_t *cards[52];
    deck_node_t *node = *deck;
    int i = 0;

    /* Extract cards from deck into array */
    while (node)
    {
        cards[i++] = (card_t *)node->card;
        node = node->next;
    }

    /* Sort the array */
    qsort(cards, 52, sizeof(card_t *), compare_cards);

    /* Rebuild the deck in order */
    node = *deck;
    for (i = 0; i < 52; i++)
    {
        node->card = cards[i];
        node = node->next;
    }
}
