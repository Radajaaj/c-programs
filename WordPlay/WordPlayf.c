#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> //adiciona o comando de limpar o teminal no windows
#include<windows.h> // adiciona o comando para aguardar alguns segundos antes de prosseguir com o código
#include"HWordPlayH.h"


int main(){
    int r, tema = 0;
    char letra, palavra[20];

    do{
        //Aqui nós vamos escolher o tema do wordplay, tudo irá se repetir se o usuário escolher um tema inválido
        printf("===============================================================================\n");
        printf("===============================Super Word Play!!===============================\n");
        printf("===============================================================================\n\n");

        printf("\nSeja bem vindo(a) ao Super Word Play!!\nPrimeiramente, escolha um tema:\n\n1)Cores\n2)Futebol\n3)Animais\nR: ");
        scanf("%i", &tema);
        fflush(stdin);

        switch(tema){//Aqui você escolhe o tema do quiz
        case 1 :
            for(r = 0; r < 5; r++){
                strcpy(trivia[r], cores[r]);
                strcpy(dicas[r], coresd[r]);
            }
            break;

        case 2 :
            for(r = 0; r < 5; r++){
                strcpy(trivia[r], futebol[r]);
                strcpy(dicas[r], futebold[r]);
            }
            break;

        case 3 :
            for(r = 0; r < 5; r++){
                strcpy(trivia[r], animais[r]);
                strcpy(dicas[r], animaisd[r]);
            }
            break;

        default:
            printf("\nOpcao invalida!\n");
            Sleep(500);
        }

        limpatela();

    }while(tema != 1 && tema != 2 && tema != 3);

    //debug printf("\nComeca preparacao\n");
    preparacao();
    //debug printf("\nAcaba preparacao\n");


    do{
        r = 0;
        limpatela();//limpam o terminal

        desenhaplacar(errol, errop); //desenha um contador tendo como base o quanto você já errou
        desenhadisplay(); // vai desenhar o jogo no terminal
        r = opcionador(); //vai apresentar as opções de resposta, e receber a escolha do usuário

        switch(r){ // aqui foi escolhida a opção
        case 1 :
            printf("\nInsira sua letra:\nR: ");
            scanf("%c", &letra);
            fflush(stdin);
            tentatival = tentatival + 1; //Usado no placar final
            letrador(letra);
            break;

        case 2 :
            printf("\nInsira a palavra completa, com letras minusculas:\nR: ");
            gets(palavra);
            fflush(stdin);
            tentativap = tentativap + 1; //Usado no placar final
            palavrador(palavra);
            break;

        default :
            printf("\nOpcao invalida!");
            Sleep(500);
            break;
        }
        comparador();

    }while(errol <= 7 && errop <= 1);

    mensagemderrota(errol, errop, tentatival, tentativap);//se o "do while" acima se completar, significa que o usuário estourou o limite de erros, e perdeu

    return 0;
}
