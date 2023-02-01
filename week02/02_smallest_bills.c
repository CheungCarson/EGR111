
#include <stdio.h>

int main(void){
    
    int total;
    int remainder;
    int NumberOfTwenties;
    int NumberOfTens;
    int NumberOfFives;
    int NumberOfOnes;

    printf("Please enter money amount: ");
    scanf("%d", &total);

    NumberOfTwenties = total / 20;
    remainder = total - (NumberOfTwenties * 20);
    total = remainder;

    if(remainder > 0){
        NumberOfTens = total / 10;
        remainder = total - (NumberOfTens * 10);
        total = remainder;
    }
    else{
        NumberOfTens = 0;
    }
    
    if(remainder > 0){
        NumberOfFives = total / 5;
        remainder = total - (NumberOfFives * 5);
        total = remainder;
    }
    else{
        NumberOfFives = 0;
    }

    if(remainder > 0 ){
        NumberOfOnes = remainder;
    }
    else{
        NumberOfOnes = 0;
    }

    printf("Number of Twenties: %d\n", NumberOfTwenties);
    printf("Number of Tens: %d\n", NumberOfTens);
    printf("Number of Fives: %d\n", NumberOfFives);
    printf("Number of Ones: %d\n", NumberOfOnes);
    return 0;
}    


