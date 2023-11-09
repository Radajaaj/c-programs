#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>

int ex1(){
    //Faça um programa que lê um número N e sorteia N números inteiros 
    //(entre 0 e 100), gravando todos em um arquivo texto (randômico.txt). 
    //A primeira linha do arquivo deverá conter a quantidade de números,
    //e os números gravados deverão ser separados por virgula.
    FILE *ptr = NULL;
    int N, i;

    system("cls");
    printf("\n==== Exercicio 1! ====\n");
    printf("Insira um numero N. Serao sorteados N numeros inteiros, que serao gravados dentro de 'randomico.txt'.\n");
    printf("A primeira linha contera a quantidade de números, e os numeros gravados serao separados por virgula.\nN: ");
    scanf("%i", &N); //Insere a variavel N

    ptr = fopen("randomico.txt", "w"); //Sobrescreve o "randomico.txt" antigo, e cria um novo
    fprintf(ptr, "%i\n", N);  // Escreve N na primeira linha, e pula para a segunda
    fclose(ptr);

    ptr = NULL; //Reseta o ponteiro ptr, por precaução

    ptr = fopen("randomico.txt", "a"); //Abre o arquivo no modo append, para adicionar os numeros aleatorios

    if(ptr == NULL){
        perror("\n=-= ERRO ABRINDO O ARQUIVO! =-=\n");
        return(-1);
    }

    for(i = 0; i < N - 1; i++){
        srand(time(NULL) * i); //Cria uma semente para a geração de numeros aleatorios, usando o tempo atual vezes a variavel i

        fprintf(ptr, "%i, ", rand() % 101);
    }
    fprintf(ptr, "%i", rand() % 101); // Gera o ultimo numero. Ele é gerado separado para que não tenha uma vírgula do lado dele

    fclose(ptr);
}

void ex522(){
    FILE *ptr;
    ptr = fopen("alunos.txt", "a");
    int op = 0;
    
    while(op != 2){
        system("cls");
        printf("=-= O que deseja fazer?\n[1] Cadastrar novo aluno(a)\n[2] Sair\n-R: ");
        scanf("%i", &op);
        fflush(stdin);
        char nome[50];
        float med, n1, n2;


        switch(op){
            case 1:
            printf("\n=-= Nome?\nR: ");
            gets(nome);
            fflush(stdin);

            printf("\n=-= Nota 1?\nR: ");
            scanf("%f", &n1);

            printf("\n=-= Nota 2?\nR: ");
            scanf("%f", &n2);

            med = ((n1 + n2) / 2);

            fprintf(ptr, "Aluno: %s\nNota 1: %.2f\tNota 2: %.2f\tMedia: %.2f\n", nome, n1, n2, med);
            if(med >= 70){
                fprintf(ptr, "APROVADO\n\n");
            }else{
                fprintf(ptr, "REPROVADO\n\n");
            }

            break;

            case 2:
            printf("\n=-= Tchau!");
            Sleep(500);
            break;

            default:
            printf("\n\n-=- Opcao Invalida!");
            Sleep(1200);
        }
    
    }

    fclose(ptr);
}

int ex523(){
    //Faça um programa que leia o arquivo “vogais.txt” e mostre na tela 
    //quantas letras são vogais e quantas são consoantes.
    system("cls");
    FILE *ptr = NULL;
    ptr = fopen("vogais.txt", "r");
    char c;
    int vo = 0, co = vo, ou = co;

    if(ptr == NULL){
        perror("\n=-= ERRO ABRINDO O ARQUIVO! =-=\n");
        return(-1);
    }  

    printf("\n\n=--= Aquivo lido:\n");

    while(!feof(ptr)){
        while((c = getc(ptr)) != '\n' && !feof(ptr)){
            printf("%c", c);
            if(!isalpha(c)){
                ou = ou + 1;
            }else if(toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U'){
                vo = vo + 1;
            }else{
                co = co + 1;
            }
        }
    }
    
    printf("\n\n=-= Numero de vogais: %i\n=-= Numero de consoantes: %i\n=-= Outros: %i", vo, co, ou);

    printf("\n\n");
    fclose(ptr);
    Sleep(3500);
}

void ex7(){
//Faça um programa que leia o conteúdo de um arquivo e crie um arquivo com o mesmo conteúdo, 
//mas com todas as letras minúsculas convertidas para maiúsculas. 
//Os nomes dos arquivos serão fornecidos, via teclado, pelo usuário.
    system("cls");

    char arq[50], nome[50], c;
    FILE *orig = NULL, *cop = NULL;
    
    do{//Checa se o arquivo existe
        printf("\n\n=-= Qual arquivo voce deseja copiar? (.txt)\nR: ");
        fflush(stdin);
        gets(arq);
        fflush(stdin);

        orig = fopen(arq,  "r");

        if(orig == NULL){
            printf("\n\nERRO! Aquivo invalido!\n\n");
        }
    }while(orig == NULL);
    
    printf("\nQual sera o nome da copia? (.txt)\nR: ");
    fflush(stdin);
    gets(nome);
    fflush(stdin);

    cop = fopen(nome, "w");

    while(!feof(orig)){
        c = getc(orig);
        if(isalpha(c) && c != '\n'){
            c = toupper(c);
        }

        if(c != EOF){
            fprintf(cop, "%c", c);
        }
        
    }
    fclose(orig);
    fclose(cop);

}

void ex8(){
//Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo 
//com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).
system("cls");

    char arq1[50], arq2[50], junt[50], c;
    FILE *orig1 = NULL, *orig2 = NULL, *new = NULL;
    
    do{//Checa se o arquivo existe
        printf("\n\n=-= Qual o nome do arquivo 1? (.txt)\nR: ");
        fflush(stdin);
        gets(arq1);
        fflush(stdin);

        orig1 = fopen(arq1, "r");

        if(orig1 == NULL){
            printf("\n\nERRO! Aquivo invalido! \n\n");
        }
    }while(orig1 == NULL);

    do{//Checa se o arquivo existe
        printf("\n\n=-= Qual o nome do arquivo 2? (.txt)\nR: ");
        fflush(stdin);
        gets(arq2);
        fflush(stdin);

        orig2 = fopen(arq2, "r");

        if(orig2 == NULL){
            printf("\n\nERRO! Aquivo invalido!\n\n");
        }
    }while(orig2 == NULL);
    
    printf("\n=-= Qual sera o nome do novo arquivo? (.txt)\nR: ");
    fflush(stdin);
    gets(junt);
    fflush(stdin);

    new = fopen(junt, "w");

    while(!feof(orig1)){
        c = getc(orig1);
        if(c != EOF){
            fprintf(new, "%c", c);
        }  
    }
    fprintf(new, "\n");
    while(!feof(orig2)){
        c = getc(orig2);
        if(c != EOF){
            fprintf(new, "%c", c);
        }  
    }

    fclose(orig1);
    fclose(orig2);
    fclose(new);
}