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
    //arrange
    char test_board[3][3] = {
        {' ', ' ', ' '},
        {' ', 'O', ' '},
        {' ', ' ', 'X'},
    };
    int test_move;
    //act
    test_move = get_move(test_board);
    //assert
    TEST_CHECK(test_move >= 0 && test_move <= 9);
}

void test_is_valid_move()
{
    // arrange
    char test_board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    int row = 1;
    int col = 1;
    bool pass = false;
    // act
    pass = is_valid_move(test_board, row, col);
    // assert
    TEST_CHECK(pass);
}

void test_is_on_board()
{
    // arrange
    int row = 1;
    int col = 1;
    bool pass = false;
    //act
    pass = is_on_board(row, col);
    //assert
    TEST_CHECK(pass);
}

void test_is_open_space()
{
    // arrange
    char test_board[3][3] = {
        {'O', 'X', 'O'},
        {'X', ' ', 'X'},
        {'O', 'X', 'X'},
    };
    int row = 1;
    int col = 1;
    bool open = false;
    //act
    open = is_open(test_board, row, col);
    //assert
    TEST_CHECK(open);
}

void test_row_win()
{
    // arrange
    char test_board[3][3] = {
        {' ', ' ', ' '},
        {'X', 'X', 'X'},
        {' ', ' ', ' '},
    };
    bool pass = false;
    char player = PLAYER_X;
    //act
    pass = is_row_win(test_board, player);
    //assert
    TEST_CHECK(pass);
}

void test_col_win()
{
    // arrange
    char test_board[3][3] = {
        {' ', 'X', ' '},
        {' ', 'X', ' '},
        {' ', 'X', ' '},
    };
    bool pass = false;
    char player = PLAYER_X;
    //act
    pass = is_col_win(test_board, player);
    //assert
    TEST_CHECK(pass);
}

void test_diag_win()
{
    // arrange
    char test_board[3][3] = {
        {'X', ' ', ' '},
        {' ', 'X', ' '},
        {' ', ' ', 'X'},
    };
    bool pass = false;
    char player = PLAYER_X;
    //act
    pass = is_diag_win(test_board, player);
    //assert
    TEST_CHECK(pass);
}

void test_for_cat()
{
     // arrange
    char test_board[3][3] = {
        {'X', 'X', 'O'},
        {'O', 'O', 'X'},
        {'X', 'O', 'X'},
    };
    bool pass = false;
    //act
    pass = check_for_cat(test_board);
    //assert
    TEST_CHECK(pass);
}

void test_next_player()
{
    //arrange
    char current_player = PLAYER_X;
    //act
    current_player = next_player(current_player);
    //assert
    TEST_CHECK(current_player == PLAYER_O);
}
// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    {"first test", test_can_clear_board},
    {"can choose player", test_can_choose_players},
    {"can select first player", test_can_select_first_player},
    {"can get move", test_can_get_move},
    {"can validate move", test_is_valid_move},
    {"can validate is on board", test_is_on_board},
    {"can validate open space", test_is_open_space},
    {"can test row win", test_row_win},
    {"can test col win", test_col_win},
    {"can test diag win", test_diag_win},
    {"can test for cat game", test_for_cat},
    {"check next player", test_next_player},
    {NULL, NULL}};

#endif