#include "carddeck.h"

void deck_factory(char deck[DECK_SIZE][CARD_SIZE])
{
    // For loops making card deck
    char suits[] = SUITS;
    char ranks[] = RANKS;
    int cards = 0;

    while (cards < DECK_SIZE)
    {
        for (int s = 0; s < 4; s++)
        {
            for (int r = 0; r < 13; r++)
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
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int r = rand() % (52);
        char temp_arr[2];
        temp_arr[0] = deck[r][0];
        temp_arr[1] = deck[r][1];

        deck[r][0] = deck[i][0];
        deck[r][1] = deck[i][1];

        deck[i][0] = temp_arr[0];
        deck[i][1] = temp_arr[1];
    }
}

void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE])
{
    for (int i = 0; i < DECK_SIZE; i++)
    {
        if (deck[i][0] != NULL && deck[i][1] != NULL)
        {
            card[0] = deck[i][0];
            card[1] = deck[i][1];
            break;
        }
    }
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