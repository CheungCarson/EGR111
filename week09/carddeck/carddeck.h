#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define TESTING false

#define DECK_SIZE 52
#define START_HAND 2
#define CARD_SIZE 3 // rank + suit + null
const char SUITS[] = {'c', 'd', 'h', 's'};
const char RANKS[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

void intro();
void deck_factory(char deck[DECK_SIZE][CARD_SIZE]); // creates deck of DECK_SIZE
void shuffle(char deck[DECK_SIZE][CARD_SIZE]);
void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE]);                  // returns first non-blank card in deck
void deal_hand(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE], int hand_size); // returns hand of hand_size
int get_card_value(char card[CARD_SIZE]);
int get_hand_value(char hand[][CARD_SIZE], int hand_size);
bool is_ace(char card[CARD_SIZE]);
void print_table(char dealer_hand[10][CARD_SIZE], char player_hand[10][CARD_SIZE], int d_cards, int p_cards);
void print_card(char card[CARD_SIZE]);
void print_hand(char hand[][CARD_SIZE], int handSize);
void print_dealer_hand(char card[CARD_SIZE]);