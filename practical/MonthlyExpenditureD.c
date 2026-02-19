/* Print monthly expenditure
Practical 2, Part 2 (a)
@author Nabina */

#include <stdio.h>

int main() {
    float foodExpenses, leisureExpenses, clothesExpenses, accomodationExpenses, travelExpenses;

    /* declaring variable for foodExpenses without assigning a value*/
    //instead of foodExpenses = 450.0;
    printf ("\n Enter food expenses: ");
    scanf("%f", &foodExpenses);

    /* declaring variable for leisureExpenses without assigning a value*/
    //instead of leisureExpenses = 120.0;
    printf("Enter leisure expenses: ");
    scanf("%f", &leisureExpenses);

    /* declaring variable for clothesExpenses without assigning a value*/
    //instead of clothesExpenses = 500.0;
    printf("Enter clothes expenses: ");
    scanf("%f", &clothesExpenses);

    /* declaring variable for accomodationExpenses without assigning a value*/
    //instead of accomodationExpenses = 500.0;
    printf("Enter accommodation expenses: ");
    scanf("%f", &accomodationExpenses);

    /* declaring variable for travelExpenses without assigning a value*/
    //instaed of travelExpenses = 60.0;
    printf("Enter travel expenses: ");
    scanf("%f", &travelExpenses);

     float totalSpent = foodExpenses + leisureExpenses + clothesExpenses + accomodationExpenses + travelExpenses;

    printf("The total expenditure of last month was £%.2f\n", totalSpent);
    return 0;
}
