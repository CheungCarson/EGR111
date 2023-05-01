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
    printf("You are dealt 2 cards to start and can draw more(hit) or can pass(stand)\n");
    printf("Once you are done, the dealer will draw cards until it is over 17 points. Dealer wins ties\n");

    printf("\nAre you ready to play?\n");
    getchar(); // pauses here until enter is pressed
}

void print_table(char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE], bool dealer_turn)
{
    printf("\e[1;1H\e[2J"); // Clear Screen

    printf("Dealer's hand:\n");

    print_hand(player_hands[0], !dealer_turn); //Print dealer hand
    if (dealer_turn) // If the dealers card is still hidden, it will only score the first card
        printf("\nScore: %d\n", get_hand_value(player_hands[0] /*d_cards*/));
    else
        printf("\nScore: %d\n", get_card_value(player_hands[0][0]));

    for (int i = 1; i <= MAX_PLAYERS; i++) //Print player hands
    {
        if (player_hands[i][0][0] == '\0')
        {
            break;
        }
        else
        {
            printf("\nPlayer %d hand:\n", i); // Prints players cards
            print_hand(player_hands[i], false);
            printf("\nScore: %d\n", get_hand_value(player_hands[i]));
        }
    }
}

bool player_turn(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE], int player_index) // Gets hit or stand input from player and take the respective action
{
    char input;
    while (1) // Gets input and validates
    {
        printf("\nPlayer %d's turn:\n", player_index);
        printf("Hit(H) or Stand(S)?");
        input = toupper(getchar());
        getchar();
        if (input == 'H' || input == 'S')
            break;
        printf("Invalid entry!\n\n");
    }

    if (input == 'H') // either hits or stands
    {
        for (int i = 0; i < MAX_CARDS; i++) // finds first empty card slot
        {
            if (hand[i][0] == '\0')
            {
                deal_card(deck, hand[i]); // Adds card to hand
                return false;
            }
        }
    }
    return true; // If returns true then it brings the game to an end
}

void deck_factory(char deck[DECK_SIZE][CARD_SIZE]) // Creates deck
{
    int cards_made = 0;            // counts cards created
    while (cards_made < DECK_SIZE) // while there are less than 52 cards
    {
        for (int s = 0; s < (sizeof(SUITS) / sizeof(SUITS[0])); s++) // indexes through suits
        {
            for (int r = 0; r < (sizeof(RANKS) / sizeof(RANKS[0])); r++) // indexes through ranks
            {
                deck[cards_made][0] = RANKS[r];
                deck[cards_made][1] = SUITS[s];
                deck[cards_made][2] = '\0';
                cards_made++;
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

void print_hand(char hand[][CARD_SIZE], bool hide_card) // Prints full hand of cards
{
    for (int i = 0; i < MAX_CARDS; i++) // Prints top row for every card
    {
        if (hand[i][0] == '\0') // breaks if there is no card
        {
            break;
        }
        printf(" ___   ");
    }
    printf("\n");

    for (int i = 0; i < MAX_CARDS; i++) // Prints second row for every card
    {
        if (hand[i][0] == '\0') // breaks if there is no card
        {
            break;
        }
        if (hide_card && i == 1) // For if it is the dealers hand and the player isn't done
            printf("|?  |  ");

        else if (hand[i][0] == 'T') // replaces 'T' with 10
            printf("|10 |  ");

        else
            printf("|%c  |  ", hand[i][0]);
    }
    printf("\n");

    for (int i = 0; i < MAX_CARDS; i++) // Prints middle row
    {
        if (hand[i][0] == '\0') // breaks if there is no card
        {
            break;
        }
        if (hide_card && i == 1) // For if it is the dealers hand and the player isn't done
            printf("| ? |  ");

        else
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

    for (int i = 0; i < MAX_CARDS; i++) // Prints bottom row for all cards
    {
        if (hand[i][0] == '\0') // breaks if there is no card
        {
            break;
        }
        if (hide_card && i == 1) // For if it is the dealers hand and the player isn't done
            printf("|__?|  ");

        else if (hand[i][0] == 'T') // replaces 'T' with 10
            printf("|_10|  ");

        else
            printf("|__%c|  ", hand[i][0]);
    }
    printf("\n");
}

void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE] /*, int *cards*/) // deals a single card
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

            // *cards += 1; // For some reason *cards++; doesn't work
            break;
        }
    }
}

void deal_hand(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE]) // deals a hand of cards
{
    for (int i = 0; i < 10; i++) 
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

            if (card_count == 2) // ends when enough cards have been dealt
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

int get_hand_value(char hand[][CARD_SIZE]) // finds value of hand
{
    int ace_counter = 0, score = 0;
    for (int i = 0; i < MAX_CARDS; i++) // for every card in the hand
    {
        if (hand[i][0] == '\0')
        {
            break;
        }
        else
        {
            score += get_card_value(&hand[i][0]); // score the card
            if (hand[i][0] == 'A')
                ace_counter++; // adds if ace
        }
    }
    while (ace_counter >= 1 && score > 21) // if bust and one of the cards is an ace
    {
        score -= 10; // jank but works
        ace_counter--;
    }
    return score;
}

bool blackjack_check(char hand[10][CARD_SIZE] /*, int hand_size*/)
{
    for (int i = 0; i < MAX_CARDS; i++)
    {
        if (hand[i][0] == '\0')
        {
            break;
        }
        else
        {
            if (get_hand_value(hand) == 21)
            {
                return true;
            }
        }
    }
    return false;
}

void win_check(char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE], int player_index, bool *player_won)
{
    int dealer_hand_value = get_hand_value(player_hands[0]);
    int player_hand_value = get_hand_value(player_hands[player_index]);

    if (dealer_hand_value > player_hand_value)
    {
        printf("Dealer beats player %d! %d > %d\n", player_index, dealer_hand_value, player_hand_value);
        *player_won = false;
    }
    else if (dealer_hand_value < player_hand_value) // checks to see if player has higher score than dealer
    {
        printf("Player %d wins! %d > %d\n", player_index, player_hand_value, dealer_hand_value);
        *player_won = true;
    }
    else if (dealer_hand_value == player_hand_value)
    {
        printf("Dealer beats player %d! tie %d = %d\n", player_index, dealer_hand_value, player_hand_value);
        *player_won = false;

    }
}

int input_bets(int player_money[MAX_PLAYERS - 1][2], int player_count)
// might be able to be a void function depending on how we implement multiplayer.
//This will be called at the beginner after the intro and before print table.
{
    int bet_amount, bet_range;
    for (int i = 0; i < player_count - 1; i++)
    {
        bet_range = player_money[i][0];
        printf("Player %d, How much would you like to bet? (Your betting cap is $%d) $", i + 1, player_money[i][0]);
        scanf("%d", &bet_amount);
        while (bet_amount > bet_range)
        {
            printf("You can't bet that much. Try again. $");
            scanf("%d", &bet_amount);
        }
        player_money[i][1] = bet_amount;
    }
    getchar();
    return bet_amount;
}

void bet_payouts(int player_money[MAX_PLAYERS - 1][2], bool blackjack, int player_count, bool player_won, int i) // needs to know if player won or lost. If lost then check for blackjack
{
    if (player_won == false) //players loses
    {
         player_money[i][0] -= player_money[i][1]; //Subtracts bet amount from bank
    }
    else if (player_won == true) //players win
    {
        if (blackjack == true) //players win by blackjack
        {
            player_money[i][0] += (player_money[i][1] * 1.5); //If blackjack then players get 1.5 their bet amount
        }
        else //Not won by blackjack
        {
            player_money[i][0] += player_money[i][1]; //Adds bet amount to bank
        }
    }

    printf("Player %d's Bank: $%d\n", i + 1, player_money[i][0]);
    printf("--------------------\n");
}

int get_player_count()
{
    int player_count;
    while (1)
    {
        printf("How many players?(1-4)\n");
        scanf("%d", &player_count);
        if (player_count > 0 || player_count < 5)
            break;   
        printf("Invalid Input\n\n");
    }
    getchar();
    return player_count + 1;
}