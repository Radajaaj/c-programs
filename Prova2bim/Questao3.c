#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char nome[100];
    char mail[100];
    char temp[100];
    char esp[0];
    int l;
    strcat(esp, " ");

    printf("Insira seu nome completo:\n");
    gets(nome);
    fflush(stdin);

    temp[0] = nome[0];

    for(l = 1; l < 50; l++){
        if(strcmp(nome[l], esp[0]) == 0){
            //Se o ponto selecionado na string nome for igual a " ", ele irá adicionar a proxima inicial ao email.
            strcat(temp, nome[l+1]);
        }
    }

    strcat(temp, "@unioeste.br");

    printf("O seu novo e-mail e: %s", temp);

}
