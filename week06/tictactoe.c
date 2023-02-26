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

char current_player, player1, player2;
char board[3][3] = {
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN},
};
int turn = 1;

void show_game()
{
    printf("  TIC TAC TOE\n\n");
}

void draw_board()
{
    printf("\e[1;1H\e[2J"); // clears terminal, this is the only thing that would work for me. The other methods for clearing the terminal all bugged out.
    int row_num = 3;
    printf("  1    2    3\n");
    for (int r = 2; r >= 0; r--) // Prints out the rows of the board
    {
        for (int c = 0; c <= 2; c++) // Prints out the columns of the board
        {
            printf(" %c ", board[r][c]);
            (c < 2) ? printf(" | ") : printf("  %d\n", row_num--);
        }
        (r > 0) ? printf("---------------\n") : printf("\n");
    }
}

void choose_player() // Alternates between player turns (Always starts with PLAYER_X)
{
    player1 = PLAYER_X;
    player2 = PLAYER_O;

    turn++;
    if (turn % 2 == 0)
        current_player = player1;
    else
        current_player = player2;
}

void play()
{
    int r = 0;
    int c = 0;
    while (r <= 3 && c <= 3)
    {
    start:
        while (r != 1 && r != 2 && r != 3) // Gets row from user and validates it
        {
            printf("Enter row: ");
            scanf("%d", &r);
            if (r != 1 && r != 2 && r != 3)
            {
                printf("Invalid row\n");
            }
        }

        while (c != 1 && c != 2 && c != 3) // Gets column from user and validates it
        {
            printf("Enter column: ");
            scanf("%d", &c);
            if (c != 1 && c != 2 && c != 3)
            {
                printf("Invalid column\n");
            }
        }

        if (board[r - 1][c - 1] != OPEN) // validates open space
        {
            printf("That space is taken! Try again.\n");
            r = 0, c = 0;
            goto start;
        }
        else
        {
            board[r - 1][c - 1] = current_player;
        }
        return;
    }
}

void check_game_over(char player, bool *game_over, bool *player_win) // Checks to see if the game is over
{
    for (int r = 0; r <= 3; r++) // Checks for wins in the rows
    {
        if (board[r][2] == player && board[r][1] == player && board[r][0] == player)
        {
            *game_over = true;
            *player_win = true;
        }
    }

    for (int c = 0; c <= 3; c++) // Checks for wins in the columns
    {
        if (board[2][c] == player && board[1][c] == player && board[0][c] == player)
        {
            *game_over = true;
            *player_win = true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) // Checks for one of the two diagonal wins
    {
        *game_over = true;
        *player_win = true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) // Checks for one of the two diagonal wins
    {
        *game_over = true;
        *player_win = true;
    }

    if (turn > 9) // Checks for cats game
    {
        *game_over = true;
    }
}

void main()
{
    bool game_over = false;
    bool player_win = false;

    while (game_over == false)
    {
        draw_board();
        show_game();
        choose_player();
        play();
        check_game_over(current_player, &game_over, &player_win);
    }

    draw_board();
    show_game();
    (player_win == true) ? printf("\nCongratulations player %c you won!!\n", current_player) : printf("\nIt's a Cats game!\n");
}