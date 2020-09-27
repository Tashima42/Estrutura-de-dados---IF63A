typedef struct NodeList
{
  char info;
  struct NodeList *prox;
} node;

typedef struct
{
  node *head;
  node *tail;
} queue;

void enqueue(queue *f, node *n)
{
  if (f->head == NULL)
  {
    f->head = f->tail = n;
  }
  else
  {
    f->tail->prox = n;
    f->tail = n;
  }
}