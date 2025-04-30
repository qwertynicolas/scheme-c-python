#include <stdio.h>

int search (int vector[], int element, int size)
{
  int i = 0, pos = -1;

  while (pos == -1 && i < size)
    {
      if (vector[i] == element) {
        pos = i;
      } else {
        ++i;
      }
    }

  return pos;
}

void unrepeatedLoad (int vector[], int size)
{
  int i, aux, pos;

  for (i = 0; i < size; ++i) {
    do {
      printf("Insert a number: ");
      scanf("%d", &aux);

      pos = search(vector, aux, i);
      if (pos != -1) {
        printf("Repeated value.\n");
      }
    } while (pos != -1);
    vector[i] = aux;
  }
}

void selectionSort (int vector[], int size)
{
  int i, j, temp, posMin;

  for (i = 0; i < size - 1; ++i) {
    posMin = i;
    for (j = i+1; j < size; ++j) {
      if (vector[j] > vector[posMin]) { // descending order, change > for < to change it to ascending order
        posMin = j;
      }
    }
   temp = vector[posMin];
   vector[posMin] = vector[i];
   vector[i] = temp;
  }
}

void bubbleSort (int vector[], int size)
{
  int i, j, temp;

  for (i = 0; i < size-1; ++i) {
    for (j = 0; j < size-i-1; ++j) {
      if (vector[j] < vector[j+1]) {
        temp = vector[j];
        vector[j] = vector[j+1];
        vector[j+1] = temp;
      }
    }
  }
}

void bubbleSortOptimized (int vector[], int size)
{
  int i, j, temp, change;

  do {
    change = 0;
    for (i = 0; i < size-1; ++i) {
      for (j = 0; j <size-1-i; ++j)
        if (vector[j] > vector[j+1]) {
          temp = vector[j];
          vector[j] = vector[j+1];
          vector[j+1] = temp;

          change = 1;
        }
    }
  } while (change != 0);
}
void printVector (int vector[], int size)
{
  int i;

  for (i = 0; i < size; ++i) {
    printf("%d ", vector[i]);
  }

  printf("\n");
}

int main (void)
{
  int vector[5] = {20, 7, 65, 53, 54};
  bubbleSortOptimized(vector, 5);
  printf("Ascending order: ");
  printVector(vector, 5);

  return 0;
}
