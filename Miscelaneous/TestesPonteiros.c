#include<stdio.h>
#include<stdlib.h>

int main(){

//variavel q sera apontada pelo ponteiro
int valor = 27;

//declaraçao do ponteio (o * indica que e um ponteiro)
int *ptr;

//atribuindo o endereço da variavel ao ponteiro
ptr = &valor;

printf("Utilizando ponteiros \n\n");
printf("Conteudo da variavel valor: %d\n", valor);
printf("Endereco da variavel valor: %x\n", &valor);
printf("Conteudo da variavel ponteiro ptr: %x\n", ptr);
printf("Conteudo da variavel para onde o ponteiro ptr aponta: %d\n", *ptr);




system("pause");
}
