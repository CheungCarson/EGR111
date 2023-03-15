#include "carddeck.h"

#if !TESTING

int main()
{
    char deck[DECK_SIZE][CARD_SIZE];
    deck_factory(deck);
}

#endif