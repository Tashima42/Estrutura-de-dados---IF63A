# Alocação dinâmica de memória
Quando uma variável é declarada, um determinado espaço na memória é reservado para ela e um endereço.
```c
int main() {
	int i, j, k;
	
	printf('%u\n', &i);
	printf('%u\n', &j);
	printf('%u\n', &k);

	return 0;
}
```

Quando essa apicação for executada, retornará não o valor da variável, mas seu endereço na memória, pois o `&` foi utilizado.

## Ponteiro
Uma variável do tipo ponteiro é utilizada para guardar um endereço de memória, ela é caracterizada pelo `*`.
- Ponteiros são sempre inicializados com o valor `0` ou `NULL`
- Antes de serem utilizadas, um valor tem que ser atribuido a eles

## malloc()
`malloc()` é uma função utilizada para alocar dinâmicamente memória em tempo de execução de programa
```c
int *vetor;
int *v = (int*)malloc(200);
char *c = (char*)malloc(200);

vetor = (int*)malloc(sizeof(int) * 5);
```
- Nesse caso, o malloc está reservando 200 espaços na memória. 

Para liberar espaço na memória, é possível utlizar a função `free(pVar)`


# Tipos de Dados Abstratos
```c
typedef struct Estudante {
 char nome[100];
 int matricula;
 int idade;
} ESTUDANTE;
```

```c
void novoEst(ESTUDANTE *e);
void exibeEst(ESTUDANTE *e);
void novoEst(ESTUDANTE *e) {
 printf("Informe o nome: ");
 gets(e->nome);
 printf("Informe o codigo de matricula: ");
 scanf("%d", &e->matricula);
 printf("Informe a idade: ");
 scanf("%d", &e->idade);
}
void exibeEst(ESTUDANTE *e) {
 printf("%s [%d] %d anos\n", e->nome, e->matricula, e->idade);
}
```
Usando structs, para dados abstratos, não se acessa diretamente eles, mas sim sempre utilizando ponteiros.


___
- [Slides](https://moodle.utfpr.edu.br/pluginfile.php/1003045/mod_resource/content/1/%20Ponteiros-Alocacao-TADS.pdf)
- [Aula](https://drive.google.com/file/d/1kU2ZEH4GZKVxe5X6lhQHU42k8ISA0vlc/view)