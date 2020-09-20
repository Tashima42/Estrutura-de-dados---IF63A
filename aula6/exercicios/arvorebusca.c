#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodetype {
  int info;
  struct nodetype *father;
  struct nodetype *left;
  struct nodetype *right;
} node;

int info(node *n);
node *left(node *n);
node *right(node *n);
node *father(node *n);
node *brother(node *n);
int isLeft(node *n);
int isRight(node *n);

node *makeTree(int val);
node *setLeft(node *n, int val);
node *setRight(node *n, int val);
node *setNodeLeft(node *tree, node *n);
node *setNodeRight(node *tree, node *n);
void freeTree(node *n);

void preOrdem(node *n);
void emOrdem(node *n);
void posOrdem(node *n);

int nivel(node *n) {
  if (father(n) == NULL) return 0;
  else return nivel(father(n)) + 1;
}

int isLeaf(node *n) {
  return left(n) == NULL && right(n) == NULL;
}

int altura(node *n) {
  if (n == NULL) {
    return -1;
  }
  if (isLeaf(n)) {
    return nivel(n);
  } else {
    int al, ar;
    al = altura(left(n));
    ar = altura(right(n));
    if (al > ar) return al;
    else return ar;
  }
}

int ehEstrita(node *n) {
  if (n == NULL) {
    return 0;
  } else if (isLeaf(n)) {
    return 1;
  } else {
    return ehEstrita(left(n)) + ehEstrita(right(n)) == 2;
  }
}

int ehBusca(node *n) {
  int ok = 1;
  if (n == NULL) {
    return 1;
  }

  if (left(n) != NULL) {
    ok = info(left(n)) < info(n);
  }
  if (right(n) != NULL) {
    ok = ok && info(n) <= info(right(n));
  }
  return ok && ehBusca(left(n)) && ehBusca(right(n));
}

node *root(node *n) {
  while(father(n) != NULL) {
    n = father(n);
  }
  return n;
}

int ehCompleta(node *n) {
  if (n == NULL) {
    return 0;
  } else if (isLeaf(n)) {
    return nivel(n) == altura(root(n));
  } else {
    return ehCompleta(left(n)) && ehCompleta(right(n));
  }
}

int nlevel(int n) {
  int total = 1;
  while (n > 0) {
    total = 2 * total;
    n--;
  }
  return total;
}

void imprime(node *n) {
  int h = altura(n);
  node *fila[128];
  int base = 0, tail=0;

  fila[tail++] = n;
  for (int i = 0; i<=h; i++) {
    int aux = tail % 128;
    for (int j = base % 128; j < aux; j++) {
      if (fila[j] == NULL) {
        printf(" --- ");
      } else if(isLeaf(fila[j])) {
        printf("(%3d)", info(fila[j]));
        fila[tail++ % 128] = NULL;
        fila[tail++ % 128] = NULL;
      } else {
        printf("[%3d]", info(fila[j]));
        fila[tail++ % 128] = left(fila[j]);
        fila[tail++ % 128] = right(fila[j]);
      }
      base++;
    }
    printf("\n");
  }
}

node *busca(node *tree, int key) {
  if (tree == NULL || info(tree) == key)
    return tree;
  if (key < info(tree))
    return busca(left(tree), key);
  else
    return busca(right(tree), key);
}

node *insert(node *tree, int val) {
  if (tree == NULL)
    return makeTree(val);

  if (val < info(tree)) {
    setNodeLeft(tree, insert(left(tree), val));
  } else {
    setNodeRight(tree, insert(right(tree), val));
  }
  return tree;
  
  /*
  //Versao não recursiva
  aux = tree;
  while(aux != NULL) {
    if (val < info(aux)) {
      if (left(aux) == NULL) {
        aux = setLeft(aux, val);
      }
      aux = left(aux);
    } else {
      if (right(aux) == NULL) {
        aux = setRight(aux, val);
      }
      aux = right(aux);
    }
  }
  */
}

node *deleteRoot(node *tree) {
  node *n, *p;

  if (left(tree) == NULL) {
    n = right(tree);
  } else {
    n = left(tree);
    while(right(n) != NULL) {
      n = right(n);
    }

    if (father(n) != tree) {
      p = father(n);
      setNodeRight(p, left(n));
      setNodeLeft(n, left(tree));
    }
    setNodeRight(n, right(tree));
  }

  if (n != NULL)
    n->father = NULL;

  free(tree);
  return n;
}

node *delete(node *tree, int val) {
  node *n = busca(tree, val);
  node *p = father(n);
  if (p == NULL) {
    return deleteRoot(n);
  }

  if (isLeft(n)) {
    setNodeLeft(p, deleteRoot(n));
  } else {
    setNodeRight(p, deleteRoot(n));
  }

  return tree;
}

node *toBinaryTree(node *tree, int vet[], int a, int b) {
  if (a > b) return NULL;
  int m = (a + b) / 2;

  tree = insert(tree, vet[m]);
  toBinaryTree(tree, vet, a, m-1);
  toBinaryTree(tree, vet, m+1, b);
  return tree;
}

int main() {
  node *tree = NULL, *aux;
  int vet[] = {0,1,2,3,4,5,6,7,8,9,10};
  int num;

  tree = toBinaryTree(tree, vet, 0, 10);
  imprime(tree);
  tree = delete(tree, 9);
  imprime(tree);
  freeTree(tree);
  tree = NULL;

  while (1) {
    printf("Informe o valor: ");
    scanf("%d", &num);
    if (num == -1) break;

    tree = insert(tree, num);
    imprime(tree);
  }
  printf("\n\n--------------------------\n\n");
  while (1) {
    printf("Informe um valor bara busca: ");
    scanf("%d", &num);
    if (num == -1) break;

    aux = busca(tree, num);
    if (aux == NULL) {
      printf("Valor nao encontrado\n");
    } else {
      if (left(aux) == NULL)
        setLeft(aux, 15);
      if (right(aux) == NULL)
        setRight(aux, 22);
      printf("Valor encontrado: [%d]\n\n", info(aux));
    }
    imprime(tree);
  }

  imprime(tree);

  printf("Pre-ordem: ");
  preOrdem(tree);
  printf("\nEm ordem: ");
  emOrdem(tree);
  printf("\nPos-ordem: ");
  posOrdem(tree);

  printf("\nAltura: %d - Estrita: %d - Completa: %d - Busca: %d\n", altura(tree), ehEstrita(tree), ehCompleta(tree), ehBusca(tree));
}


int info(node *n) {
  if (n == NULL)
    return -999;
  return n->info;
}

node *left(node *n) {
  return n->left;
}

node *right(node *n) {
  return n->right;
}

node *father(node *n) {
  return n->father;
}

node *brother(node *n) {
  if (father(n) == NULL) return NULL;
  if (isLeft(n)) return right(father(n));
  else return left(father(n));
}

int isLeft(node *n) {
  if (father(n) == NULL) return 0;
  return left(father(n)) == n;
}

int isRight(node *n) {
  if (father(n) == NULL) return 0;
  return right(father(n)) == n;
}

node *makeTree(int val) {
  node *n = malloc(sizeof(node));
  n->info = val;
  n->father = n->left = n->right = NULL;
  return n;
}

node *setLeft(node *n, int val) {
  n->left = makeTree(val);
  n->left->father = n;
  return n->left;
}

node *setRight(node *n, int val) {
  n->right = makeTree(val);
  n->right->father = n;
  return n->right;
}

node *setNodeLeft(node *tree, node *n) {
  tree->left = n;
  if (n != NULL)
    n->father = tree;
  return n;
}

node *setNodeRight(node *tree, node *n) {
  tree->right = n;
  if (n != NULL)
    n->father = tree;
  return n;
}

void freeTree(node *n) {
  if (n != NULL) {
    node *parent = father(n);
    freeTree(left(n));
    freeTree(right(n));

    if (isLeft(n)) {
      parent->left = NULL;
    } else if (isRight(n)) {
      parent->right = NULL;
    }

    free(n);
  }
}

void preOrdem(node *n) {
  if (n != NULL) {
    printf("[%d]", info(n));
    preOrdem(left(n));
    preOrdem(right(n));
  }
}

void emOrdem(node *n) {
  if (n != NULL) {
    emOrdem(left(n));
    printf("[%d]", info(n));
    emOrdem(right(n));
  }
}

void posOrdem(node *n) {
  if (n != NULL) {
    posOrdem(left(n));
    posOrdem(right(n));
    printf("[%d]", info(n));
  }
}
