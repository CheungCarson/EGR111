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

void print_table(char dealer_hand[10][CARD_SIZE], char player_hand[10][CARD_SIZE], int d_cards, int p_cards, bool dealer_turn)
{
    printf("\e[1;1H\e[2J"); // Clear Screen

    printf("Dealer's hand:\n");

    print_hand(dealer_hand, d_cards, !dealer_turn); // Prints full hand

    if (dealer_turn) // If the dealers card is still hidden, it will only score the first card
        printf("\nScore: %d\n", get_hand_value(dealer_hand, d_cards));
    else
        printf("\nScore: %d\n", get_hand_value(dealer_hand, 1));

    printf("\nPlayer's hand:\n"); // Prints players cards
    print_hand(player_hand, p_cards, false);
    printf("\nScore: %d\n", get_hand_value(player_hand, p_cards));
}

bool player_turn(char deck[DECK_SIZE][CARD_SIZE], char hand[][CARD_SIZE], int *card_cnt) // Gets hit or stand input from player and take the respective action
{
    char input = '\0';

    while (input != 'H' && input != 'S') // Gets input and validates
    {
        printf("Hit(H) or Stand(S)?");
        input = toupper(getchar());
        if (input != 'H' && input != 'S')
            printf("Invalid entry!\n");
        printf("\n");
        getchar();
    }

    if (input == 'H') // either hits or stands
    {
        deal_card(deck, hand[*card_cnt], card_cnt); // Adds card to hand
        return false;
    }
    else
        return true; // If returns true then it brings the game to an end
}

void deck_factory(char deck[DECK_SIZE][CARD_SIZE]) // Creates deck
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

void print_hand(char hand[][CARD_SIZE], int handSize, bool hide_card) // Prints full hand of cards
{
    for (int i = 0; i < handSize; i++) // Prints top row for every card
        printf(" ___   ");
    printf("\n");

    for (int i = 0; i < handSize; i++) // Prints second row for every card
    {
        if (hide_card && i == 1) // For if it is the dealers hand and the player isn't done
            printf("|?  |  ");

        else if (hand[i][0] == 'T') // replaces 'T' with 10
            printf("|10 |  ");

        else
            printf("|%c  |  ", hand[i][0]);
    }
    printf("\n");

    for (int i = 0; i < handSize; i++) // Prints middle row
    {
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

    for (int i = 0; i < handSize; i++) // Prints bottom row for all cards
    {
        if (hide_card && i == 1) // For if it is the dealers hand and the player isn't done
            printf("|__?|  ");

        else if (hand[i][0] == 'T') // replaces 'T' with 10
            printf("|_10|  ");

        else
            printf("|__%c|  ", hand[i][0]);
    }
    printf("\n");
}

void deal_card(char deck[DECK_SIZE][CARD_SIZE], char card[CARD_SIZE], int *cards) // deals a single card
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

            *cards += 1; // For some reason *cards++; doesn't work
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
        score -= 10; // jank but works
        ace_counter--;
    }
    return score;
}

bool blackjack_check(char hand[10][CARD_SIZE], int hand_size)
{
    if (get_hand_value(hand, hand_size) == 21)
    {
        return true;
    }
    return false;
}

bool check_player_bust(char player_hand[10][CARD_SIZE], int p_cards) // Runs after the end of each turn to check for busts
{
    if (get_hand_value(player_hand, p_cards) > 21) // if player busts
    {
        printf("Player busted\n");
        return true;
    }
}

bool check_dealer_bust(char dealer_hand[10][CARD_SIZE], int d_cards)
{
    if (get_hand_value(dealer_hand, d_cards) > 21) // if dealer busts
    {
        printf("Dealer busted\n");
        return true;
    }
}

void round_over(char dealer_hand[10][CARD_SIZE], char player_hand[10][CARD_SIZE], int d_cards, int p_cards, int *d_wins, int *p_wins) // declares winner and indexes the scores
{
    bool dealerbust = false, playerbust = false, dealerwin = false, playerwin = false; // blackjack = false;
    int dealer_hand_value = get_hand_value(dealer_hand, d_cards);
    int player_hand_value = get_hand_value(player_hand, p_cards);

    if (dealer_hand_value > 21) // if dealer busts
    {
        printf("Dealer busted\n");
        dealerbust = true;
    }
    else
        printf("Dealer score: %d\n", dealer_hand_value); // Print score

    if (get_hand_value(player_hand, p_cards) > 21) // if player busts
    {
        printf("Player busted\n");
        playerbust = true;
    }
    else
        printf("Player score: %d\n", player_hand_value); // Print score

    if (playerbust && !dealerbust)                                  // If the dealer busted
        *d_wins += 1;                                               //++ doesn't seem to work on pointers ¯\_(ツ)_/¯
    else if (dealer_hand_value >= player_hand_value && !dealerbust) // if dealer wins
    {
        printf("\nDealer wins %d > %d\n", dealer_hand_value, player_hand_value);
        *d_wins += 1;
        dealerwin = true;
    }

    if (!playerbust && dealerbust) // If the player busted
        *p_wins += 1;
    else if (dealer_hand_value < player_hand_value && !playerbust) // if player wins
    {
        printf("\nPlayer wins %d > %d\n", player_hand_value, dealer_hand_value);
        *p_wins += 1;
        playerwin = true;
    }

    printf("\nDealer's wins: %d\nPlayer's wins: %d\n", *d_wins, *p_wins); // prints current scores
    // blackjack = blackjack_check(player_hand[10][CARD_SIZE], p_cards);
    // bet_payouts(playerwin, dealerwin, blackjack);
    getchar(); // Pauses until player presses enter
}

void win_check(char dealer_hand[10][CARD_SIZE], char player_hand[10][CARD_SIZE], int d_cards, int p_cards, int *d_wins, int *p_wins)
{
    int dealer_hand_value = get_hand_value(dealer_hand, p_cards);
    int player_hand_value = get_hand_value(player_hand, d_cards);

    if (dealer_hand_value > player_hand_value)
    {
        printf("\nDealer wins %d > %d\n", dealer_hand_value, player_hand_value);
        *d_wins += 1;
    }
    else if (dealer_hand_value < player_hand_value)
    {
        printf("\nPlayer wins %d > %d\n", player_hand_value, dealer_hand_value);
        printf("Player score: %d\n", player_hand_value);
        *p_wins += 1;
    }
}

int input_bets()
{
    int bet_amount, bet_range = 50;
    printf("Your betting range is $0-$50");
    scanf("%d", &bet_amount);
    while (bet_amount > bet_range)
    {
        printf("You can't bet that much. Try again");
        scanf("%d", &bet_amount);
    }
    return bet_amount;
}

/* void bet_payouts(bool playerwin, bool dealerwin, bool blackjack, int bet_amount, int bank) //needs to know if player won or lost. If lost then check for blackjack
{
    if (playerwin == false)
    {
        bank -= bet_amount;
    }
    else if ()
    {

    }

    printf("\nDealer's wins: %d\nPlayer's wins: %d\n", *d_wins, *p_wins); //prints current scores
    getchar();
}
    //if (lost)
    //{
        //Player loses their bet money
    //}
    //else if (win)
    //{
        //if (blackjack == true)
        //{
            //bet = bet + (bet * 1.5)
        //}
        //else
        //{
            //bet = bet * 2
        //}
    //}
}*/
