#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;

    x = sizeof(int);
    printf("Tamanho de int = %i\n", x);

    x = sizeof(char);
    printf("Tamanho de char = %i\n", x);

    x = sizeof(float);
    printf("Tamanho de float = %i\n", x);

    x = sizeof(double);
    printf("Tamanho de double = %i\n", x);

    x = sizeof(void);
    printf("Tamanho de void = %i\n", x);

    return x;
}