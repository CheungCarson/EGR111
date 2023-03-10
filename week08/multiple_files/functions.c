
#include "functions.h"

void function1()
{
    printf("Function 1\n");
}

void function2()
{
    printf("Function 2\n");
}

int add_two_nums(int a, int b)
{
    int z = a + b;
    // int z = a + b + 1; // make this fail
    return z;
}