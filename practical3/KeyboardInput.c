#include <stdio.h>

int main(){
    //three variables for holding three values of input
    char firstWord[20]; //a word or string up to 20 characters meaning Buffer size is 20
    char secondWord[20]; //a word or string up to 20 characters meaning Buffer size is 20

    int num;
    //prompt user to enter three input values
    printf("Enter two words and an integer from keyboard:\n");

    if (scanf("%19s %19s %d", firstWord, secondWord, &num) !=3) {
        printf("Error: Invalid input format\n");
        return 1;

    }

    //display two words and an integer
    printf("%s %s \n%d \n", firstWord, secondWord, num);

    return 0;
}