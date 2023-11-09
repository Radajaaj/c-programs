#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//MDC finder
int main(){

    int num[2];
    int i, j, k, mdc = 1, primo;

    printf("=======Calculadora de maximo divisor comum=======\nInforme 2 numeros inteiros:\n");
    scanf("%i", &num[1]);

    scanf("%i", &num[2]);

    //num[0] => o maior dos 2 numeros;

    if(num[1] > num[2]){
        num[0] = num[1];
    }else{
        num[0] = num[2];
    }

    for(i = 1; (i < num[0]); i++){
      primo = 0;
        for(j = 1; j < ((num[0]) - 1); j++){
            //detector de num primo, se primo == 2 entao 'i' eh primo
            if(i % j == 0){
                primo = primo + 1;
            }
        }


            if(primo == 2){


                printf("%i e primo\n", i);

                if(num[1] % i == 0 && num[2] % i == 0){
                    num[1] = num[1] / i;
                    num[2] = num[2] / i;
                    mdc = (mdc * i);
                    printf("did");
                    //caso ambos os numeros forem divisiveis pelo numero primo selecionado,
                    //os dois numeros serao divididos por ele, e o mdc ira se multiplicar
                    //pelo numero primo
                }

                for(k = 0; k < 50; k++){
                    if((num[1] % i) == 0 || (num[2] % i) == 0){
                        if(num[1] % i == 0){
                            num[1] = (num[1] / i);
                            printf("Feito1\n");
                        }
                        if(num[2] % i == 0){
                            num[2] = (num[2] / i);
                            printf("Feito2\n");
                        }
                        //dentro deste for, os numeros 1 e 2 serao divididos pelo prim quatas vezes forem necessarias.

                    printf("Feito\n");
                }
            }
        }
        //Depois disso o mdc deveria estar pronto.
        primo = 0;
    }

    printf("O MDC dos numeros e %i!", mdc);

    return 0;

}
