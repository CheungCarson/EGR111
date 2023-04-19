#include "carddeck.h"

#if !TESTING

int main()
{
    char deck[DECK_SIZE][CARD_SIZE];
    char dealer_hand[10][CARD_SIZE], player_hand[10][CARD_SIZE];
    int score, bet_amount, bank = 0;
    int d_wins = 0, p_wins = 0;

    char input = '\0';
    intro();
    while (input != 'N')
    {
        int dealer_card_count = 2, player_card_count = 2;
        bool players_done = false;
        bool player_stand = false;
        bool dealer_bust = false, player_bust = false;
        bool dealer_blackjack = false, player_blackjack = false;
        input = '\0'; // Resetting to NULL so end game loop runs again

        deck_factory(deck); // Setup
        shuffle(deck);
        deal_hand(deck, dealer_hand, START_HAND);
        deal_hand(deck, player_hand, START_HAND);

        print_table(dealer_hand, player_hand, dealer_card_count, player_card_count, players_done);

        player_blackjack = blackjack_check(player_hand, player_card_count);

        while (!player_blackjack && !player_bust && !player_stand) // Player's play
        {
            int hand_value = get_hand_value(player_hand, player_card_count);
            // print_table(dealer_hand, player_hand, dealer_card_count, player_card_count, player_done);
            // bet_amount = input_bets();
            if (hand_value == 21)
                player_blackjack = true;

            else if (hand_value > 21)
                player_bust = true;

            else
                player_stand = player_turn(deck, player_hand, &player_card_count);

            print_table(dealer_hand, player_hand, dealer_card_count, player_card_count, players_done);
        }

        while (get_hand_value(dealer_hand, dealer_card_count) < 17) // Dealer's play
        {
            deal_card(deck, dealer_hand[dealer_card_count], &dealer_card_count);
            print_table(dealer_hand, player_hand, dealer_card_count, player_card_count, players_done);
            getchar(); // pauses here until enter is pressed
        }
        // round_over(dealer_hand, player_hand, dealer_card_count, player_card_count, &d_wins, &p_wins);

        for (int i = 0; i < 2 /*number of players + 1*/; i++)
        {
            if (!player_bust && !dealer_bust)
            {
                win_check(dealer_hand, player_hand, dealer_card_count, player_card_count, &d_wins, &p_wins);
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