#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1;
    int num2;
    int num3;
    int sum;

    if (argc == 3 || argc == 4) { // checks if 2 or 3 integers passed
        // Convert from strings to int
        num1 = atoi(argv[1]); // First element
        num2 = atoi(argv[2]); // Second element

        if (argc == 4) { // for 3 int case
            num3 = atoi(argv[3]);
            sum = num1 + num2 + num3;
            printf("Sum of %d, %d, and %d is %d\n", num1, num2, num3, sum);
        }
        else { // for 2 int case
            sum = num1 + num2;
            printf("Sum of %d and %d is %d\n", num1, num2, sum);
        }
    } else {
        printf("Please enter 2 or 3 integer arguments.\n");
    }
    return 0;
}
