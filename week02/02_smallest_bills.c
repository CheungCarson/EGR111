
#include <stdio.h>

int main(void)
{

    int total;
    int remainder;
    int NumberOfTwenties;
    int NumberOfTens;
    int NumberOfFives;
    int NumberOfOnes;

    printf("Please enter money amount: ");
    scanf("%d", &total);

    NumberOfTwenties = total / 20;
    remainder %= 20;

    NumberOfTens = remainder / 10;
    remainder %= 10;

    NumberOfFives = remainder / 5;
    remainder %= 5;

    NumberOfOnes = remainder;

    printf("Number of Twenties: %d\n", NumberOfTwenties);
    printf("Number of Tens: %d\n", NumberOfTens);
    printf("Number of Fives: %d\n", NumberOfFives);
    printf("Number of Ones: %d\n", NumberOfOnes);
    return 0;
}
