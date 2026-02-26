/* Electricity bill
Practical 2, part 2
Nabina */

#include <stdio.h>

int maxdayInmonth(int month) {
    if ( month == 2) return 29;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    if (month >= 1 && month <= 12) return 31;
    return 0;
}

int main(){
    // define variables for previous and current readings, day and month
    int previousMetre, currentMetre, day, month;


    printf("Enter previous metre, current metre, day and month:\n");

    // check correct input formats
    if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4){
        printf("Error: Invalid input format\n");
        return 1;
    }

    // print input values
    printf("%d %d %d %d\n", previousMetre, currentMetre, day, month);

    // meter reading validation
    if (previousMetre <0 || previousMetre >9999)
    printf("Error: previous meter reading out of range\n");

    if (currentMetre <0 || currentMetre > 9999)
    printf("Error: current meter reading out of range\n");

    if (previousMetre > currentMetre)
    printf("Error: previous reading is more than present reading\n");

    //electricity used
    if (previousMetre <= currentMetre){
        int used = currentMetre - previousMetre;

        if(used > 1000)
        printf("Error: electricity used is more than 1000 units\n");
    }

    //months validation
    if (month < 1 || month > 12){
        printf("Error: month out of range\n");
    }
    else{
        int maxday = maxdayInmonth(month);

        if (day < 1 || day > maxday)
        printf("Error: invalid day for the given month\n");
    }

    return 0;

}