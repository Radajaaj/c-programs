#include<stdio.h>
#include<stdlib.h>

int main(){
char nome[100];
char sobrenome[100];
char fullname[100];

printf("Whats your name?\n");
scanf("%[^t] %s", &nome, &sobrenome);
printf("\nYour name is %s", &nome);
printf("\nYour surname is %s", &sobrenome);
fflush(stdin);

printf("\n\nNow tell me your complete name\n");
gets(fullname);
fflush(stdin);
printf("\nYour complete name is %s", &fullname);








return 0;
}
