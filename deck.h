#ifndef DECK_H_
#define DECK_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * enum kind_e - The Enumeration of card suits.
 * @SPADE: The ♠️Spades♠️ suit.
 * @HEART: The ♥️Hearts♥️ suit.
 * @CLUB: The ♣️Clubs♣️ suit.
 * @DIAMOND: The ♦️Diamonds♦️ suit.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card.
 * @value: Value of the card.
 *         From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card.
 * @card: Pointer to the card of the node.
 * @prev: Pointer to the previous node of the list.
 * @next: Pointer to the next node of the list.
 *
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H_ */
