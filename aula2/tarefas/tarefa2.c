#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  char *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char element);
void freeArray(Array *a);

void main()
{
  Array a;
  Array b;
  int i;
  int openD = 0;
  int closeD = 0;

  initArray(&a, 1);
  initArray(&b, 1);

  insertArray(&a, '<');
  insertArray(&a, '<');
  insertArray(&a, '.');
  insertArray(&a, '.');
  insertArray(&a, '<');
  insertArray(&a, '<');
  insertArray(&a, '.');
  insertArray(&a, '.');
  insertArray(&a, '.');
  insertArray(&a, '.');
  insertArray(&a, '.');
  insertArray(&a, '>');
  insertArray(&a, '>');

  for (i = 0; i < a.size; i++)
  {
    if (a.array[i] == '<')
    {
      openD++;
    }
    else if (a.array[i] == '>')
    {
      closeD++;
    }
  }
  if (openD > closeD)
  {
    printf("%d Diamonds\n", closeD);
  }
  else
  {
    printf("%d Diamonds\n", openD);
  }
}

void initArray(Array *a, size_t initialSize)
{
  a->array = malloc(initialSize * sizeof(char));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, char element)
{
  if (a->used == a->size)
  {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(char));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}