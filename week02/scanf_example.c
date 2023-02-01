// Scanf example code
// see https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output

#include <stdio.h>

int main(void)
{
    int a;
    char name[50];

    printf("Please input an integer value: ");
    scanf("%d", &a);        // &a is "address-of" a. You are passing a reference to the container.
    printf("You entered: %d\n", a);

    printf("Please input an your name: ");
    scanf("%s", name);      // No & here. name is already reference to the memory containing the string of chars.
    printf("You entered: %s\n", name);

    return 0;
}