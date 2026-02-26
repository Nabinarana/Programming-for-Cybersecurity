#include <stdio.h>

#define MAX_ITERATIONS 100
int main(){

    int userInput;
    int iterations =0;

    printf("Guess the number (between 1 and 10): ");

    while (iterations < MAX_ITERATIONS) {

        //check valid integer input
        if (scanf("%d", &userInput) != 1) {
            printf("Invalid input! Try again: ");

            while (getchar() != '\n'); // clear buffer
            iterations++;
            continue;
        }

        //correct guess
        if (userInput == 7) {
            printf("Correct! You guessed it in %d attempts.\n", iterations +1);
            break;
        }

        //wrong guess
        printf("Wrong! Try again: ");
        iterations++;
    }

    //if user reaches max attempts
    if (iterations >= MAX_ITERATIONS) {
        printf("Maximum attempts reached. Game over!\n");
    }

    return 0;
}