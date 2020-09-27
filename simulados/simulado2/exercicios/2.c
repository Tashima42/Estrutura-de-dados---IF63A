#define N 5

typedef struct
{
  int base;
  int top;
} stack;

int pop(int pilha[N], stack *s)
{
  if (s->base == s->top)
  {
    return -1;
  }
  s->top--;
  return pilha[s->top];
}