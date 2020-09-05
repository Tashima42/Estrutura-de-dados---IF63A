#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
} node;

typedef struct list
{
    node* head;
} list;

void printList(list*);
list* newList(list*);
node* insertBegining(list*, int);
node* insertTail(list*, int);
node* insertEvenOrOdd(list*, int);
node* insertPosition(list*, int, node*);
node* findNode(list*, int);
int sumValues(list*);
int findBiggestValue(list*);
list* invertList(list*);

int main()
{
    list* l;
    int menu, value, position, biggestValue, sumOfValues;
    node* anterior;

    l=newList(l);

    do{
        printf("1) Insert a value in a specific position\n");
        printf("2) Print the biggest value on the list\n");
        printf("3) Insert a even or odd number\n");
        printf("4) Insert a value on the head\n");
        printf("5) Insert a value on the tail\n");
        printf("6) Sum all the values on the list\n");
        printf("7) Invert list\n");
        printf("8) Show list\n");
        printf("9) Exit\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Type the number: ");
                scanf("%d", &value);
                printf("Position: ");
                scanf("%d", &position);
                anterior = findNode(l, position);
                if(insertPosition(l, value, anterior)){
                    printf("Inserted\n\n");
                }
                break;
            case 2:
                biggestValue=findBiggestValue(l);
                printf("Biggest value:  %d\n\n", biggestValue);
                break;
            case 3:
                printf("Type the number: ");
                scanf("%d", &value);
                insertEvenOrOdd(l, value);
                printf("Inserted\n\n");
                break;
            case 4:
                printf("Type the number: ");
                scanf("%d", &value);
                insertBegining(l, value);
                printf("Inserted\n\n");
                break;
            case 5:
                printf("Type the number: ");
                scanf("%d", &value);
                insertTail(l, value);
                printf("Inserted\n\n");
                break;
            case 6:
                sumOfValues=sumValues(l);
                printf("Sum of all values: %d\n\n", sumOfValues);
                break;
            case 7:
                l=invertList(l);
                printf("Inverted list: \n\n");
                printList(l);
                printf("\n\n");
                break;
            case 8:
                printf("List: \n\n");
                printList(l);
                printf("\n\n");
                break;
            case 9:
                printf("Exited\n\n");
                break;
        }
    }while(menu>0 && menu<9);

    return 0;


}

int sumValues(list *l){
    int sum=0;
    node* aux;
    for(aux=l->head; aux!=NULL;aux=aux->next){
        sum+=aux->info;
    }
    return sum;
}

int findBiggestValue(list* l){
    int biggest;
    node* aux;
    biggest=l->head->info;
    for(aux=l->head; aux!=NULL;aux=aux->next){
        if(aux->info>biggest){
            biggest=aux->info;
        }
    }
    return biggest;
}

node* findNode(list* l, int position){
    int i=0;
    node* aux;
    for(aux=l->head; aux!=NULL;aux=aux->next){
        if(i==position){
            return aux;
        }
        i++;
    }
    printf("This position doesn't exist\n");
    return NULL;
}

void printList(list* list){
    node* aux;
    if(list->head==NULL){
        printf("Empty list\n");
        return;
    }
    for(aux = list->head; aux != NULL; aux = aux->next){
        if(aux->next!=NULL){
            printf("[%d]->", aux->info);
        }else{
            printf("[%d]-||", aux->info);
        }
    }
}

list* invertList(list* l){
    list* new=newList(new);
    node* aux;
    for(aux = l->head; aux != NULL; aux = aux->next){
        insertBegining(new, aux->info);
    }
    return new;
}

list* newList(list* l){
    l=(list*)malloc(sizeof(list));
    l->head=NULL;
    return l;
}

node* insertEvenOrOdd(list* l, int value){
    if(value%2){
        return insertTail(l, value);
    }
    return insertBegining(l, value);
}

node* insertPosition(list* l, int value, node* anterior){
    node* aux;
    node* new;
    for(aux=l->head; aux!=NULL;aux=aux->next){
        if(aux==anterior){
            new=(node*)malloc(sizeof(node));
            new->info=value;
            new->next=aux->next;
            aux->next=new;
            return aux;
        }
    }
    printf("No nao encontrado! Valor nao inserido\n");
    return NULL;
}

node* insertBegining(list* list, int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->info = value;
    temp->next = list->head;
    list->head = temp;
    return temp;
}

node* insertTail(list* l, int num)
{
    node* new;
    node* aux;

    new = (node*)malloc(sizeof(node));
    new->info = num;
    new->next = NULL;

    if(l->head==NULL)
    {
        l->head=new;
        return new;
    }
    for(aux = l->head; aux!=NULL; aux = aux->next)
    {
        if(aux->next==NULL)
        {
            aux->next = new;
            return l->head;
        }
    }
    return NULL;
}