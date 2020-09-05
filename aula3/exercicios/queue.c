#include <stdlib.h>
#include <stdio.h>

#define N 50

typedef struct {
   int head;
   int tail;
   int vet[N];
} queue;

void newQueue(queue *q);
void enqueue(queue *q, int value);
int dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
void showQueue(queue *q);

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

void newQueue(queue *q) {
  q->head = 0;
  q->tail = 0;
}

int isEmpty(queue *q) {
  return q->head == q->tail;
}

int isFull(queue *q) {
  return q->tail == N;
}

void enqueue(queue *q, int value) {
  if (isFull(q)) {
    printf("Queue overflow!\n");
    exit(1);
  }
  q->vet[q->tail++] = value;
}

int dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow!\n");
    exit(1);
  }
  return q->vet[q->head++];
}


void showQueue(queue *q) {
  int i;
  printf("Queue: ");
  for (i=q->head; i<q->tail; i++) {
    printf("%d ", q->vet[i]);
  }
  printf("\n");
}
