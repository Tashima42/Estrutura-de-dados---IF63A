#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
} node;

typedef struct {
  node *top;
} stack;

void newStack(stack *p);
void push(stack *p, int value);
int pop(stack *p);
int top(stack *p);
int isEmpty(stack *p);
node *newNode(int value);

int main() {
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

  while (!isEmpty(&pilha)) {
    printf("%d ", pop(&pilha));
  }
}

node *newNode(int value) {
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
  return n;
}

void newStack(stack *p){
  p->top = NULL;
}

int isEmpty(stack *p) {
  return p->top == NULL;
}

void push(stack *p, int value) {
  node *n = newNode(value);
  n->prox = p->top;
  p->top = n;
}

int pop(stack *p) {
  node *n;
  int aux;
  aux = top(p);
  n = p->top;
  p->top = n->prox;
  free(n);
  return aux;
}

int top(stack *p) {
  if (isEmpty(p)) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return p->top->info;
}
