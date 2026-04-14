#include <stdio.h>

void multiplyMatrices(int A[], int W[][5], int B[], int result[], int colA, int colW) {
    for (int j = 0; j < colW; ++j) {
        result[j] = 0;
        for (int k = 0; k < colA; ++k) {
            result[j] += A[k] * W[k][j];
        }
        result[j] += B[j];
    }
}

void printMatrix(int matrix[], int size) {
    for (int j = 0; j < size; ++j) {
        printf("%d ", matrix[j]);
    }
    printf("\n");
}

int main() {
    // Given matrices
    int A[] = {10, 30, 40};
    int W[][5] = {
            {1, 3, 4, 5, 1},
            {2, 4, 5, 0, 0},
            {1, 1, 5, 0, 0}
    };
    int B[] = {1, 1, 1, 1, 1};
    int result[5]; // Assuming colW is 5

    // Perform calculations
    multiplyMatrices(A, W, B, result, 3, 5);

    // Print the resulting array
    printf("Result = ");
    printMatrix(result, 5);

    return 0;
}