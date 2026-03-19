/* StudentScoreSort.c
Practical 6, Part 3 (b)
Secure sorting with bounds checking
@Nabina Rana */

#include <stdio.h>
#include <stdbool.h>

#define NUM_STUDENTS 5
#define MAX_STUDENTS 100

//Function declarations
bool validateArrayParams(int scores[], int size);
bool swapElements(int scores[], int size, int index1, int index2);
bool sortScoresAscending(int scores[], int size);
void displayScores(int scores[], int size);

int main(){
    int scores [NUM_STUDENTS];

    //INPUT SCORES
    printf("Enter %d student scores:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Score %d ", i + 1);
        scanf("%d", &scores[i]);
    }

    //SORT SCORES
    printf("\nSorting scores.....\n");
    if (sortScoresAscending(scores, NUM_STUDENTS)) {
        printf("Scores sorted successfully.\n");
        displayScores(scores, NUM_STUDENTS);
    } else {
        printf("Error: Failed to sort scores.\n");
        return 1;
    }

    return 0;

}

//validate array parameters (defensive programming)
bool validateArrayParams(int scores[], int size) {
    if (scores == NULL){
        printf("Error: NULL array pointer.\n");
        return false;
    }

    if (size <= 0 || size > MAX_STUDENTS) {
        printf("Error: Invalid array size.\n");
        return false;
    }
    return true;
}

//Secure Swap function
bool swapElements(int scores[], int size, int index1, int index2){
    //Validate array parameters
    if (!validateArrayParams(scores, size)) {
        return false;
    }

    //validate both indices are within bounds
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >=size) {
        printf("Error: Swap indices out of bounds.\n");
        return false;
    }

    //Perform swap
    int temp = scores[index1];
    scores[index1] = scores[index2];
    scores[index2] = temp;

    return true;
}

//Secure bubble sort
bool sortScoresAscending(int scores[], int size) {
    //Validate array parameters
    if (!validateArrayParams(scores, size)) {
        return false;
    }

    // Bubble sort with secure bounds checking
    for (int i = 0; i < size - 1; i++) {
        // Bounds check for outer loop
        if (i >= size) {
            printf("Error: Outer loop index out of bounds.\n");
            return false;
        }

        for (int j = 0; j < size - i - 1; j++) {
            //Bounds check for inner loop
            if (j >= size || j + 1 >= size) {
                printf("Error: Inner loop index out of bounds.\n");
                return false;
            }

            //Compare and swap if needed
            if (scores[j] > scores[j + 1]) {
                if (!swapElements(scores, size, j, j + 1)) {
                    return false;
                    }
            }
        }
    }

    return true;
}

//Secure display function
void displayScores(int scores[], int size) {
    if (!validateArrayParams(scores, size)) {
        return;
    }

    printf("\nSortedScores:\n");

    for (int i = 0; i < size; i++) {
        printf("Student %d: %d\n", i + 1, scores[i]);
    }
}



