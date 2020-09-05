/*1b - Escreva um fun��o que mostre uma lista duplamente encadeada na ordem contr�ria

2b - Escreva uma fun��o que insere n�meros pares no in�cio e �mpares no final

3b - Escreva uma fun��o que insere os elementos na lista de forma ordenada

4b - Escreva uma fun��o que ordene uma lista em ordem decrescente

5b - Escreva uma fun��o que remova o maior elemento de uma lista*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeItem
{
	int info;
	struct NodeItem *prox;
	struct NodeItem *ant;
} node;

typedef struct
{
	node *first;
	node *last;
} list;

int vazio(list *l)
{
	return l->first == NULL;
}

list *novaLista()
{
	list *l = (list *)malloc(sizeof(list));
	l->first = NULL;
	l->last = NULL;
	return l;
}

node *novoNo(int valor)
{
	node *n = (node *)malloc(sizeof(node));
	n->info = valor;
	n->ant = NULL;
	n->prox = NULL;
	return n;
}

node *addInicio(list *l, int valor)
{
	node *n = novoNo(valor);
	if (vazio(l))
	{
		l->first = n;
		l->last = n;
	}
	else
	{
		n->prox = l->first;
		l->first->ant = n;
		l->first = n;
	}
	return n;
}

node *addFim(list *l, int valor)
{
	node *n = novoNo(valor);
	if (vazio(l))
	{
		l->first = n;
		l->last = n;
	}
	else
	{
		n->ant = l->last;
		l->last->prox = n;
		l->last = n;
	}
	return n;
}

void inserir(list *l, int valor)
{
	node *n;
	if ((valor % 2) == 0)
	{
		addInicio(l, valor);
	}
	else
	{
		addFim(l, valor);
	}
}

void mostrarLista(list *l)
{
	node *n;
	if (vazio(l))
	{
		printf("Lista vazia\n");
	}
	else
	{
		n = l->first;
		while (n != NULL)
		{
			if (n->ant != NULL && n->prox != NULL)
				printf("-> [%d]\t", n->info);
			else if (n->ant != NULL)
				printf("-> [%d]\t", n->info);
			else if (n->prox != NULL)
				printf("-> [%d]\t", n->info);
			else
				printf("-> [%d]\t", n->info);
			n = n->prox;
		}
		printf("\n");
	}
}

void mostrarListaInvertida(list *l)
{
	node *n;
	if (vazio(l))
	{
		printf("Lista vazia\n");
	}
	else
	{
		n = l->last;
		while (n != NULL)
		{
			printf("-> [%d]\t", n->info);
			n = n->ant;
		}
		printf("\n");
		n = l->first;
	}
}

int maiorValor(list *l)
{
	node *n;
	int maior = 0;
	n = l->first;
	while (n != NULL)
	{
		if (n->info > maior)
		{
			maior = n->info;
		}
		n = n->prox;
	}
	printf("Maior: %d", maior);
	return maior;
}

node *encontrarNo(list *l, int maior)
{
	node *n;
	n = l->first;
	while (n != NULL && n->info != maior)
	{
		n = n->prox;
	}
	return n;
}

void Remover(list *l, int maior)
{
	node *n, *ant, *prox;
	n = encontrarNo(l, maior);
	if (n != NULL)
	{
		ant = n->ant;
		prox = n->prox;
		if (n == l->first)
		{
			l->first = prox;
		}
		if (n == l->last)
		{
			l->last = ant;
		}
		if (ant != NULL)
		{
			ant->prox = prox;
		}
		if (prox != NULL)
		{
			prox->ant = ant;
		}
		free(n);
	}
}

int main()
{
	list *l = (list *)malloc(sizeof(list));
	l->first = NULL;

	int opc = 0, valor, sair = 0, remover;
	do
	{
		printf("\nEscolha uma opcao:\n1-Inserir valor\n2-Mostrar lista\n3-Inverter lista\n4-Lista crescente\n5-Lista decrescente\n6-Remover maior valor\n7-Sair\n\n");
		scanf("%d", &opc);
		printf("\n");
		system("Cls");

		switch (opc)
		{
		case 1:
			printf("Informe um valor inteiro:\t");
			scanf("%d", &valor);
			inserir(l, valor);
			system("Cls");
			break;
		case 2:
			mostrarLista(l);
			break;
		case 3:
			mostrarListaInvertida(l);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			remover = maiorValor(l);
			encontrarNo(l, remover);
			Remover(l, remover);
			break;
		case 7:
			printf("Deseja realmente sair?\n1-Sim\n0-Nao\n");
			scanf("%d", &sair);
			break;
		default:
			printf("\nOpcao Invalida!!!!!!!!\nTente novamente\n");
			break;
		}
	} while (sair != 1);
}