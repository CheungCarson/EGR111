// Variables and the debug window.
// Set a breakpoint at line 9 and run.
// from https://en.wikibooks.org/wiki/C_Programming/Variables
#include <stdio.h>

int main(void)
{
    int some_number;
    int anumber, anothernumber, yetanothernumber;
    some_number = 3;
    int some_new_number = 4;
    some_number = some_new_number;
    anumber = anothernumber = yetanothernumber = 8;

    // Variable names - resource for naming restriction
    // Convention - variable are lower case with _ separator
    int my_age = 21;
    // You will see CamelCase used by some - CurrentEmployee

    // Variable size (bytes in memory) depends on hardware
    printf("int size is %d\n", sizeof(int));
    printf("char size is %d\n", sizeof(char));
    printf("float size is %d\n", sizeof(float));
    printf("double size is %d\n", sizeof(double));
    printf("\n");
    printf("Size of 99 is %d\n", sizeof(99));
    printf("Size of 4.0 is %d\n", sizeof(4.0));
    printf("Size of 4.0f is %d\n", sizeof(4.0f));

    // Other data types - used less frequently
    unsigned short int usi;  /* fully qualified -- unsigned short int */
    short si;                /* short int */
    unsigned long uli;       /* unsigned long int */

    // Don't use magic numbers (literals) when coding
    double cost = 178.99;
    double mi_tax = 178 * .06;      // but what if Gov. raises sales tax rate?
    
    // You can use a preprocessor Macro
    #define MI_SALES_TAX .06      // no = sign and no semicolon on preprocessor directive
    mi_tax = cost * MI_SALES_TAX;
    
    // use of const keyword is better practice
    const double MI_TAX_RATE = .06;
    mi_tax = cost * MI_TAX_RATE;

    return 0;
}