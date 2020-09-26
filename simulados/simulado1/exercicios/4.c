/*
4) (1.5) Escreva o método para encontrar o penúltimo elemento de uma lista simplesmente
encadeada COM CABEÇA. Considere a estrutura ‘node’ apresentada na atividade anterior.
Caso a lista só possua um único elemento, retorno NULO.
*/
typedef struct NodeList
{
  char info;
  struct NodeList *prox;
} node;

node *penultimoElemento(node *list)
{
  node *ant = NULL;

  if (list->prox == NULL)
  {
    return NULL;
  }

  list = list->prox;
  while(list->prox != NULL)
  {
    ant = list;
    list = list->prox;
  }

  return ant;
}
