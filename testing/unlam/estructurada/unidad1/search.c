#include <stdio.h>

int search (int v[], int element, int size)
{
  int i = 0;
  int pos = -1;

  while (pos == -1 && i < size) {
    if (v[i] == element) {
      pos = i;
    } else {
      i++;
    }
  }

  return pos;
}

int binarySearch (int v[], int x, int low, int high) // límite inferior y límite superior, respectivamente
{
  int mid;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (v[mid] == x) {
      return mid;
    }

    if (x > v[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

void bubbleSortOptimized (int v[], int size)
{
  int i, j, temp, change;

  do {
    change = 0;

    for (i = 0; i < size-1; ++i) {
      for (j = 0; j < size-i-1; ++j) {
        if (v[j+1] < v[j]) {
          temp = v[j];
          v[j] = v[j+1];
          v[j+1] = temp;

          change = 1;
        }
      }
    }
  } while (change != 0);
}
void unrepeatedLoad (int v[], int size)
{
  int i, pos, aux;
  for (i = 0; i < size; ++i) {
    do {
      printf("Insert a number: ");
      scanf("%d", &aux);

      pos = search(v, aux, i);

      if (pos != -1) {
        printf("Repeated value. Insert again\n");
      }
    } while (pos != -1);

    v[i] = aux;
  }
}

int main (void)
{
  int i, vector[10];

  unrepeatedLoad(vector, 10);
  bubbleSortOptimized (vector, 10);

  char lookUp;
  int x, position;

  do {
  printf("\nDo you wish to search for a certain element? (Y/N): ");
  scanf(" %c", &lookUp);

  if (lookUp == 'Y') {
    printf("Insert the element you are looking for: ");
    scanf("%d", &x);

    position = binarySearch (vector, x, 0, 9);

    if (position != -1) {
      printf("The element is in the position %d.", position);
    } else {
      printf("The element is not in the array.");
    }

  }
  } while (lookUp != 'N');

  printf("\n");
  printf("Vector values (ascending order): ");
  for (i = 0; i < 10; ++i) {
    printf("%d ", vector[i]);
  }

  printf("\n");

  return 0;
}
