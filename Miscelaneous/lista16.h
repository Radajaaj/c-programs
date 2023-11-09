#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float pi = 3.141592;

void ex1(){


}

void ex2(){


}

void ex3(){


}

void ex4(){


}

void ex5(){


}

void ex6(){


}

void ex7(){


}

void ex8(){


}

void ex9(){


}


void selecionador(int e){
//Recebe o numero escolhido, e executa o exercicio
    switch(e){
        case 1:
            printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex1();
        break;

        case 2:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex2();
        break;

        case 3:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex3();
        break;

        case 4:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex4();
        break;

        case 5:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex5();
        break;

        case 6:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex6();
        break;

        case 7:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex7();
        break;

        case 8:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex8();
        break;

        case 9:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex9();
        break;

        default:
        printf("\nOpcao invalida!\n");
        break;
    }
}

void exercicio(){
    int resp = 0, ex = 0;

    printf("\nQual exercicio voce deseja analisar?\nR: ");
    scanf("%i", &ex);
    selecionador(ex);
    //Núm do exercicio escolhido pelo usuario é enviado pro selecionador, que vai executar o exercício 
            
    
}