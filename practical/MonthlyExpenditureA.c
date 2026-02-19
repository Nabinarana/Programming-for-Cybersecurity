/* Print monthly expenditure
Practical 2, Part 2 (a)
@author Nabina */

#include <stdio.h>

int main() {
    float foodExpenses = 300.0; //variable for food expenses
    float leisureExpenses = 100.0; //assign 100.0 to leisureExpenses
    float clothesExpenses = 50.0; //variable for clothes expenses

    float totalSpent = foodExpenses + leisureExpenses + clothesExpenses;

    printf("The total expenditure this month was £%.2f\n\n", totalSpent);
    return 0;
}
