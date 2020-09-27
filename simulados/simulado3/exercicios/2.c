#include <stdio.h>
#define N 9

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i ++)
  {
    printf("%d-", arr[i]);
  }
  printf("\n");
}

int main()
{
  int studentsAges[N] = {13, 14, 15, 4, 6, 8, 28, 2, 5};
  
  printArray(studentsAges, N);
  insertionSort(studentsAges, N);
  printArray(studentsAges, N);
  
}