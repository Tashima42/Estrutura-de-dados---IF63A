/* 1 - Desenvolva um sistema para controlar a fila de um banco. O sistema possui 2 funções: 

  a) incluir nova pessoa, 
  b) realizar atendimento

Ao ativar a função A, registre o nome da pessoa e a inclua na fila de espera. Ao ativar a função B, informe em qual mesa será realizado o atendimento.
*/
#include <stdlib.h>
#include <stdio.h>

#define N 50
#define O 10

typedef struct
{
  int head;
  int tail;
  char vet[N][O];
} queue;

void newQueue(queue *q);
void enqueue(queue *q, char value);
char dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
void showQueue(queue *q);

int main()
{
  queue q;

  newQueue(&q);
  //dequeue(&q);
  enqueue(&q, 'hey');
  showQueue(&q);
  printf("Removido %s\n", dequeue(&q));
}

void newQueue(queue *q)
{
  q->head = 0;
  q->tail = 0;
}

int isEmpty(queue *q)
{
  return q->head == q->tail;
}

int isFull(queue *q)
{
  return q->tail == N;
}

void enqueue(queue *q, char value)
{
  if (isFull(q))
  {
    printf("Queue overflow!\n");
    exit(1);
  }
  q->vet[q->tail++] = value;
}

char dequeue(queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue underflow!\n");
    exit(1);
  }
  return q->vet[q->head++];
}

void showQueue(queue *q)
{
  int i;
  printf("Queue: ");
  for (i = q->head; i < q->tail; i++)
  {
    printf("%s ", q->vet[i]);
  }
  printf("\n");
}
