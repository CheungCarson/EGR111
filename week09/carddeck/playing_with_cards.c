#include "carddeck.h"

#if !TESTING

int main()
{
    char deck[DECK_SIZE][CARD_SIZE];
    deck_factory(deck);
    shuffle(deck);

    for (int i = 0; i < DECK_SIZE; i++)
    {
        printf("%c", deck[i][0]);
        printf("%c", deck[i][1]);
        printf("\n");
    }
}

#endif