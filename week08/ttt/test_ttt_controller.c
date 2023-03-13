#include "ttt_controller.h"
#if TESTING

#include "acutest.h"
void test_can_clear_board(void)
{
    // arrange
    char test_board[3][3] = {
        {' ', ' ', ' '},
        {' ', 'O', ' '},
        {' ', ' ', 'X'},
    };

    // act
    clear_board(test_board);
    // assert
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            TEST_CHECK(test_board[i][j] == OPEN);
}

void test_can_choose_players(void)
{
    // arrange
    char p1, p2;
    // act
    choose_players(&p1, &p2);
    // assert
    TEST_CHECK(p1 == PLAYER_O || p1 == PLAYER_X);
    TEST_CHECK(p2 == PLAYER_O || p2 == PLAYER_X);
    TEST_CHECK(p1 != p2);
}

void test_can_select_first_player()
{
    // arrange
    char player;
    // act
    player = select_first_player();
    // assert
    TEST_CHECK(player == PLAYER_O || player == PLAYER_X);
}

void test_can_get_move()
{
    // Im not really sure how to do this one
}

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    {"first test", test_can_clear_board},
    {"can choose player", test_can_choose_players},
    {"can select first player", test_can_select_first_player},
    {NULL, NULL}};

#endif