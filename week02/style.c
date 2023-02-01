 /* EGR111
    Introduction to C coding style
    See https://en.wikibooks.org/wiki/C_Programming/Structure_and_style
*/

// **************************************
// Hello world example from earlier coding introduction
//  #include <stdio.h>
  
//  int main(void) {
//  	printf("Hello, World!\n");
//  	return 0;
//  }

// **************************************
// Here is is again. Compiler ignores extra white space and line returns
// but can you read it?
// #include <stdio.h>
// int main(void) {printf("Hello, World!\n");return 0;}

// **************************************
// How about this? Does it run? What is the function?
// #include <stdio.h>
// int main(void) { int revenue = 80; int cost = 50; int roi; roi = (100 * (revenue - cost)) / cost; if (roi >= 0) { printf ("%d\n", roi); } return 0; }

// **************************************
// Don't write code like above. Coding conventions require line breaks
// #include <stdio.h>
// int main(void) {
// int revenue = 80;
// int cost = 50;
// int roi;
// roi = (100 * (revenue - cost)) / cost;
// if (roi >= 0) {
// printf ("%d\n", roi);
// }
// return 0;
// }

// **************************************
// Next blank lines (white space) should be used to separate components.
// #include <stdio.h>

// int main(void) {

// int revenue = 80;
// int cost = 50;

// int roi;

// roi = (100 * (revenue - cost)) / cost;

// if (roi >= 0) {
// printf ("%d\n", roi);
// }

// return 0;
// }

// **************************************
// Add readability for block structures using indentation
// #include <stdio.h>

// int main(void) {

//     int revenue = 80;
//     int cost = 50;

//     int roi;

//     roi = (100 * (revenue - cost)) / cost;

//     if (roi >= 0) {
//         printf ("%d\n", roi);
//     }

//     return 0;
// }

// **************************************
// kek prefers to keep brackets aligned.
#include <stdio.h>

int main(void) 
{

    int revenue = 80;
    int cost = 50;

    int roi;

    roi = (100 * (revenue - cost)) / cost;

    if (roi >= 0) 
    {
        printf ("%d\n", roi);
    }

    return 0;
}