/*
3) (1.5) Escreva o método DEQUEUE de uma fila utilizando a estrutura dinâmica a seguir.
Considere que se head é nulo a fila está vazia e se a fila está vazia, retorne o ‘\0’.
*/
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

char dequeue(queue *f)
{
  node *n;
  char aux;

  if (f->head != NULL)
  {
    n = f->head;
    aux = n->info;
    free(n);
    return aux;
  }

  return '\0';
}