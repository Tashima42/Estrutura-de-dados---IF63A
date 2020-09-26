/*
5) (2.0) Considerando uma lista duplamente encadeada, implemente uma função que
receba 2 nós como parâmetro e teste se estes nós são vizinhos ou possuem um vizinho em
comum. Quando positivo, retorne 1, caso o contrário retorne 0;
*/
typedef struct NodeList
{
  char info;
  struct NodeList *prox;
  struct NodeList *ant;
} node;

int vizinho(node *firstList, node *secondList)
{
  if (firstList == NULL || secondList == NULL)
  {
    return NULL;
  }
  else if (firstList->prox == secondList->ant || secondList->prox == firstList->ant)
  {
    return 1;
  }
  else if (firstList->prox == secondList || firstList->ant == secondList || secondList->prox == firstList || secondList->ant == firstList)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}