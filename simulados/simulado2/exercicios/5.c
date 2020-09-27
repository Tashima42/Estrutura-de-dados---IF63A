typedef struct NodeList
{
  int info;
  struct NodeList *prev;
  struct NodeList *next;
} node;

node *split(node *L, int value)
{
  node *foundNode, *nextNode = NULL;
  foundNode = findNode(L, value);
  if (foundNode != NULL)
  {
    nextNode = foundNode->next;
    foundNode->next = NULL;
    if(nextNode != NULL)
    {
      nextNode->prev = NULL;
    }
  }
  return nextNode;
}