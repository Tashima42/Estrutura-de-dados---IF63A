#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, int element);
void freeArray(Array *a);

void main()
{
  Array a;

  initArray(&a, 1);

  newCar(&a, 1);
  newCar(&a, 2);
}

void newCar(Array a, int carPlate)
{
  insertArray(a, carPlate);
}

void removeCar(jj, int carPlate)
{
}

void initArray(Array *a, size_t initialSize)
{
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element)
{
  if (a->used == a->size)
  {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}