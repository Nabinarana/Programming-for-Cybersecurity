#include <stdio.h>

#define MAX_CUSTOMERS 10

// function to check maximum days in month
int maxdayInmonth(int month){
    if (month == 2) return 29;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    if (month >= 1 && month <= 12) return 31;
    return 0;
}

int main(){

    int n;
    int totalUnits = 0;

    // ask number of customers
    printf("Enter number of cutomers (1-10): ");
    if (scanf("%d", &n) !=1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (n<1 || n> MAX_CUSTOMERS){
        printf("Error: Customers must be between 1 and 10.\n");
        return 1;
    }

    //process each customer using for loop
    for (int i=1; i <=n; i++){

        int previous, current, day, month;
        int valid = 1;

        printf("\n--- Customer %d ---\n", i);
        printf("Enter previous metre, current metre, day and month:\n");

        //validate input format
        if (scanf("%d %d %d %d", &previous, &current, &day, &month) !=4){
            printf("Invalid input format\n");
            while (getchar() != '\n'); //claer buffer
            i--; //retry same customer
            continue;
        }

        printf("%d %d %d %d", &previous, &current, &day, &month);

        //meter validation
        if(previous <0 || previous> 9999){
            printf("Error: previous meter reading out of range\n");
            valid=0;
        }

        if(current <0 || current> 9999){
            printf("Error: current meter reading out of range\n");
            valid=0;
        }

        if(previous > current){
            printf("Error: previous reading is more than present reading\n");
            valid=0;
        }

        //electricity usage
        if(previous <= current) {
            int used = current - previous;
            if (used > 1000){
                printf("Error: electricity used is more than 1000 units\n");
                valid =0;
            }
        }

        // month and day validation
        if (month < 1 || month > 12) {
            printf("Error: month out of range\n");
            valid = 0;
        }
        else{
            int maxday = maxdayInmonth(month);
            if (day < 1 || day > maxday){
                printf("Error: Invalid day for the given month\n");
                valid = 0;
            }
        }

        // Add to total only if valid
        if (valid){
            int used = current - previous;
            printf("Units used: %d\n", used);
            totalUnits += used;
        }
    }

    //display summary
    printf("\n==== Summary =====\n");
    printf("Customers processed: %d\n", n);
    printf("Total electricity units (valid customers only): %d\n", totalUnits);

    return 0;

}