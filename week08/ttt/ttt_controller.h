#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define OPEN ' '

#define TESTING true

void clear_board(char b[3][3]);
void show_directions();
void draw_board(char b[3][3]);
void choose_players(char *p1_ptr, char *p2_ptr);
char select_first_player();
int get_move(char b[3][3]);
bool is_valid_move(char b[3][3], int row, int col);
bool is_on_board(int row, int col);
bool is_open(char board[3][3], int row, int col);
void mark_move(char b[3][3], char p, int move);
bool check_for_win(char b[3][3], char p);
bool is_row_win(char b[3][3], char p);
bool is_col_win(char b[3][3], char p);
bool is_diag_win(char b[3][3], char p);
bool check_for_cat(char b[3][3]);
char next_player(char p);