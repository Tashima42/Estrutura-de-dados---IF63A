#include <stdlib.h>
#include <stdio.h>

#define N 5

typedef struct
{
  int top;
  int vet[N];

} stack;

void newStack(stack *s)
{
  s->top = 0;
}

int isEmpty(stack *s)
{
  return s->top == 0;
}

int isFull(stack *s)
{
  return s->top == N;
}

void push(stack *s, int value)
{
  if (isFull(s))
  {
    printf("Stack overflow!\n");
    exit(1);
  }

  s->vet[s->top++] = value;
}

int pop(stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow!\n");
    exit(1);
  }
  s->top--;
  return s->vet[s->top];
}

int top(stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow!\n");
    exit(1);
  }
  return s->vet[s->top - 1];
}

int main()
{
  stack pilha;

  newStack(&pilha);

  push(&pilha, 3);
  push(&pilha, 4);
  pop(&pilha);
  push(&pilha, 5);
  push(&pilha, 6);
  pop(&pilha);
  push(&pilha, 7);
  push(&pilha, 8);
  while (!isEmpty(&pilha))
  {
    printf("%d ", pop(&pilha));
  }
}
