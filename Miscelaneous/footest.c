#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int res;
    int i = 1;

    struct biblioteca{
        char nome[50];
        int ano;
        char autor[50];
    }livro[i];

    while(res != 3){
        printf("Selecione uma opcao:\n 1 Adicionar um livro\n 2 Ver livros cadastrados\n 3 Fechar Programa\n");
        scanf("%i", &res);

        switch(res){
        case 1:
            i = i + 1;


            printf("\nAno de publicacao?\n");
            scanf("%i", livro[i-1].ano);
            fflush(stdin);

            printf("\nNome do livro?\n");
            gets(livro[i-1].nome);
            fflush(stdin);



            printf("\nNome do autor?\n");
            gets(livro[i-1].autor);
            fflush(stdin);


            break;

        case 2:



            break;

        case 3:



            break;
        }
    }
}

