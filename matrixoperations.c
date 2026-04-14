#include <string.h>
#include <stdio.h>

// A * W + B = R
void multiplyAW(int A[], int W[][5], int B[], int R[], int colA, int colW) {
    for (int i = 0; i < colW; ++i) {
        R[i] = 0;

        for (int j = 0; j < colA; ++j) {
            R[i] += A[j] * W[j][i];
        }
        R[i] += B[i];
    }
}

// Prints R
void printResultingMatrix(int arr[], int end) {
    for (int i = 0; i < end; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// atoi from canvas
int asciitoint(const char *str) {
    int value = 0;

    while (*str == ' ') // for leading spaces
        str++;

    while (*str != '\0' && *str >= '0' && *str <= '9') {
        value = value * 10 + (*str - '0');
        str++;
    }

    return value;
}

int main(int arguments, char *files[]) {

    // Check if 3 files are passed // assignment1.exe A1.txt W1.txt B1.txt (four arguments)
    if (arguments != 4) {
        fprintf(stderr, "Error: Three files are expected as the input\nTerminating now, exit code 1.\n");
        return 1;
    }

    FILE *fileA, *fileB, *fileW;

    // second argument into fileA, third into file W, fourth into file B
    fileA = fopen(files[1], "r");
    fileW = fopen(files[2], "r");
    fileB = fopen(files[3], "r");

    // Error handlers
    if (fileA == NULL) {
        fprintf(stderr, "Error: %s is not found or cannot open\nTerminating now, exit code 1.\n", files[1]);

        return 1;
    }

    if (fileW == NULL) {
        fprintf(stderr, "Error: %s is not found or cannot open\nTerminating now, exit code 1.\n", files[2]);

        return 1;
    }

    if (fileB == NULL) {
        fprintf(stderr, "Error: %s is not found or cannot open\nTerminating now, exit code 1.\n", files[3]);

        return 1;
    }

    int rowA = 1, colA = 3; // A 1x3
    int rowW = 3, colW = 5; // W 3x5
    int rowB = 1, colB = 5; // B 1x5

    // Initialize arrays
    int A[rowA][colA];
    int W[rowW][colW];
    int B[rowB][colB];
    int R[rowA][colW];

    // temporary for reading
    char lineBuffer[100];

    rowA = 0;
    while (fgets(lineBuffer, sizeof(lineBuffer), fileA) != NULL) {
        // Used strtok from canvas reference and stackoverflow
        char *token = strtok(lineBuffer, " \n");
        int valuesRead = 0;

        while (token != NULL && valuesRead < colA) {
            int value = asciitoint(token);
            A[rowA][valuesRead++] = value;
            token = strtok(NULL, " \n");
        }

        // Fill rest of row with 0
        for (int i = valuesRead; i < colA; ++i) {
            A[rowA][i] = 0;
        }

        // Increment row count
        if (valuesRead > 0) {
            rowA++;
        }

        else {
            break; // Stop reading when empty line
        }
    }

    // Read matrix W, handling variable row count and filling missing values
    rowW = 0;
    while (fgets(lineBuffer, sizeof(lineBuffer), fileW) != NULL) {
        char *token = strtok(lineBuffer, " \n");
        int valuesRead = 0;

        while (token != NULL && valuesRead < colW) {
            int value = asciitoint(token);
            W[rowW][valuesRead++] = value;
            token = strtok(NULL, " \n");
        }

        for (int i = valuesRead; i < colW; ++i) {
            W[rowW][i] = 0;
        }

        if (valuesRead > 0) {
            rowW++;
        }

        else {
            break;
        }
    }

    rowB = 0;
    while (fgets(lineBuffer, sizeof(lineBuffer), fileB) != NULL) {
        char *token = strtok(lineBuffer, " \n");
        int valuesRead = 0;

        while (token != NULL && valuesRead < colB) {
            int value = asciitoint(token);
            B[rowB][valuesRead++] = value;
            token = strtok(NULL, " \n");
        }

        for (int i = valuesRead; i < colB; ++i) {
            B[rowB][i] = 0;
        }

        if (valuesRead > 0) {
            rowB++;
        }
        else {
            break;
        }
    }

    // Close input files
    fclose(fileA);
    fclose(fileW);
    fclose(fileB);

    // Perform matrix multiplication
    multiplyAW(A, W, B, R, colA, colW);

    // Print the resulting array R
    printf("Result of %s * %s + %s = ", files[1], files[2], files[3]);
    printResultingMatrix(R, 5);


    return 0;
}