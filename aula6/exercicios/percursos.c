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

int main() {
  node *tree;

  tree = makeTree(14);
  setLeft(setLeft(tree, 4), 3);
  setRight(left(tree), 10);
  setLeft(setRight(tree, 22), 18);
  setLeft(setRight(right(tree), 25), 22);

  imprime(tree);

  printf("Pre-ordem: ");
  preOrdem(tree);
  printf("\nEm ordem: ");
  emOrdem(tree);
  printf("\nPos-ordem: ");
  posOrdem(tree);

  printf("\nAltura: %d - Estrita: %d - Completa: %d\n", altura(tree), ehEstrita(tree), ehCompleta(tree));
}


int info(node *n) {
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
