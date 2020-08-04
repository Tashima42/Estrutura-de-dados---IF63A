#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int hour;
  int min;
  int sec;
} time;

long int toSec(time *t);              //Transforma um time para segundos
time *fromSec(long int s);            //Transforma segundos para um time

time *readTime();                     //Faz a leitura de um time
void showTime(time *t);               //Exibe um time
time *addSec(time *t, long int sec);  //Adiciona segundos a um time
time *decSec(time *t, long int sec);  //Retira segundos de um time
time *timeDiff(time *t1, time *t2);   //Calcula a diferenca entre 2 times

int main() {
  time *t1, *t2, *t3;
  long int secs;

  t1 = fromSec(10234);
  secs = toSec(t1);

  printf("%ld segundos = ", secs);
  showTime(t1);

  t2 = readTime();
  printf("%ld segundos = ", toSec(t2));
  showTime(t2);

  t3 = timeDiff(t2, t1);
  printf("Diferenca:\n");
  printf("%ld segundos = ", toSec(t3));
  showTime(t3);

  printf("Aumentando 60 segundos: ");
  showTime(addSec(t3, 60));

  printf("Diminuindo 2 minutos e 3 segundos: ");
  showTime(decSec(t3, 123));

  return 0;
}

long int toSec(time *t) {
  return t->hour * 3600 + t->min * 60 + t->sec;
}

time* fromSec(long int s) {
  time *t = (time *) malloc(sizeof(time));
  t->hour = s / 3600;
  s = s % 3600;
  t->min = s / 60;
  t->sec = s % 60; 
  return t;
}

time *readTime() {
  time *t = fromSec(0);
  printf("Informe a hora: ");
  scanf("%d", &t->hour);
  printf("Informe o minuto: ");
  scanf("%d", &t->min);
  printf("Informe o segundo: ");
  scanf("%d", &t->sec);

  return t;
}

void showTime(time *t) {
  printf("%dh %dm %ds\n", t->hour, t->min, t->sec);
}

time *addSec(time *t, long int sec) {
  time *aux;
  aux = fromSec(toSec(t) + sec);
  t->hour = aux->hour;
  t->min = aux->min;
  t->sec = aux->sec;
  free(aux);
  return t;
}

time *decSec(time *t, long int sec) {
  time *aux;
  long int total = toSec(t) - sec;
  if (total < 0) {
    printf("Warning: Tempo em segundos invalido!\n");
    return t;
  }
  aux = fromSec(total);
  t->hour = aux->hour;
  t->min = aux->min;
  t->sec = aux->sec;
  free(aux);
  return t;
}

time *timeDiff(time *t1, time *t2) {
  long int v1, v2;
  v1 = toSec(t1);
  v2 = toSec(t2);
  if (v1 > v2) {
    return fromSec(v1 - v2);
  } else {
    return fromSec(v2 - v1);
  }
}
