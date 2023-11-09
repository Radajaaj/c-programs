#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include"arquivos.h"

int main(){
    int op = 0;

    do{
        op = 0;
        system("cls");
        printf("\n=========================================");
        printf("\n=========== Lista de Arquivos ===========");
        printf("\n=========================================");
        printf("\n\n=== Qual exercicio voce deseja executar?\n\n[0] Lista 22, ex 1\n[1] Lista 22, ex 5\n[2] Lista 23, ex 5\n[3] Lista 23, ex 7\n[4] Lista 23, ex 8\n[5] Sair\n-R: ");
        scanf("%i", &op);

        switch(op){
            case 0:
            ex1();
            break;

            case 1:
            ex522();
            break;

            case 2:
            ex523();
            break;

            case 3:
            ex7();
            break;

            case 4:
            ex8();
            break;

            case 5:
            printf("\n\n=== Tchau! ===\n");
            break;

            default:
            printf("\n\n=== Opcao Invalida! ===\n");
            Sleep(600);
            break;
        }

    }while(op != 5);

    return 0;
}