#include "carddeck.h"

void intro()
{
    printf("\e[1;1H\e[2J"); // Clear Screen

    printf("      _____\n"); // print cards
    printf("     |A .  | _____\n");
    printf("     | /.\\ ||A ^  | _____\n");
    printf("     |(_._)|| / \\ ||A _  | _____\n");
    printf("     |  |  || \\ / || ( ) ||A_ _ |\n");
    printf("     |____V||  .  ||(_'_)||( v )|\n");
    printf("            |____V||  |  || \\ / |\n");
    printf("                   |____V||  .  |\n");
    printf("                          |____V|\n");

    printf(" _______   __                      __                                     __       \n"); // print title
    printf("|       \\ |  \\                    |  \\                                   |  \\      \n");
    printf("| $$$$$$$\\| $$  ______    _______ | $$   __       __   ______    _______ | $$   __ \n");
    printf("| $$__/ $$| $$ |      \\  /       \\| $$  /  \\     |  \\ |      \\  /       \\| $$  /  \\ \n");
    printf("| $$    $$| $$  \\$$$$$$\\|  $$$$$$$| $$_/  $$      \\$$  \\$$$$$$\\|  $$$$$$$| $$_/  $$\n");
    printf("| $$$$$$$\\| $$ /      $$| $$      | $$   $$      |  \\ /      $$| $$      | $$   $$ \n");
    printf("| $$__/ $$| $$|  $$$$$$$| $$_____ | $$$$$$\\      | $$|  $$$$$$$| $$_____ | $$$$$$\\ \n");
    printf("| $$    $$| $$ \\$$    $$ \\$$     \\| $$  \\$$\\     | $$ \\$$    $$ \\$$     \\| $$  \\$$\\\n");
    printf(" \\$$$$$$$  \\$$  \\$$$$$$$  \\$$$$$$$ \\$$   \\$$__   | $$  \\$$$$$$$  \\$$$$$$$ \\$$   \\$$\n");
    printf("                                           |  \\__/ $$\n");
    printf("                                            \\$$    $$\n");
    printf("                                             \\$$$$$$\n");

    printf("\nThe goal of the game is to get as close to 21 points without going over\n"); // instructions
    printf("Number cards are worth their face value and face cards are all worth 10 points\n");
    printf("Aces are worth 11 points unless that pushes you over into a bust, then they are 1 point\n"); // To-Do: correct and rewrite
    printf("The first player is the dealer and the dealer wins ties\n");
    printf("You are dealt 2 cards two start and will take turns drwing cards until both players have either busted or passed\n");

    printf("\nAre you ready to play?\n");
    getchar(); // pauses here until enter is pressed
}

void print_table(char dealer_hand[10][CARD_SIZE], char player_hand[10][CARD_SIZE], int d_cards, int p_cards)
{
    printf("\e[1;1H\e[2J"); // Clear Screen

    printf("Dealer's hand:\n");
    print_dealer_hand(dealer_hand[0]);
    printf("\nScore: %d\n", get_card_value(dealer_hand[0]));

    printf("\nPlayer's hand:\n");
    print_hand(player_hand, p_cards);
    printf("\nScore: %d\n", get_hand_value(player_hand, p_cards));
}

bool player_done(char hand[][CARD_SIZE], int card_count, bool *bust, bool *blackjack)
{
    int score = get_hand_value(hand, card_count);
    if (score == 21)
        *blackjack = true;
    if (score >= 21)
        *bust = true;
}

void player_turn()
{
}

void deck_factory(char deck[DECK_SIZE][CARD_SIZE]) // Creats deck
{
    int cards = 0;            // counts cards created
    while (cards < DECK_SIZE) // while there are less than 52 cards
    {
        for (int s = 0; s < (sizeof(SUITS) / sizeof(SUITS[0])); s++) // indexes through suits
        {
            for (int r = 0; r < (sizeof(RANKS) / sizeof(RANKS[0])); r++) // indexes through ranks
            {
                deck[cards][0] = RANKS[r];
                deck[cards][1] = SUITS[s];
                deck[cards][2] = '\0';
                cards++;
            }
        }
    }
}

void shuffle(char deck[DECK_SIZE][CARD_SIZE]) // shuffles deck
{
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int r = rand() % (52);
        char temp_arr[2];
        temp_arr[0] = deck[r][0]; // saves random card to temp_arr
        temp_arr[1] = deck[r][1];

        deck[r][0] = deck[i][0]; // moves first card to random card's spot
        deck[r][1] = deck[i][1];

        deck[i][0] = temp_arr[0]; // moves random card to first card's spot
        deck[i][1] = temp_arr[1];
    }
}

void print_hand(char hand[][CARD_SIZE], int handSize)
{

    for (int i = 0; i < handSize; i++)
        printf(" ___   ");
    printf("\n");

    for (int i = 0; i < handSize; i++)
    {
        if (hand[i][0] == 'T')
            printf("|10 |  ");
        else
            printf("|%c  |  ", hand[i][0]);
    }
    printf("\n");

    for (int i = 0; i < handSize; i++)
    {
        switch (hand[i][1])
        {
        case 'd':
            printf("| ♦ |  ");
            break;
        case 'h':
            printf("| ♥ |  ");
            break;
        case 's':
            printf("| ♠ |  ");
            break;
        case 'c':
            printf("| ♣ |  ");
            break;
        default:
            break;
        }
    }
    printf("\n");

    for (int i = 0; i < handSize; i++)
    {
        if (hand[i][0] == 'T')
            printf("|_10|  ");
        else
            printf("|__%c|  ", hand[i][0]);
    }
    printf("\n");
}

void print_card(char card[CARD_SIZE])
{
    char r = card[0];

    printf(" ___\n");
    if (r == 'T')
        printf("|10  |\n");
    else
        printf("|%c  |\n", card[0]);
    switch (card[1])
    {
    case 'd':
        printf("| ♦ |\n");
        break;
    case 'h':
        printf("| ♥ |\n");
        break;
    case 's':
        printf("| ♠ |\n");
        break;
    case 'c':
        printf("| ♣ |\n");
        break;
    default:
        break;
    }
    if (r == 'T')
        printf("|_10|\n");
    else
        printf("|__%c|\n", card[0]);
}

void print_dealer_hand(char card[CARD_SIZE])
{
    char r = card[0];

    printf(" ___    ___\n");
    if (r == 'T')
        printf("|10 |  |?  |\n");
    else
        printf("|%c  |  |?  |\n", card[0]);
    switch (card[1])
    {
    case 'd':
        printf("| ♦ |  ");
        break;
    case 'h':
        printf("| ♥ |  ");
        break;
    case 's':
        printf("| ♠ |  ");
        break;
    case 'c':
        printf("| ♣ |  ");
        break;
    default:
        break;
    }
    printf("| ? |\n");
    if (r == 'T')
        printf("|_10|  |__?|\n");
    else
        printf("|__%c|  |__?|\n", card[0]);
}

void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE]) // deals a single card
{
    for (int i = 0; i < DECK_SIZE; i++) // checks through deck until first non-blank card
    {
        if (deck[i][0] != NULL && deck[i][1] != NULL) // if the card isnt NULL
        {
            card[0] = deck[i][0];
            card[1] = deck[i][1];
            card[2] = deck[i][2];

            deck[i][0] = '\0'; // removes card from deck
            deck[i][1] = '\0';
            break;
        }
    }
}

void deal_hand(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE], int hand_size) // deals a hand of cards
{
    for (int i = 0; i < 10; i++) // inits hand to NULL
    {
        hand[i][0] = '\0';
        hand[i][1] = '\0';
        hand[i][2] = '\0';
    }

    int card_count = 0; // counts cards dealt

    for (int i = 0; i < DECK_SIZE; i++) // deals non-blank cards until it has dealt hand_size cards
    {
        if (deck[i][0] != NULL && deck[i][1] != NULL) // if the card isnt NULL
        {
            hand[card_count][0] = deck[i][0];
            hand[card_count][1] = deck[i][1];
            hand[card_count][2] = deck[i][2];

            deck[i][0] = '\0'; // removes card from deck
            deck[i][1] = '\0';
            card_count++;

            if (card_count == hand_size) // ends when enough cards have been dealt
                break;
        }
    }
}

int get_card_value(char card[CARD_SIZE]) // finds value of single card
{
    if (card[0] >= 50 && card[0] <= 57) // if number card
        return card[0] - '0';           // returns int value of the char
    else
    {
        switch (card[0]) // returns face card value
        {
        case 'K':
        case 'Q':
        case 'J':
        case 'T':
            return 10;
        case 'A':
            return 11;
        default:
            return 0;
        }
    }
}

int get_hand_value(char hand[][CARD_SIZE], int hand_size) // finds value of hand
{
    int ace_counter = 0, score = 0;
    for (int i = 0; i < hand_size; i++) // for every card in the hand
    {
        score += get_card_value(&hand[i][0]); // score the card
        if (hand[i][0] == 'A')
            ace_counter++; // adds if ace
    }
    while (ace_counter >= 1 && score > 21) // if bust and one of the cards is an ace
    {
        score -= 10;
        ace_counter--;
    }
    return score;
}

bool is_ace(char card[CARD_SIZE])
{
}

void copy_card(char *d_card, const char *s_card)
{
    *(d_card) = *(s_card);
    *(d_card + 1) = *(s_card + 1);
    *(d_card + 2) = '\0';
}

void swap_cards(char *card1, char *card2)
{
    char temp_card[CARD_SIZE];
    copy_card(temp_card, card1);
    copy_card(card1, card2);
    copy_card(card2, temp_card);
}