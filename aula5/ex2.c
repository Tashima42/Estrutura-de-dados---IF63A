/*1a - Escreva uma fun��o que inverta uma lista

2a - Escreva uma fun��o que insere n�meros pares no in�cio e �mpares no final

3a - Escreva uma fun��o que permita inserir um elemento em qualquer posi��o da lista. Al�m da lista, a fun��o deve receber o elemento anterior como par�metro da fun��o.

4a - Escreva uma fun��o que some os valores de cada n� da lista

5a - Escreva uma fun��o que retorne o n� que cont�m o maior valor da lista*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 	NodeItem {
    int info;
    struct NodeItem *prox;
}node;

typedef struct{
     node *first;
} list;

//Criar nova Lista
list *NLista (){
	list* L = (list*)malloc(sizeof(list));
	L->first = NULL;
	return L;
}

//Lista Vazia
int Vazio(list *L){
	return L->first==NULL;
}

node *inserirInicio(list *L, int valor){
	node* n=(node*)malloc(sizeof(node));
	n->info=valor;
	n->prox=L->first;
	L->first=n;
	return n;
}

node *inserirFinal(list *L, int valor){
	node *ant;
	node* n=(node*)malloc(sizeof(node));
	if(Vazio(L)){
		inserirInicio(L, valor);
	} else{
		ant=L->first;
		while(ant->prox!=NULL){
			ant = ant->prox;
		} if(ant->prox==NULL){
			n->info = valor;
			ant->prox = n;
			n->prox=NULL;
		}
	}
	return n;
}

//Inserir valor par ou impar
void inserirPI(list*L, int valor){
	node *n;
	if((valor%2)==0){
		inserirInicio(L, valor);
	} else{
		inserirFinal(L, valor);
	}
}

void mostrarLista(list*L){
	   node *n;
	   if(Vazio(L)){
		   printf("Lista Vazia!!!\n");
	   } else{
	   		n=L->first;
		   while(n!=NULL){
			   printf("%d\t", n->info);
			   n = n->prox;
		   }
		   printf("\n");
	   }	
}

void inverter(list* L){
	
	if(Vazio(L)){
		printf("\nLista vazia\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	} else{
		list *nova=NLista();
		node *n;
		for (n=L->first;n!=NULL; n=n->prox){
			inserirInicio(nova, n->info);
		}	
	}	
}

int main(){
	list* L = (list*)malloc(sizeof(list));
	L->first = NULL;
	
	int opc=0, valor, sair=0;
	do{
		printf("\nEscolha uma opcao:\n1-Mostrar lista\n2-Inserir Valor\n3-Inserir elemento em uma posicao\n4-Somar valores\n5-Maior Valor\n10-Sair\n");
		scanf("%d",&opc);
		printf("\n");
		system("Cls");

		switch(opc){
			case 1: 
				mostrarLista(L);
				break;
			case 2:
				printf("Informe um valor inteiro:\t");
				scanf("%d",&valor);
				inserirPI(L, valor);
				system("Cls");
				break;
			case 10: 
				printf("Deseja realmente sair?\n1-Sim\n0-Nao\n");
				scanf("%d",&sair);
				break;
			default:
				printf("\nOpcao Invalida!!!!!!!!\nTente novamente\n");
				break;
		}
	} while(sair!=1);
}									   