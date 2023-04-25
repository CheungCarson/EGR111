#include "carddeck.h"

#if !TESTING

int main()
{
    char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE]; //[players (0 is dealer)][card index][card characteristics]
    char deck[DECK_SIZE][CARD_SIZE];
    int score, bet_amount, bank = 0;
    int d_wins = 0, p_wins = 0;

    char input = '\0';
    intro();
    while (input != 'N')
    {
        bool players_done = false;
        bool player_stand = false;                               // going away
        bool dealer_bust = false, player_bust = false;           // going away
        bool dealer_blackjack = false, player_blackjack = false; // going away
        int blackjack_count = 0, bust_count = 0, stand_count = 0;
        input = '\0'; // Resetting to NULL so end game loop runs again

        deck_factory(deck); // Setup
        shuffle(deck);
        deal_hand(deck, player_hands[0]);
        deal_hand(deck, player_hands[1]);

        print_table(player_hands, players_done);

        player_blackjack = blackjack_check(player_hands[1]);

        for (int i = 1; i < MAX_PLAYERS; i++)
        {
            if (player_hands[i][0][0] != '\0')
            {
                while (!player_blackjack && !player_bust && !player_stand) // Player's play
                {
                    player_blackjack = false;
                    player_bust = false;
                    player_stand = false;
                    // print_table(dealer_hand, player_hand, dealer_card_count, player_card_count, player_done);
                    // bet_amount = input_bets();
                    if (get_hand_value(player_hands[i]) == 21)
                    {
                        player_blackjack = true;
                    }

                    else if (get_hand_value(player_hands[i]) > 21)
                    {
                        player_bust = true;
                    }

                    else
                    {
                        player_stand = player_turn(deck, player_hands[i]);
                    }

                    print_table(player_hands, players_done);
                }
            }
        }

        players_done = true;
        print_table(player_hands, players_done);

        while (get_hand_value(player_hands[0]) < 17 && !player_bust && !player_blackjack) // Dealer's play
        {
            for (int i = 0; i < MAX_CARDS; i++)
            {
                if (player_hands[0][i][0] == '\0')
                {
                    deal_card(deck, player_hands[0][i]);
                    print_table(player_hands, players_done);
                    getchar(); // pauses here until enter is pressed
                    break;
                }
            }
            if (get_hand_value(player_hands[0]) > 21)
            {
                dealer_bust = true;
            }
        }

        for (int i = 1; i < 2 /*number of players + 1*/; i++) // Checks players fo win
        {
            if (!player_bust && !dealer_bust)
            {
                win_check(player_hands, &d_wins, &p_wins);
            }
            else if (player_blackjack)
            {
                printf("BLACKJACK!\n");
                p_wins += 1;
                printf("Dealer Wins: %d\n", d_wins);
                printf("Player Wins: %d\n", p_wins);
            }
            else if (player_bust)
            {
                printf("Player Busted!\n");
                d_wins += 1;
                printf("Dealer Wins: %d\n", d_wins);
                printf("Player Wins: %d\n", p_wins);
            }
            else if (dealer_bust)
            {
                printf("Dlayer Busted!\n");
                p_wins += 1;
                printf("Dealer Wins: %d\n", d_wins);
                printf("Player Wins: %d\n", p_wins);
            }
        }

        while (input != 'Y' && input != 'N') // Ask if the player is done
        {
            printf("Would you like to play again? (Y/N)\n");
            input = toupper(getchar());
            if (input != 'Y' && input != 'N')
                printf("Invalid entry!\n");
            getchar();
        }
    }
    printf("Thanks for playing!"); // Bye
}

#endif

// all the setup
// check blackjack on all
// player turn(s)
// dealer turn
// check for busts
// check for blackjacks
// determine winner
// index wins
// print end of round screen

// if (dealer did not bust)
// for(each player)
// get score
// if did not bust
// print result

// set current player to player[i]
// while players done is false
// print table
// player[i] turn
//  all the checks
// i++
// if i is too big i = 1