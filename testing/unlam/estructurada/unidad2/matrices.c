#include <stdio.h>
#include <stdbool.h>
#define N 10
#define COL 4
void identityMatrix (void)
{
    int row, col;
    int identity[N][N];

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (row == col) {
                identity[row][col] = 1;
            } else {
                identity[row][col] = 0;
            }
        }
    }

    printf("Identity matrix: ");
    printf("\n");

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", identity[i][j]);
        }

        printf("\n");
    }
}

void squareMatrixSum(int firstMatrix[][COL], int secondMatrix[][COL], int result[][COL], int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

void showMatrix(int matrix[][COL], int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%02d ", matrix[i][j]);
        }

        printf("\n");
    }
}

void loadMatrix(int matrix[][COL], int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Enter value (%d|%d): ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main(void)
{
    /* bool digit_seen[10] = {false}; */
    /* int digit; */
    /* long n; */

    int matrix1[4][COL];
    int matrix2[4][COL];

    printf("Loading values for the first matrix...\n");
    loadMatrix(matrix1, 4, 4);

    printf("Loading values for the second matrix...\n");
    loadMatrix(matrix2, 4, 4);

    int matrixSum[4][COL];

    squareMatrixSum(matrix1, matrix2, matrixSum, 4, 4);

    printf("Showing the sum of the two matrices:\n");
    showMatrix(matrixSum, 4, 4);

    /* printf("Enter a number: "); */
    /* scanf("%ld", &n); */

    /* while (n > 0) { */
    /*     digit = n % 10; */
    /*     if (digit_seen[digit]) */
    /*         break; */
    /*     digit_seen[digit] = true; */
    /*     n /= 10; */
    /* } */

    /* if (n > 0) */
    /*     printf("Repeated digit.\n"); */
    /* else */
    /*     printf("No repeated digit.\n"); */

    return 0;
}
