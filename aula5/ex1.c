/*
1b - Escreva um função que mostre uma lista duplamente encadeada na ordem contrária

2b - Escreva uma função que insere números pares no início e ímpares no final

3b - Escreva uma função que insere os elementos na lista de forma ordenada

4b - Escreva uma função que ordene uma lista em ordem decrescente

5b - Escreva uma função que remova o maior elemento de uma lista
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeItem
{
	int info;
	struct NodeItem *next;
	struct NodeItem *prev;
} node;

typedef struct
{
	node *head;
	node *tail;
} list;

int empty(list *l)
{
	return l->head == NULL;
}

list *newList()
{
	list *l = (list *)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;
	return l;
}

node *newNode(int value)
{
	node *n = (node *)malloc(sizeof(node));
	n->info = value;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

node *addToHead(list *l, int value)
{
	node *n = newNode(value);
	if (empty(l))
	{
		l->head = n;
		l->tail = n;
	}
	else
	{
		n->next = l->head;
		l->head->prev = n;
		l->head = n;
	}
	return n;
}

node *addToTail(list *l, int value)
{
	node *n = newNode(value);
	if (empty(l))
	{
		l->head = n;
		l->tail = n;
	}
	else
	{
		n->prev = l->tail;
		l->tail->next = n;
		l->tail = n;
	}
	return n;
}

void insertItemAndseparateEvenAndOdd(list *l, int value)
{
	node *n;
	if ((value % 2) == 0)
	{
		addToHead(l, value);
	}
	else
	{
		addToTail(l, value);
	}
}

void printList(list *l)
{
	node *n;
	if (empty(l))
	{
		printf("Lista vazia\n");
	}
	else
	{
		n = l->head;
		while (n != NULL)
		{
			if (n->prev != NULL && n->next != NULL)
				printf("-> [%d]\t", n->info);
			else if (n->prev != NULL)
				printf("-> [%d]\t", n->info);
			else if (n->next != NULL)
				printf("-> [%d]\t", n->info);
			else
				printf("-> [%d]\t", n->info);
			n = n->next;
		}
		printf("\n");
	}
}

void printListBackward(list *l)
{
	node *n;
	if (empty(l))
	{
		printf("Lista vazia\n");
	}
	else
	{
		n = l->tail;
		while (n != NULL)
		{
			printf("-> [%d]\t", n->info);
			n = n->prev;
		}
		printf("\n");
		n = l->head;
	}
}

int biggestValue(list *l)
{
	node *n;
	int biggest = 0;
	n = l->head;
	while (n != NULL)
	{
		if (n->info > biggest)
		{
			biggest = n->info;
		}
		n = n->next;
	}
	printf("biggest: %d", biggest);
	return biggest;
}

node *findNode(list *l, int biggest)
{
	node *n;
	n = l->head;
	while (n != NULL && n->info != biggest)
	{
		n = n->next;
	}
	return n;
}

void removeNode(list *l, int biggest)
{
	node *n, *prev, *next;
	n = findNode(l, biggest);
	if (n != NULL)
	{
		prev = n->prev;
		next = n->next;
		if (n == l->head)
		{
			l->head = next;
		}
		if (n == l->tail)
		{
			l->tail = prev;
		}
		if (prev != NULL)
		{
			prev->next = next;
		}
		if (next != NULL)
		{
			next->prev = prev;
		}
		free(n);
	}
}

void orderListDescending(list *l)
{
	int aux = 0;
	node *n, *s;

	for (n = l->head; n; n = n->next)
	{
		for (s = l->head; s; s = s->next)
		{
			if (s->info < n->info)
			{
				aux = n->info;
				n->info = s->info;
				s->info = aux;
			}
		}
	}
}

void orderListAscending(list *l)
{
	int aux = 0;
	node *n, *s;

	for (n = l->head; n; n = n->next)
	{
		for (s = l->head; s; s = s->next)
		{
			if (s->info > n->info)
			{
				aux = n->info;
				n->info = s->info;
				s->info = aux;
			}
		}
	}
}

int main()
{
	list *l = (list *)malloc(sizeof(list));
	l->head = NULL;

	int opc = 0, value, sair = 0, remover;
	do
	{
		printf("\nChoose an option:\n1 - Insert value\n2 - Show list\n3 - Show list backwards\n4 - List ascending order\n5 - List descending order\n6 - Remove biggest value\n7 - Exit\n\n");
		scanf("%d", &opc);
		printf("\n");

		switch (opc)
		{
		case 1:
			printf("Informe um value inteiro:\t");
			scanf("%d", &value);
			insertItemAndseparateEvenAndOdd(l, value);
			break;
		case 2:
			printList(l);
			break;
		case 3:
			printListBackward(l);
			break;
		case 4:
			orderListAscending(l);
			printList(l);
			break;
		case 5:
			orderListDescending(l);
			printList(l);
			break;
		case 6:
			remover = biggestValue(l);
			findNode(l, remover);
			removeNode(l, remover);
			break;
		case 7:
			printf("Exit?\n1 - Yes\n0 - No\n");
			scanf("%d", &sair);
			break;
		default:
			printf("\nInvalid Option\n");
			break;
		}
	} while (sair != 1);
}