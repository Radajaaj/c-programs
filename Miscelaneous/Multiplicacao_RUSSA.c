#include<stdio.h>
#include<stdlib.h>

int main(){

int mult[2], cont;

printf("====================================\n");
printf("==Calculadora Multiplicacao Russa!==\n");
printf("====================================\n");

printf("\nPrimeiramente, informe os numeros naturais que serao multiplicados.\na: ");
scanf("%i", &mult[0]);
printf("b: ");
scanf("%i", &mult[1]);

if(mult[0] % 2 != 0){
    printf("\na eh impar\n");
    mult[2] = mult[1];
}else{
    mult[2] = 0;
}

if(mult[0] == 0 || mult[1] == 0){
    mult[0] = 1;
    mult[2] = 0;
}else{
    do{
        mult[0] = mult[0] / 2;
        mult[1] = mult[1] * 2;

        if(mult[0] % 2 != 0){
            mult[2] = mult[2] + mult[1];
        }
    }while(mult[0] != 1 && mult[0] != 0);
}

printf("\n\nO resultado da sua multiplicacao e %i !!", mult[2]);
return mult[2];
}
