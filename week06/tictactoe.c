// Tic Tac Toe project
// EGR111
// Carson Cheung
// 2/22/2023
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define OPEN ' '

char player1, player2;
char board[3][3] = {
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN},
};

void show_directions()
{
    printf("/n");
}

void draw_board()
{

    for (int r = 2; r >= 0; r--)
    {
        for (int c = 0; c <= 2; c++)
        {
            printf(" %c ", board[r][c]);
            (c < 2) ? printf(" | ") : printf("\n");
        }
        (r > 0) ? printf("----------------\n") : printf("\n");
    }
}

void choose_player()
{
    player1 = PLAYER_X;
    player2 = PLAYER_O;
}

char select_first_player()
{
    return player1;
}

void play(char current_player)
{
    // TODO - get row and colum from user
    // TODO - validate row and column values (0,1,2)
    // TODO - verfiy empty
    // TODO - place current_player in cell
}

void main()
{
    draw_board();
    // bool game_over = false;
    // bool has_winner, is_cat;

    // show_directions();
    // draw_board();
    // choose_player();
    // char player = select_first_player();

    // while(!has_winner && !is_cat)
    // {
    //     play(player);
    //     draw_board();
    //     has_winner = check_for_end();
    //     is_cat = check_for_cat();

    // }
    // if(has_winner)
    // {
    //     printf("%c is the winner!", player);
    // }
    // else
    // {
    //     printf("Cats game!");
    // }
}