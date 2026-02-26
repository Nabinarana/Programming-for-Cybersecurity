#include <stdio.h>

int main(){

    int number;
    int sum = 0;
    int count =0;

    printf("=== Sum Calculator ==\n");
    printf("Enter positive numbers (enter negative number to stop)\n");

    while(1){
        printf("Enter number: ");

        // check if input is integer
        if (scanf("%d", &number) !=1){
            printf("Invalid input! Please enter a number.\n");

        // clear wrong input from buffer
        while (getchar() != '\n');
        continue;
        }

        // stop if negative number
        if (number < 0)
        break;

        sum += number;
        count++;

        printf("Current sum: %d\n", sum);

    }

    printf("\nFinal sum: %d\n", sum);
    printf("Total numbers enetered: %d\n", count);

    return 0;
}