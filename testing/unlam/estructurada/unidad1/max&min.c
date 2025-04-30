 #include <stdio.h>

void load (int v[], int size)
{
  int i;

  for (i = 0; i < size; ++i) {
    printf("Insert a number: ");
    scanf("%d", &v[i]);
  }
}

int maximum (int v[], int size)
{
  int max = v[0], i;

  for (i = 1; i < size; ++i) {
    if (v[i] > max) {
      max = v[i];
    }
  }

  return max;
}

void showMaximum (int v[], int max, int n)
{
  int counter = 0, i;

  printf("The maximum value is %d and it's on the positions: ", max);

  for (i = 0; i < n; ++i) {
    if (v[i] == max) {
      printf("%d ", i+1);
      counter++;
    }
  }

  printf("\n");
  printf("The maximum value repeats %d times.\n", counter);
}

int main (void)
{
  int vec[10], max;

  load(vec, 10);
  max = maximum(vec, 10);
  showMaximum(vec, max, 10);

  return 0;
}
