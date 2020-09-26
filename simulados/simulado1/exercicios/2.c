/*
2) (1.5) Escreva a função PUSH para implementar uma pilha em vetor estático, conforme a
estrutura de dados a seguir. Considere que a propriedade top é controlada na primeira
posição (índice 0) do vetor VET e que TOP aponta para a próxima posição a ser inserida na
pilha. Caso necessite de uma função adicional, você também deverá implementá-la.
*/
#define N 10

typedef struct
{
  int vet[N];
} stack;

void push(stack *s, int value);

int main()
{
}

void push(stack *s, int value)
{
  if (s->vet[0] == N)
  {
    return;
  }
  s->vet[s->vet[0]] = value;
  s->vet[0]++;
}