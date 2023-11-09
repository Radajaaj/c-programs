#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

int variavelglobal;

int somador(int num, int fibba, int fibbo){
    //static int fibbo = 0;
    if(num != 0){
        num--;
        printf("%i ", fibbo);
        somador(num, fibbo, fibba + fibbo);
    }
}

void main(){
    int num;
    printf("\nFibbonaccificador, informe ate onde sera fibbonaciado\nR: ");
    scanf("%i", &num);

    somador(num, 0, 1);
}

