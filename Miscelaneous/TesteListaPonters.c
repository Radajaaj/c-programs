#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int esc = 0;

    while(esc != 2){
        printf("\n\n======================\n==Lista de ponteiros==\n======================");
        printf("\n\nEscolha uma opcao:\n1) Executar algum exercicio;\n2) Fechar o programa.\nR: ");
        scanf("%i", esc);
        printf("debug1");
        switch(esc){
            printf("debug1");
            case 1:

            printf("Exercicio");
            break;

            case 2:
            printf("\nTchau!");
            break;

            default:
            printf("\nOpcao invalida! Tente de novo.");
            break;
        }
    }

    return 0;
}
