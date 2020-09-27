#include <stdlib.h>
#include <stdio.h>

#define N 6

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

void removeMultiplesOfThree(stack *s)
{
  stack temp;
  newStack(&temp);
  
  while (!isEmpty(s))
  {
    int popedNumber = pop(s);
    if ((popedNumber % 3) != 0)
    {
      push(&temp, popedNumber);
    }
  }
  while (!isEmpty(&temp))
  {
    push(s, pop(&temp));
  }
}

int main()
{
  stack pilha;

  newStack(&pilha);

  push(&pilha, 3);
  push(&pilha, 4);
  push(&pilha, 5);
  push(&pilha, 6);
  push(&pilha, 7);
  push(&pilha, 9);

  removeMultiplesOfThree(&pilha);

  while (!isEmpty(&pilha))
  {
    printf("%d ", pop(&pilha));
  }
}
