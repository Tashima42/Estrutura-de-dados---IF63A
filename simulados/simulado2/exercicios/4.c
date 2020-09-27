typedef struct NodeList
{
  char info;
  struct NodeList *prox;
} node;

node *findNode(node *list, char value)
{
  while (list != NULL && list->info != value)
  {
    list = list->prox;
  }
  return list;
}