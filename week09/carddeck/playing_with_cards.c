#include "carddeck.h"

#if !TESTING

int main()
{
    char card[3];
    char hand[7][CARD_SIZE];
    char deck[DECK_SIZE][CARD_SIZE];
    deck_factory(deck);
    shuffle(deck);
    deal_card(deck, card);

    for (int i = 0; i < DECK_SIZE; i++)
    {
        printf("%c", deck[i][0]);
        printf("%c", deck[i][1]);
        printf("\n");
    }
    printf("your card is: %c%c", card[0], card[1]);
}

#endif