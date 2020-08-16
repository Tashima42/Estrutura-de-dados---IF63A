#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  char *array;
  size_t used;
  size_t size;
} Array;

typedef struct NodeItem
{
  int info;
  struct NodeItem *prox;
} node;

typedef struct
{
  node *top;
} stack;

void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, char element);
void freeArray(Array *a);
void newStack(stack *p);
void push(stack *p, char value);
char pop(stack *p);
char top(stack *p);
int isEmpty(stack *p);
node *newNode(char value);
int matchingBrackets(char a, char b);
void removeArray(Array *a);

int main()
{
  stack pilha;
  Array a;
  Array b;
  int i;
  initArray(&a, 1);

  newStack(&pilha);
  push(&pilha, ')');
  push(&pilha, ')');
  push(&pilha, '(');

  while (!isEmpty(&pilha))
  {
    insertArray(&a, pop(&pilha));
  }

  initArray(&b, 1);

  for (i = 0; i < a.size; i++)
  {
    if (a.array[i] == '(' || a.array[i] == '[')
    {
      insertArray(&b, a.array[i]);
    }
    else if (!matchingBrackets(b.array[b.size - 1], a.array[i]) || b.size == 0)
    {
      printf("not balenced");
      break;
    }
    else
    {
      removeArray(&b);
    }
  }

  if (b.size == 0)
  {
    printf("Balenced");
  }

  freeArray(&b);
  freeArray(&a);
}

int matchingBrackets(char a, char b)
{
  if (a == '[' && b == ']')
    return 1;
  else if (a == '(' && b == ')')
    return 1;
  else
    return 0;
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
  if (a->used == a->size)
  {
    a->size = a->size / 2;
    a->array = realloc(a->array, a->size * sizeof(char));
  }
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

node *newNode(char value)
{
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
}

void newStack(stack *p)
{
  p->top = NULL;
}

int isEmpty(stack *p)
{
  return p->top == NULL;
}

void push(stack *p, char value)
{
  node *n = newNode(value);
  n->prox = p->top;
  p->top = n;
}

char pop(stack *p)
{
  node *n;
  int aux;
  aux = top(p);
  n = p->top;
  p->top = n->prox;
  free(n);
  return aux;
}

char top(stack *p)
{
  if (isEmpty(p))
  {
    printf("Stack underflow!\n");
    exit(1);
  }
  return p->top->info;
}
