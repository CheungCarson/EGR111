// Checker Moves
// Create the required logic to list moves

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char BLACK = 'b';
const char RED = 'r';
const char EMPTY = ' ';

char space_home = BLACK;
char space_up1_left1 = EMPTY;
char space_up2_left2 = BLACK;
char space_up1_right1 = RED;
char space_up2_right2 = EMPTY;

void display_board()
{
    printf("---------------------\n");
    printf("| %c |:::|   |:::| %c |\n", space_up2_left2, space_up2_right2);
    printf("---------------------\n");
    printf("|:::| %c |:::| %c |:::|\n", space_up1_left1, space_up1_right1);
    printf("---------------------\n");
    printf("|   |:::|[%c]|:::|   |\n", space_home);
    printf("---------------------\n\n");
}

void place_checkers()
{
#define RANDOM_PLAYER (picker = rand() % 2) ? BLACK : RED
#define RANDOM_CHECKER (picker = rand() % 3) ? (picker % 3 == 1 ? BLACK : RED) : EMPTY
    int picker;

    srand(time(0));
    space_home = RANDOM_PLAYER;
    space_up1_left1 = RANDOM_CHECKER;
    space_up2_left2 = RANDOM_CHECKER;
    space_up1_right1 = RANDOM_CHECKER;
    space_up2_right2 = RANDOM_CHECKER;
}

void main()
{
    printf("Checker Moves - move solution demonstrating conditional logic.\n");
    place_checkers();
    display_board();
    printf("\nPOSSIBLE MOVES\n");
    if ((space_up2_left2 == EMPTY) && (space_up1_left1 != space_home) && (space_up1_left1 != EMPTY))
    {
        printf("Jump left\n");
    }
    if ((space_up2_right2 == EMPTY) && (space_up1_right1 != space_home) && (space_up1_right1 != EMPTY))
    {
        printf("Jump right\n");
    }
    if ((space_up2_left2 == EMPTY || space_up2_left2 == space_home) && (space_up1_left1 == EMPTY))
    {
        printf("Good move left\n");
    }
    if ((space_up2_right2 == EMPTY || space_up2_right2 == space_home) && (space_up1_right1 == EMPTY))
    {
        printf("Good move right\n");
    }
    if (space_up2_left2 != space_home && space_up2_left2 != EMPTY)
    {
        printf("Bad move left\n");
    }
    if (space_up2_right2 != space_home && space_up2_right2 != EMPTY)
    {
        printf("Bad move right\n");
    }

    printf("\n");
}