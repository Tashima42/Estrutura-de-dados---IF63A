typedef struct
{
  int head;
  int tail;
  int vet[5];
} queue;

void removeEvenNumbers(queue *q)
{
  queue temp;
  newQueue(&temp);
  while (!isEmpty(q))
  {
    if ((q->vet[q->head]) % 2 != 0)
    {
      enqueue(&temp, dequeue(q));
    }
    dequeue(q);
  }
}