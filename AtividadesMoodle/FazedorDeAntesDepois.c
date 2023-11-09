#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main(){
    int num;

    printf("==================================\n");
    printf("==Super Calculadora Antes-Depois==\n");
    printf("==================================\n");

    printf("\nDigite um número:\nR: ");
    scanf("%i", &num);

    printf("%i - 1 = %i.\n%i + 1 = %i.", num, num - 1, num, num + 1);



    return 0;
}
