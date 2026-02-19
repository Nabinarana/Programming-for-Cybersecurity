/* Print monthly expenditure
Practical 2, Part 2 (a)
@author Nabina */

#include <stdio.h>

int main() {
    float foodExpenses = 450.0; //variable for food expenses
    float leisureExpenses = 120.0; //assign 120.0 to leisure expenses
    float clothesExpenses = 500.0; //variable for clothes expenses

    float totalSpent = foodExpenses + leisureExpenses + clothesExpenses;

    printf("The total expenditure this month was £%.2f\n", totalSpent);
    return 0;
}
