#include <stdlib.h>
#include <stdio.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

void newQueue(queue *f);
void enqueue(queue *f, int value);
int dequeue(queue *f);
int isEmpty(queue *f);
node *newNode(int value);
void showQueue(queue *f);

int main() {
  queue q;

  newQueue(&q);
  //dequeue(&q);
  enqueue(&q, 21);
  showQueue(&q);
  enqueue(&q, 13);
  showQueue(&q);
  enqueue(&q, 44);
  showQueue(&q);
  enqueue(&q, 2);
  showQueue(&q);
  enqueue(&q, 5);
  showQueue(&q);
  printf("Removido %d\n", dequeue(&q));
  showQueue(&q);
  printf("Removido %d\n", dequeue(&q));
  showQueue(&q);
  enqueue(&q, 12);
  showQueue(&q);
}

node *newNode(int value) {
  node *n = (node *)malloc(sizeof(node));
  n->info = value;
  n->prox = NULL;
  return n;
}

void newQueue(queue *f){
  f->head = NULL;
}

int isEmpty(queue *f) {
  return f->head == NULL;
}

void enqueue(queue *f, int value) {
  node *n = newNode(value);
  if (isEmpty(f)) {
    f->head = f->tail = n;
  } else {
    f->tail->prox = n;
    f->tail = n;
  }
}

int dequeue(queue *f) {
  node *n;
  int aux;

  if (isEmpty(f)) {
    printf("Queue underflow!\n");
    exit(1);
  }

  aux = f->head->info;
  n = f->head;
  f->head = n->prox;
  free(n);
  return aux;
}

void showQueue(queue *f) {
  node *n = f->head;
  printf("Fila:\n");
  while(n != NULL) {
    printf("[%d]", n->info);
    n = n->prox;
  }
  printf("\n");
}
