// Tic Tac Toe controller
// Keith E. Kelly 3/8/2023
#include "ttt_controller.h"

void clear_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = OPEN;
}

void draw_board(char board[3][3])
{
// no state change. This is not testable.
#define HOR_LINE "\t-----------\n"

    printf("\e[1;1H\e[2J");
    printf("\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf(HOR_LINE);
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf(HOR_LINE);
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\n");
}

void show_directions()
{
    printf("This is a tic tac toe game.\n\n");
}

void choose_players(char *p1_ptr, char *p2_ptr)
{
    while (*p1_ptr != PLAYER_X && *p1_ptr != PLAYER_O)
    {
        printf("Player 1, would you like to be X or O? ");
        scanf("%c", p1_ptr);
        while (getchar() != '\n')
            ;
        *p1_ptr = toupper(*p1_ptr);
        printf("\n");
    }
    *p2_ptr = next_player(*p1_ptr);
}

char select_first_player()
{
    return (rand() % 2 ? PLAYER_O : PLAYER_X);
}

int get_move(char board[3][3])
{
    int row, col;

    do
    {
        printf("Enter move row followed by column.\n");
        printf("Valid values are 1 -3. Example: 1 3\n");
        printf("Move: ");
        scanf("%d %d", &row, &col);
        row--; // adjust to zero based index
        col--; // adjust to zero based index
    } while (!is_valid_move(board, row, col));

    return (3 * row) + col; // array index 0 - 9
}

bool is_valid_move(char board[3][3], int row, int col)
{
    return is_on_board(row, col) && is_open(board, row, col);
}

bool is_on_board(int row, int col)
{
    bool valid = true;
    if (row < 0 || row > 2)
    {
        printf("Invalid row value.\n\n");
        valid = false;
    }
    else if (col < 0 || col > 2)
    {
        printf("Invalid col value.\n\n");
        valid = false;
    }
    return valid;
}

bool is_open(char board[3][3], int row, int col)
{
    bool valid = true;
    if (board[row][col] != OPEN)
    {
        printf("That space is taken.\n");
        valid = false;
    }
    return valid;
}

void mark_move(char board[3][3], char player, int move)
{
    char *brd_ptr = &board[0][0];
    *(brd_ptr + move) = player;
}

bool check_for_win(char board[3][3], char player)
{
    return is_row_win(board, player) || is_col_win(board, player) || is_diag_win(board, player);
}

bool is_row_win(char board[3][3], char player)
{
    bool return_val = false;
    for (int r = 0; r <= 2; r++)
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return_val = true;
            break;
        }
    return return_val;
}

bool is_col_win(char board[3][3], char player)
{
    bool return_val = false;
    for (int c = 0; c <= 2; c++)
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
        {
            return_val = true;
            break;
        }
    return return_val;
}

bool is_diag_win(char board[3][3], char player)
{
    bool return_val = false;
    if (board[1][1] == player)
        if (board[0][0] == player && board[2][2] == player)
            return_val = true;
        else if (board[0][2] == player && board[2][0] == player)
            return_val = true;
    return return_val;
}

bool check_for_cat(char board[3][3])
{
    bool is_cat = true;
    char *brd_ptr = &board[0][0];
    for (int i = 0; i < 9; i++)
        if (*(brd_ptr + i) == OPEN)
        {
            is_cat = false;
            break;
        }
    return is_cat;
}

char next_player(char current_player)
{
    return (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}