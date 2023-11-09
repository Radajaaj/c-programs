#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main(){
    int num1, num2, sum, sub, div, mult;

    printf("===============================\n");
    printf("==Super Calculadora Algébrica==\n");
    printf("===============================\n");

    printf("\nPrimeiramente, informe 2 numeros:\n R: ");
    scanf("%i", &num1);
    printf(" R: ");
    scanf("%i", &num2);

    sum = num1 + num2;
    sub = num1 - num2;
    div = num1 / num2;
    mult = num1 * num2;

    printf("\nSum: %i, Sub: %i, Div: %i, Mult: %i\n", sum, sub, div, mult);
    return 0;
}
