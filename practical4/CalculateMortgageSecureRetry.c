/* CalculateMortgageSecureRetry.c
Practical 4, Part 2 (a)
Secure mortgage calculation with retry + validation
Nabina */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

//Function declarations
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double salary2);
bool validateSalary(double salary);
bool readSalaries(double *salary1, double *salary2);
double calculateMortgage(double salary1, double salary2);

int main(){
    double salary1, salary2, mortgage;
    const int MAX_ATTEMPTS = 3;
    int attempts =0;
    bool inputValid = false;

    //Give user multiple attempts with security limit
    while (attempts < MAX_ATTEMPTS && !inputValid){

        printf("Enter two salaries sepaarted by a space:\n");

        if (!readSalaries(&salary1, &salary2)) {
            attempts++;
            printf("Error: Invalid input format.\n");
            printf("Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
            continue;
        }

        if(!validateSalary(salary1) || !validateSalary(salary2)){
            attempts++;
            printf("Error: Salaries must be between £0 and £1,000,000.\n");
            printf("Attempts remaining: %d\n", MAX_ATTEMPTS- attempts);
            continue;
        }
        inputValid=true;
    }

    //Check if max attempts exceeded
    if (attempts >= MAX_ATTEMPTS){
        printf("Maximum attempts exceeded. Program terminated.\n");
        return 1;
    }

    //calculate mortage
    mortgage = calculateMortgage(salary1, salary2);

    if(mortgage < 0){
        printf("Error: Calculation failed due to overflow.\n");
        return 1;
    }

    printf("The maximum size of mortgage is: £ %.2lf\n", mortgage);
    return 0;
}

bool readSalaries(double *salary1, double *salary2){
    //Defensive programming: check pointers
    if(salary1 == NULL || salary2 == NULL){
        return false;
    }

    // Must successfully read 2 doubles
    if (scanf("%lf %lf", salary1, salary2) !=2){

    //clear remaining invalid input from buffer
    while(getchar() !='\n' && !feof(stdin)){}
    return false;
    }
    return true;
}

bool validateSalary(double salary){
    const double MIN_SALARY = 0.0;
    const double MAX_SALARY = 1000000.0;

    if(salary < MIN_SALARY || salary > MAX_SALARY){
        return false;
    }
    return true;
}

double calculateMortgage(double salary1, double salary2){
    double larger = largerSalary(salary1, salary2);
    double smaller = smallerSalary(salary1, salary2);
    double mortgage = larger *3 + smaller;
    return mortgage;
}

double largerSalary(double salary1, double salary2){
    if(salary1 > salary2)
    return salary1;
    else
    return salary2;
}

double smallerSalary(double salary1, double salary2){
    if (salary1 > salary2)
    return salary2;
    else
    return salary1;
}