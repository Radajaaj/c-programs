#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    int i = 1, j = 1, k = 1, l = 1;
    int con = 0;
    int col = 0;
    int coc = 0;
    int soma = 0;
    int matriza[i][j];
    int matrizb[k][l];
    int matrizc[i][l];

    printf("=======Multiplicador de matrizes=======\n");
    printf("Quantas linhas tem a matriz a?\n");
    scanf("%i", &i);



    printf("\nQuantas colunas tem a matriz a?\n");
    scanf("%i", &j);


    printf("\nQuantas linhas tem a matriz b?\n");
    scanf("%i", &k);


    printf("\nQuantas colunas tem a matriz b?\n");
    scanf("%i", &l);


    if(j == k){
        printf("\n\nA multiplicacao das matrizes a e b e possivel!\nPrencha a matriz a:");

        for(con = 0; con < i; con ++){
            for(col = 0; col < j; col++){
                printf("\nInforme o valor da posicao a %i %i: ", con, col);
                scanf("%i", &matriza[con][col]);
            }
        }

        printf("\n\nPrencha a matriz b:");
        for(con = 0; con < k; con ++){
            for(col = 0; col < l; col++){
                printf("\nInforme o valor da posicao b %i %i: ", con, col);
                scanf("%i", &matrizb[con][col]);
            }
        }

        printf("\n\nA matriz resultante e:\n");

        for(con = 0; con < i; con ++){
            for(col = 0; col < l; col++){
                soma = 0;
                //aqui será selecionado cada coordenada da matriz C, onde C = A + B;
                for(coc = 0; coc < j; coc ++){
                    //aqui ele vai ir somando e multplicando os valores nas matrizes A e B que se relacionam às coordenadas de C;
                    soma = soma + (matriza[con][coc] * matrizb[coc][col]);

                }
                matrizc[con][col] = soma;
            }
        }

        //aqui ele vai mostrar a matriz final

        for(con = 0; con < i; con ++){
            for(col = 0; col < l; col++){
                printf("%i ", matrizc[con][col]);

            }
            printf("\n");
        }

    }else{
        printf("\n\nA multiplicação das matrizes a e b nao e possivel");
    }
    return 0;
}

