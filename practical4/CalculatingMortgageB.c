/* CalculateMortgageB.c
Practical 4, Part 1(b)
Nabina */

#include <stdio.h>

//Function declarations
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double saalry2);

int main(){

    //Declare variables
    double salary1, salary2, mortgage;

    //Read in two salaries, salry1, salary2
    printf("Enter two salaries sepaarted by a space: \n");
    scanf(" %lf %lf", &salary1, &salary2);

    //Calculate mortgage
    mortgage = largerSalary(salary1,salary2) * 3;
    mortgage = smallerSalary (salary1, salary2);

    //Display the mortgage
    printf("The maximum size of mortgage is: £ %.2lf \n", mortgage);

    return 0;
}

// Function stub for largerSalary(double, double)
double largerSalary(double salary1, double salary2){
    return 1; // placeholder
}

// Function stub flor smallerSalary(double, double)
double smallerSalary(double salary1, double salary2) {
    return 1;
}