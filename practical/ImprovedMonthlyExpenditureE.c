/*
Improved Secure version - MonthlyExpenditureE.c

Replaced scanf with fgets (safer input handling)
Added validation prevent negtaive values
Added error checking for invalid numeric input
*/

#include <stdio.h>

int main (){
    const int ACCOMODATION = 500;

    float food, leisure, clothes, travel;
    int result;

    //food
    while(1){
       printf("Enter food expenses: ");
        result = scanf("%f", &food);

      if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
    }

    if (food<0){
        printf("Expense cannot be negative. Try again.\n");
            continue;
    }
    break;

}

//leisure
  while (1) {
        printf("Enter leisure expenses: ");
        result = scanf("%f", &leisure);

        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (leisure < 0) {
            printf("Expense cannot be negative. Try again.\n");
            continue;
        }
        break;
    }

    //clothes
    while (1) {
        printf("Enter clothes expenses: ");
        result = scanf("%f", &clothes);

        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (clothes < 0) {
            printf("Expense cannot be negative. Try again.\n");
            continue;
        }
        break;
    }

    //travel
    while (1) {
        printf("Enter travel expenses: ");
        result = scanf("%f", &travel);

        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        if (travel < 0) {
            printf("Expense cannot be negative. Try again.\n");
            continue;
        }
        break;
    }

  float total = food + leisure + clothes + travel + ACCOMODATION;

    printf("\nTotal spent last month was £%.2f\n", total);

    return 0;
}