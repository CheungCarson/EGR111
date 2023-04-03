#include "carddeck.h"

#if !TESTING

int main()
{
    bool dealer_win = false, player_win = false;
    int dealer_cards = 2, player_cards = 2;
    char deck[DECK_SIZE][CARD_SIZE];
    char dealer_hand[10][CARD_SIZE], player_hand[10][CARD_SIZE];
    int score;
    bool done = false, round_done = false;
    // two players need to be created
    // card counters for both players
    // intro
    // while loop that runs until players are done
    // deal hands
    // while loop that runs until one hits 21 or both bust or both pass
    // print hands
    // non dealer turn
    // dealer turn
    // checks for bust
    // Do you want to play again?
    // goodbye

    intro();

    deck_factory(deck);
    shuffle(deck);
    deal_hand(deck, dealer_hand, START_HAND);
    deal_hand(deck, player_hand, START_HAND);
    print_table(dealer_hand, player_hand, dealer_cards, player_cards);
    // printf("🂡");
    // while(!done)
    // {
    //     deck_factory(deck);
    //     deal_hand(deck, dealer_hand, START_HAND);
    //     deal_hand(deck, player_hand, START_HAND);

    //     while (!round_done)
    //     {
    //         print_table(dealer_hand, player_hand, dealer_cards, player_cards);
    //     }

    // }
    // intro();
    // deck_factory(deck);
    // shuffle(deck);

    // deal_card(deck, card);

    // deal_hand(deck, hand, START_HAND);

    // score = get_hand_value(hand, 10);

    // for(int i = 0; i < DECK_SIZE; i++)
    // {
    //     printf("%c", deck[i][0]);
    //     printf("%c", deck[i][1]);
    //     printf("\n");
    // }

    // printf("Your card is: %c%c\n", card[0], card[1]);
    // printf("Your hand contains: %c%c %c%c\n", hand[0][0], hand[0][1], hand[1][0], hand[1][1]);
    // printf("Your hand is worth %d\n", score);

    // two players need to be created
    // card counters for both players
    // intro
    // while loop that runs until players are done
    // while loop that runs until one hits 21 or both bust or both pass
    // deal hands
    // print hands
    // non dealer turn
    // dealer turn
    // checks for bust
    // Do you want to play again?
    // goodbye
}

#endif