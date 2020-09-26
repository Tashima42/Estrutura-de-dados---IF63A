/*
6) (2.0) Dada uma pilha de inteiros formada por uma sequência de números positivos,
construa uma função que remova da pilha os valores múltiplos de 3 e mantenha o restante
na sua respectiva ordem.
Exemplo:
==> Empilha os elementos: 3 4 5 6 7 9
==> chama a função desenvolvida
==> Desempilha: 7 5 4
Considere que as seguintes funções já estão implementadas:
void newStack(stack *s);
int isEmpty(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
*/

#define N 5

typedef struct
{
  int top;
  int vet[N];

} stack;

void removeMultiplesOfThree(stack *s)
{
  stack *temp;

  if(isEmpty(s))
  {
    return 0;
  }

  

}