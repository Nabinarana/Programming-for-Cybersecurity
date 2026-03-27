/* SecureScoreAnalyser.c
Practical 7 - Part 2 (c)
Secure pointer - based score analyser
@Nabina Rana */

#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100

//Validate array pointer and size
bool validateArrayParams(int *arr, int size) {
    if (arr == NULL) {
        printf("Error: Array pointer is NULL\n");
        return false;
    }

    if (size <= 0 || size > MAX_STUDENTS) {
        printf("Error: Invalid size\n");
        return false;
    }
    return true;
}

//Caculate sum using template
bool calculateSum( int *ptr, int size, int *result) {

    //Step 1: validate result pointer
    if ( result == NULL) {
        return false;
    }

    //Step 2: Validate array parameters
    if (!validateArrayParams(ptr, size)) {
        return false;
    }

    //step 3: safe processing
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ptr[i];
    }

    //Step 4: set result
    *result = sum;
    return true;
}

//Find maximum using template
bool findMax(int *ptr, int size, int *result) {

    if (result == NULL) {
        return false;
    }

    if (!validateArrayParams(ptr, size)) {
    return false;
}

int max = ptr[0];

for (int i = 1; i < size; i++) {
    if (ptr[i] > max) {
        max = ptr[i];
    }
}

*result = max;
return true;

}

//Find minimum using template
bool findMin(int *ptr, int size, int *result) {

    if (result == NULL) {
        return false;
    }

    if (!validateArrayParams(ptr, size)) {
        return false;
    }

    int min = ptr[0];

    for (int i = 1; i < size; i++) {
        if (ptr[i] < min) {
            min = ptr[i];
        }
    }

    *result = min;
    return true;
}

//Calculate average (slightly difeerent because float)
bool calculateAverage(int *ptr, int size, float *avg) {

    if (avg == NULL) {
        return false;
    }

    if (!validateArrayParams(ptr, size)) {
        return false;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ptr[i];
    }

    *avg = (float)sum / size;
    return true;
}

int main () {

    int scores[MAX_STUDENTS];
    int n;

    printf("Enter number of students: ");
    if (scanf("%d", &n) !=1) {
        printf("Invalid inpujt\n");
        return 1;
    }

//Input scores with validation
for (int i = 0; i < n; i++) {

    printf("Enter score %d (0-100): ", i + 1);

    if (scanf("%d", &scores[i]) !=1 ) {
        printf("Invalid input. Try again.\n");
        i--;
        while (getchar() != '\n'); //clear buffer
        continue;
    }

    if (scores[i] < MIN_SCORE || scores[i] > MAX_SCORE) {
        printf("Score must be between 0 and 100\n");
        i--;
    }
}

int sum, max, min;
float avg;

if (calculateSum(scores, n, &sum)) {
    printf("Sum: %d\n", sum);
}

if (findMax(scores, n, &max)) {
    printf("Maximum: %d\n", max);
}

if (findMin(scores, n, &min)) {
    printf("Minimum: %d\n", min);
}

if (calculateAverage(scores, n, &avg)) {
    printf("Average: %.2f\n", avg);
}

return 0;

}