#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define TESTING false

#define DECK_SIZE 52
#define CARD_SIZE 3 // rank + suit + null
#define MAX_PLAYERS 5
#define MAX_CARDS 10
const char SUITS[] = {'c', 'd', 'h', 's'};
const char RANKS[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

void intro();
int input_bets();
bool player_turn(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE]);
void deck_factory(char deck[DECK_SIZE][CARD_SIZE]); // creates deck of DECK_SIZE
void shuffle(char deck[DECK_SIZE][CARD_SIZE]);
void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE]);   // deals a single card; //returns first non-blank card in deck
void deal_hand(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE]); // returns hand of hand_size
int get_card_value(char card[CARD_SIZE]);
int get_hand_value(char hand[][CARD_SIZE]);
void print_table(char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE], bool dealer_turn);
void print_hand(char hand[][CARD_SIZE], bool hide_card);
void win_check(char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE], int *d_wins, int *p_wins);
bool blackjack_check(char hand[10][CARD_SIZE]);
void bet_payouts(bool playerwin, bool dealerwin, bool blackjack, int bet_amount, int bank);
bool check_bust(char dealer_hand[MAX_CARDS][CARD_SIZE], bool dealer_turn, int *d_wins, int *p_wins /*, int d_cards*/);
// bool check_player_bust(char player_hand[10][CARD_SIZE], int p_cards);
int get_player_count();