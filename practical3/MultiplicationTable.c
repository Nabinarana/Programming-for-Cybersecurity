#include <stdio.h>

#define MAX_SIZE 9

int main () {
    int userSize;

    printf("Enter table size (1-%d): ", MAX_SIZE);

    //check invalid integer input
    if (scanf("%d", &userSize) !=1){
        printf("Error: Invalid Input!\n");
        return 1;
    }

    // check range
    if (userSize < 1 || userSize > MAX_SIZE){
        printf("Error: Size must be between 1 and %d!\n", MAX_SIZE);
        return 1;
    }

    //print header
    printf("\nMultiplication Table (%dx%d):\n", userSize, userSize);

    for (int i = 1; i<= userSize; i ++){
       printf("%3d |", i);

       for (int j = 1; j <= userSize; j++){
        printf("%4d", i*j);
       }

       printf("\n");
    }

    return 0;
}