// Assignment 01_tictactoe.c
// Use the printf statement to create three
// versions of a tic tac toe board. You have seen
// how to use the \n escape sequence to create a 
// new line. Use the web to research other escape 
// sequences in C to determine how to create a 
// tab. The board must be shown as below with a two
// tab stops between the left margin and the left 
// edge of the board.
//
//       O | X | O
//      -----------
//       O | X | X
//      -----------
//       X | O | X
//
//  Name: 
//  Date: 
//**********************************************
#include <stdio.h>

int main(void)
{
    // Board 1: Use 5 printf statements to create the
    // board. Each statement prints one row.
    printf("Board 1\n");
    printf("\t\tO | X | O\n");
    printf("\t\t---------\n");
    printf("\t\tO | X | X\n");
    printf("\t\t---------\n");
    printf("\t\tX | O | X\n\n");

    

    //**********************************************
    // Board 2: Use 5 printf statements from board 1 but 
    // use the %c placeholder followed by cell values.
    // See the example below printing the board id.
    printf("Board %c\n", '2');
    printf("\t\t%c | %c | %c\n", 'O','X','O');
    printf("\t\t---------\n");
    printf("\t\t%c | %c | %c\n", 'O','X','O');
    printf("\t\t---------\n");
    printf("\t\t%c | %c | %c\n\n", 'O','X','O');
    
    


    //**********************************************
    // Board 3: Use a single printf statement to create
    // the board. Placeholder is not required.
    printf("Board 3\n");
    printf("\t\tO | X | O\n\t\t---------\n\t\tO | X | X\n\t\t---------\n\t\tX | O | X\n");

    return 0;
}


