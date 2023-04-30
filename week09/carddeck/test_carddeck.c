#include "carddeck.h"

#if TESTING

#include "../../acutest.h"

void test_can_make_deck()
{
    // arrange
    char deck[DECK_SIZE][CARD_SIZE];
    int c_count = 0, d_count = 0, h_count = 0, s_count = 0;
    bool pass = true;
    // act
    deck_factory(deck);

    for (int i = 0; i < 52; i++)
    {
        if (deck[i][1] == 'c')
            c_count++;
        if (deck[i][1] == 'd')
            d_count++;
        if (deck[i][1] == 'h')
            h_count++;
        if (deck[i][1] == 's')
            s_count++;
    }
    if (c_count != 13 || d_count != 13 || h_count != 13 || s_count != 13)
        pass = false;
    // assert
    TEST_CHECK(pass);
}

void test_can_shuffle_deck()
{
    // arrange
    char deck[DECK_SIZE][CARD_SIZE];
    bool pass = true;
    deck_factory(deck);
    // act
    shuffle(deck);

    if
    // assert
}

void test_can_deal_card()
{
    TEST_CHECK(true);
}

void test_can_deal_hand()
{
    TEST_CHECK(true);
}

void test_can_get_card_value()
{
    TEST_CHECK(true);
}

void test_can_get_hand_value()
{
    TEST_CHECK(true);
}

TEST_LIST = {
    {"can make deck", test_can_make_deck},
    {"can shuffle deck", test_can_shuffle_deck},
    {"can deal card", test_can_deal_card},
    {"can deal hand", test_can_deal_hand},
    {"can get card value", test_can_get_card_value},
    {"can get hand value", test_can_get_hand_value},
    {NULL, NULL}};
#endif
// arrange

// act

// assert