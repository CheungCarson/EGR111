#include "ttt_controller.h"

#if !TESTING

int main()
{
    char board[3][3];
    char player1, player2, player;
    int move;
    bool has_winner = false, is_cat = false;

    clear_board(board);
    draw_board(board);
    show_directions();
    choose_players(&player1, &player2);
    player = select_first_player();
    while (!has_winner && !is_cat)
    {
        printf("It's player %c's move.\n", player);
        move = get_move(board);
        mark_move(board, player, move);
        draw_board(board);
        if (check_for_win(board, player))
            has_winner = true;
        else if (check_for_cat(board))
            is_cat = true;
        else
            player = next_player(player);
    }
    if (has_winner)
        printf("%c is the winner!\n\n", player);
    else
        printf("Cat game!\n\n");

    return 0;
}

#endif