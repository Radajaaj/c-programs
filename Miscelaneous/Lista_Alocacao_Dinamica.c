#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define getName(var) #var
#include"lista16.h"

int main(){
    int esc = 0;

    while(esc != 2){
        printf("\n\n=---==-====-==---=-==-===-==---=\n=-=Lista de Alocacao Dinamica=-=\n=---==-====-==---=-==-===-==---=");
        printf("\n\nEscolha uma opcao:\n1) Executar algum exercicio;\n2) Fechar o programa.\nR: ");
        scanf("%i", &esc);
        //escolhe a opção inicial

        switch(esc){
            case 1:
            printf("\nExercicio!\n");
            exercicio();
            //função onde o usuário irá escolher o exercicio a ser executado.
            break;

            case 2:
            //Desliga o programa
            printf("\nTchau!");
            break;

            default:
            //Repete a função, pois o input foi inválido
            printf("\nOpcao invalida! Tente de novo.\n");
            break;
        }
    }
    fflush(stdin);
    return 69;
}