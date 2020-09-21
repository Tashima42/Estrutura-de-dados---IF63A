#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct nodetype {
  int data;
  struct nodetype *father;
  struct nodetype *left;
  struct nodetype *right;
} node;

int data(node *n);
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

void preOrder(node *n);
void inOrder(node *n);
void postOrder(node *n);
int isBst(node *n, int min, int max);
int findMax(node *n);
int findMin(node *n);

int level(node *n) {
  if (father(n) == NULL) return 0;
  else return level(father(n)) + 1;
}

int isLeaf(node *n) {
  return left(n) == NULL && right(n) == NULL;
}

int height(node *n) {
  if (n == NULL) {
    return -1;
  }
  if (isLeaf(n)) {
    return level(n);
  } else {
    int al, ar;
    al = height(left(n));
    ar = height(right(n));
    if (al > ar) return al;
    else return ar;
  }
}

int isStrict(node *n) {
  if (n == NULL) {
    return 0;
  } else if (isLeaf(n)) {
    return 1;
  } else {
    return isStrict(left(n)) + isStrict(right(n)) == 2;
  }
}



node *root(node *n) {
  while(father(n) != NULL) {
    n = father(n);
  }
  return n;
}

int isComplete(node *n) {
  if (n == NULL) {
    return 0;
  } else if (isLeaf(n)) {
    return level(n) == height(root(n));
  } else {
    return isComplete(left(n)) && isComplete(right(n));
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

int findInterval(int max, int min) {
  return max - min;
}

void printTree(node *n) {
  int h = height(n);
  node *line[128];
  int base = 0, tail=0;

  line[tail++] = n;
  for (int i = 0; i<=h; i++) {
    int aux = tail % 128;
    for (int j = base % 128; j < aux; j++) {
      if (line[j] == NULL) {
        printf(" --- ");
      } else if(isLeaf(line[j])) {
        printf("(%3d)", data(line[j]));
        line[tail++ % 128] = NULL;
        line[tail++ % 128] = NULL;
      } else {
        printf("[%3d]", data(line[j]));
        line[tail++ % 128] = left(line[j]);
        line[tail++ % 128] = right(line[j]);
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

  printTree(tree);

  printf("Pre-order: ");
  preOrder(tree);
  printf("\nIn order: ");
  inOrder(tree);
  printf("\nPost-order: ");
  postOrder(tree);

  printf("\nHeight: %d - Strict: %d - Complete: %d - BST: %d - Interval: %d\n", height(tree), isStrict(tree), isComplete(tree), isBst(tree, INT_MIN, INT_MAX), findInterval(findMax(tree), findMin(tree)));
}

int data(node *n) {
  return n->data;
}

node *left(node *n){
  return n->left;
}

node *right(node *n){
  return n->right;
}

node *father(node *n){
  return n->father;
}

node *brother(node *n){
  if(father == NULL) return NULL;
  if(isLeft(n)) return right(father(n));
  else return left(father(n));
}

int isLeft(node *n){
  if(father(n) == NULL) return 0;
  return left(father(n)) == n;
}

int isRight(node *n){
  if(father(n) == NULL) return 0;
  return right(father(n)) == n;
}

node *makeTree(int val) {
  node *n = malloc(sizeof(node));
  n->data = val;
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

void preOrder(node *n) {
  if (n != NULL) {
    printf("[%d]", data(n));
    preOrder(left(n));
    preOrder(right(n));
  }
}

void inOrder(node *n) {
  if (n != NULL) {
    inOrder(left(n));
    printf("[%d]", data(n));
    inOrder(right(n));
  }
}

void postOrder(node *n) {
  if (n != NULL) {
    postOrder(left(n));
    postOrder(right(n));
    printf("[%d]", data(n));
  }
}

int isBst(node *n, int min, int max){
  if(n == NULL)
    return 1;
  if(n->data < min)
    return 0;
  if(n->data > max)
    return 0;
  return isBst(n->right, n ->data, max) && isBst(n->left, min, n->data);
}

int findMax(node *n) {
  if(n == NULL)
    return INT_MIN;

  int nodeData = n->data;
  int leftData = findMax(n->left);
  int rightData = findMax(n->right);
  if(leftData > nodeData)
    nodeData = leftData;
  if(rightData > nodeData)
    nodeData = rightData;
  
  return nodeData;
}

int findMin(node *n) {
  if(n == NULL)
    return INT_MAX;

  int nodeData = n->data;
  int leftData = findMin(n->left);
  int rightData = findMin(n->right);
  if(leftData < nodeData)
    nodeData = leftData;
  if(rightData < nodeData)
    nodeData = rightData;
  
  return nodeData;
}