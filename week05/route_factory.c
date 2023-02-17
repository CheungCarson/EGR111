// ROUTE FACTORY
// Run this solution multiple times to investigate output
// Use debugger to single step. Practice Step Into, Step Over, and Step Out
// Add extensive comments documenting your understanding of the code. Every line?
// Keith E. Kelly
// 2/13/2023
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Field dimensions
#define H_SIZE 32
#define V_SIZE H_SIZE / 2
//Characters for drawing the field
const char CLOSED = '#';
const char OPEN = ' ';
const char START = 'O';
char field[V_SIZE][H_SIZE];//defining field

void make_field()//Fills the entire field with '#'
{
    for (int r = 0; r < V_SIZE; r++)//steps through all horizontal rows
        for (int c = 0; c < H_SIZE; c++)//fills the horizontal rows
            field[r][c] = CLOSED;
}

void display_field()//displays the field to the terminal
{
    system("clear");//clears the system terminal
    for (int r = 0; r < V_SIZE; r++)
    {
        for (int c = 0; c < H_SIZE; c++)
            printf("%c", field[r][c]);
        printf("\n");
    }
}

int get_next_index(int current)
{
    // 50% chance no move, %25 forward, 25% backward
    int random = rand();
    int delta = (random % 4 == 0 ? -1 : (random % 4 == 1) ? 1
                                                          : 0);
    return current + delta;
}

bool is_valid_space(int row, int col, char mark)
{
    bool return_val = false;
    if (row < 0)
        ;
    else if (row >= V_SIZE)
        ;
    else if (col < 0)
        ;
    else if (col >= H_SIZE)
        ;
    else if (field[row][col] != mark)
        ;
    else
        return_val = true;
    return return_val;
}

bool is_remote_space(int row, int col)
{
    int adjacent_closed_spaces = 0;
    if (is_valid_space(row + 1, col, CLOSED))
        adjacent_closed_spaces++;
    if (is_valid_space(row - 1, col, CLOSED))
        adjacent_closed_spaces++;
    if (is_valid_space(row, col + 1, CLOSED))
        adjacent_closed_spaces++;
    if (is_valid_space(row, col - 1, CLOSED))
        adjacent_closed_spaces++;

    return adjacent_closed_spaces >= 3;
}

int make_route(int row, int col, const int ROUTE_LENGTH)
{
    int try_count = ROUTE_LENGTH * 10;
    int next_row, next_col;
    int length = 0;
    int tries = 0;

    field[row][col] = START;
    while (length < ROUTE_LENGTH && tries < try_count)
    {
        next_row = get_next_index(row);
        if (next_row == row) // no vertical move so then horizontal
            next_col = get_next_index(col);
        else
            next_col = col;
        if (is_valid_space(next_row, next_col, CLOSED))
            if (is_remote_space(next_row, next_col))
            {
                row = next_row;
                col = next_col;
                field[row][col] = OPEN;
                length++;
                // display_field();
            }
        tries++;
    }
    return length;
}

void main()
{
    int PATH_LENGTH = 100;
    int length = 0;

    srand(time(0));
    while (length < PATH_LENGTH / 2)
    {
        make_field();
        length = make_route(V_SIZE / 2, H_SIZE / 2, PATH_LENGTH);
        // display_field();
    }
    display_field();
    printf("Path length = %d\n", length);
}