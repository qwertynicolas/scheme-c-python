#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void randomLoad (int v[], int size, int max)
{
  int i;

  for (i = 0; i < size; ++i) {
    v[i] = rand() % max;
  }
}

void show (int v[], int size)
{
  int i;

  for (i = 0; i < size; ++i) {
    printf("%d\n", v[i]);
  }
}

int main (void)
{
  int vec[SIZE];
  srand(time(NULL));
  randomLoad(vec, SIZE, 100);
  show(vec, SIZE);

  return 0;
}
