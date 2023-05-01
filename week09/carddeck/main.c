#include "carddeck.h"

#if !TESTING

int main()
{
    char player_hands[MAX_PLAYERS][MAX_CARDS][CARD_SIZE]; //[players (0 is dealer)][card index][card characteristics]
    int player_money[MAX_PLAYERS - 1][2] = {//player_money[bank][bets]
        {20, 0,} ,
        {20, 0,} ,
        {20, 0,} ,
        {20, 0,} ,
    }; 
    char deck[DECK_SIZE][CARD_SIZE];
    int score, bet_amount, bank = 0;

    char input = '\0';
    intro();
    int player_count = get_player_count();
    while (input != 'N')
    {
        bool players_done = false;
        bool player_stand = false;                               // going away
        bool dealer_bust = false, player_bust = false;           // going away
        bool dealer_blackjack = false, player_blackjack = false; // going away
        bool player_won = false;
        bool game_over = false;
        int blackjack_count = 0, bust_count = 0, stand_count = 0;
        input = '\0'; // Resetting to NULL so end game loop runs again
        
        deck_factory(deck); // Setup
        shuffle(deck);

        for(int i = 0; i < MAX_PLAYERS; i++)// inits hands to NULL    Might not need in the end
        {
            for(int j = 0; j < MAX_CARDS; j++)
            {
                player_hands[i][j][0] = '\0';
                player_hands[i][j][0] = '\0';
                player_hands[i][j][0] = '\0';
            }
        }

        for(int i = 0; i < player_count; i++) //Deals Hands
            deal_hand(deck, player_hands[i]);

        print_table(player_hands, players_done);
        input_bets(player_money, player_count);

        for(int i = 1; i < player_count; i++)
        {
            while (!player_blackjack && !player_bust && !player_stand) // Player's play
            {
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
                    player_stand = player_turn(deck, player_hands[i], i);
                }

                print_table(player_hands, players_done);
            }
            player_blackjack = false; player_bust = false; player_stand = false;
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
        if(dealer_bust)
        {
            printf("Dealer Busted!\n");
        }

        for (int i = 1; i < player_count; i++) // Checks players for win
        {
            int score = get_hand_value(player_hands[i]);

            if (score > 21)
            {
                printf("Player %d Busted!\n", i);
                player_won = false;
            }
            else if(score == 21)
            {
                printf("Player %d BLACKJACK!\n", i);
                player_won = true;
            }
            else
            {
                if(dealer_bust)
                {
                    player_won = true;
                    printf("Player %d won!\n", i);
                }                   
                else
                    win_check(player_hands, i, &player_won);
            }

            bet_payouts(player_money, player_blackjack, player_count, player_won, i - 1);
        }

        for (int i = 0; i < player_count - 1; i++)
        {
            if (player_money[i][0] == 0)
            {
                printf("Player %d is all out of money!\n", i + 1);
                game_over = true;
                input = 'N';
                break;
            }
        }
        
        if (!game_over)
        {
            while (1) // Ask if the player is done
            {
                printf("\nWould you like to play again? (Y/N)\n");
                input = toupper(getchar());
                getchar();
                if (input == 'Y' || input == 'N')
                    break;
                printf("Invalid entry!\n");
            }
        }
        
    }
    printf("\nThanks for playing!"); // Bye
}

#endif