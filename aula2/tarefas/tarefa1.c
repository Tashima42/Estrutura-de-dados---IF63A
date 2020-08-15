#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem
{
  int info;
  struct NodeItem *prox;
} node;

typedef struct
{
  node *top;
} stack;

void newStack(stack *p);
void push(stack *p, char value);
char pop(stack *p);
char top(stack *p);
int isEmpty(stack *p);
node *newNode(char value);

int main()
{
  stack pilha;

  newStack(&pilha);
  push(&pilha, 'o');
  push(&pilha, '1');
  pop(&pilha);
  push(&pilha, 'm');
  push(&pilha, 'a');
  pop(&pilha);
  push(&pilha, 'n');
  push(&pilha, 'o');

  while (!isEmpty(&pilha))
  {
    printf("%c ", pop(&pilha));
  }
}

node *newNode(char value)
{
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
  return n;
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
