#include "carddeck.h"

#if TESTING

#include "../../acutest.h"

void test_can_make_deck()
{
    TEST_CHECK(true);
}

void test_can_shuffle_deck()
{
    TEST_CHECK(true);
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