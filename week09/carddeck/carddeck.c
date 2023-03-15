#include "carddeck.h"

void deck_factory(char deck[DECK_SIZE][CARD_SIZE])
{
    // For loops making card deck
    char suits[] = SUITS;
    char ranks[] = RANKS;
    int cards = 0;

    while (cards <= DECK_SIZE)
    {
        for (int s = 0; s <= 4; s++)
        {
            for (int r = 0; r <= 13; r++)
            {
                deck[cards][0] = suits[s];
                deck[cards][1] = ranks[r];
                deck[cards][2] = '\0';
                cards++;
            }
        }
    }
}

void shuffle(char deck[DECK_SIZE][CARD_SIZE])
{
    // random num gen
    // switch first card w/ random card
    // Checks first two cards
}

void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE]) // returns first non-blank card in deck
{
}

void deal_hand(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE], int hand_size) // returns hand of hand_size
{
}

int get_card_value(char card[CARD_SIZE])
{
}

int get_hand_value(char hand[][CARD_SIZE], int hand_size)
{
}

bool is_ace(char card[CARD_SIZE])
{
}