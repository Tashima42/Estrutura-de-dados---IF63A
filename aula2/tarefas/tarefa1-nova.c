/*
  Passei horas nesse exercício e não consegui encontrar qual o bug que não deixa ele funcionar, mas essa é a lógica que usei para resolver o problema:

  Ao invés de usar o estilho de pilhas apresentado na aula, achei que seria mais fácil trabalhar com um array A alocado dinamicamente.
  Um loop for passa por todos os elementos do array A, se for um de abertura, como '(' ou '[', ele é adicionado em um array B. Caso seja um de fechamento, é feita uma verificação se o elemento for contrário ao que está topo da pilha (array B), o topo é removido, caso não seja, o algoritmo retorna que não está balanceado.  
*/

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
void removeArray(Array *a);
int matchingBrackets(char a, char b);

void main()
{
  Array a;
  Array b;
  int i;
  int bPlus = 0;

  initArray(&a, 1);
  initArray(&b, 1);

  insertArray(&a, '(');
  insertArray(&a, ')');

  for (i = 0; i < a.size; i++)
  {
    if (a.array[i] == '(' || a.array[i] == '[')
    {
      insertArray(&b, a.array[i]);
      bPlus++;
    }

    else if ((matchingBrackets(b.array[bPlus - 1], a.array[i]) != 0) || b.size == 0)
    {
      printf("not balenced\n");
      break;
    }
    else
    {
      if (bPlus != 0)
      {
        removeArray(&b);
        bPlus--;
      }
    }
  }
  if (bPlus == 0)
  {
    printf("Balenced\n");
  }

  freeArray(&a);
  freeArray(&b);
}

int matchingBrackets(char a, char b)
{
  if (a == '[' && b == ']')
  {
    return 1;
  }
  else if (a == '(' && b == ')')
  {
    return 1;
  }
  else
  {
    return 0;
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

void removeArray(Array *a)
{
  a->size = a->size / 2;
  a->array = realloc(a->array, a->size * sizeof(char));
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}