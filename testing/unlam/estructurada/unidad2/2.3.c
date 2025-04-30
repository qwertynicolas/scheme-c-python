#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 8

void randomLoad(int matrix[][COLUMNS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int maximumValue(int matrix[][COLUMNS])
{
    int maximum = matrix[0][0];
    int i, j, counter = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (matrix[i][j] > maximum) {
                maximum = matrix[i][j];
                counter = 0;
            } else if (matrix[i][j] == maximum) {
                counter++;
            }
        }
    }

    if (counter > 0) {
        printf("Maximum value: %d. Repetitions: %d.\n", maximum, counter);
    } else if (counter == 0) {
        printf("Maximum value: %d.\n", maximum);
    }

    return maximum;
}

void repeatedPositions(int matrix[][COLUMNS], int maximum)
{
    int i, j;

    printf("Positions: ");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (matrix[i][j] == maximum) {
                printf("%d|%d ", i+1, j+1);
            }
        }
    }

    printf("\n");
}

int main(void)
{
    int matrix[5][8];
    srand((unsigned) time(NULL));

    randomLoad(matrix);

    int maximum;
    maximum = maximumValue(matrix);

    repeatedPositions(matrix, maximum);

    return 0;
}
