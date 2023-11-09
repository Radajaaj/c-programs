#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float pi = 3.141592;

void ex1(){
    //Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
    //Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros. 
    //Imprima os valores das variáveis antes e após a modificação
    int a = 12, *in;
    float b = 1.2, *fl;
    char c = 'm', *ch;

    in = &a;
    fl = &b;
    ch = &c;

    printf("\n\nVariaveis: %s\nValor: %i", getName(a), a);
    printf("\n\nVariaveis: %s\nValor: %f", getName(b), b);
    printf("\n\nVariaveis: %s\nValor: %c", getName(c), c);

    *in = 21;
    *fl = 2.1;
    *ch = 'n';
       
    printf("\n\nVariaveis: %s\nValor: %i", getName(a), a);
    printf("\n\nVariaveis: %s\nValor: %f", getName(b), b);
    printf("\n\nVariaveis: %s\nValor: %c\n\n", getName(c), c);
}

void ex2(){
    //Escreva um programa que contenha duas variáveis inteiras.
    //Compare seus endereços e exiba o maior endereço.
    int a = 1, b = 2;
    printf("\nEndereco de %s = %x. Endereco de %s = %x\n", getName(a), &a, getName(b), &b);
    if(&a > &b){
        printf("\nEndereco de %s eh maior! ele eh %x\n\n", getName(a), &a);
    }else{
        printf("\nEndereco de %s eh maior! ele eh %x\n\n", getName(b), &b);
    }
}

void ex3(){
    //Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado.
    //Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
    int a, b;
    printf("\nInforme o valor da var %s\n", getName(a));
    scanf("%i", &a);
    printf("\nO endereco de %s eh %x", getName(a), &a);

    printf("\nInforme o valor da var %s\n", getName(b));
    scanf("%i", &b);
    printf("\nO endereco de %s eh %x", getName(b), &b);

    if(&a > &b){
        printf("\nEndereco %x eh maior!", &a);
    }else{
        printf("\nEndereco %x eh maior!", &b);
    }
}

void ex4pont(int *a, int *b, int c){
    *a = *b;
    *b = c;
}
void ex4(){
    //Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis
    //e troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo 
    //e, após a execução da função, A conterá o valor de B e B terá o valor de A.
    int a, b, *pa, *pb;

    printf("\nInsira o valor de A\n");
    scanf("%i", &a);

    printf("\nInsira o valor de B\n");
    scanf("%i", &b);

    pa = &a;
    pb = &b;

    ex4pont(pa, pb, a);

    printf("\n\nOs novo valor de A eh %i, e de B eg %i!\n", a, b);
}

void ex5pont(int *a, int *b, int c){
    if(*b > *a){
        *a = *b;
        *b = c;
    }
}
void ex5(){
//Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada
//e retorne o maior valor na primeira variável e o menor valor na segunda variável. 
//Escreva o conteúdo das 2 variáveis na tela.
    int a, b, *pa, *pb;

    printf("\nInsira o valor de A\n");
    scanf("%i", &a);

    printf("\nInsira o valor de B\n");
    scanf("%i", &b);

    pa = &a;
    pb = &b;

    ex5pont(pa, pb, a);

    if(a == b){
        printf("\n\nAmbas as variaveis sao iguais!\n");
    }else{
        printf("\n\nA ordem eh A %i e B %i!\n", a, b);
    }
}

int ex6pont(int *a, int*b){
    *a = 2 * (*a);
    *b = 2 * (*b);

    return ((*a) + (*b));
}
void ex6(){
    //Elaborar um programa que leia dois valores inteiros (A e B). 
    //Em seguida faça uma função que retorne a soma do dobro dos dois números lidos. 
    //A função deverá armazenar o dobro de A na própria variável A e o dobro de B na própria variável B.
    int a = 0, b = 0, soma = 0;

    printf("\n\nInforme os valores de A e B, respectivamente:\n");
    scanf("%i %i", &a, &b);
    soma = ex6pont(&a, &b);
    printf("\n\nA eh %i, B eh %i e a soma eh %i\n\n", a, b, soma);
}

void ex7pont(int a, int b, int *c){
    *c = a + b;
}
void ex7(){
    //Crie um programa que contenha uma função que permita passar por parâmetro dois números inteiros A e B.
    //A função deverá calcular a soma entre estes dois números e armazenar o resultado na variável A.
    //Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro parâmetro.
    //Imprima os valores de A e B na função principal.
    int A, B;
    printf("\n\nDefina os valores de A e B, respectivamente:\n");
    scanf("%i %i", &A, &B);
    ex7pont(A, B, &A);
    printf("\nValores finais: A = %i, B = %i\n\n", A, B);
}

int ex8pont(int i, int *b){
    int soma = 0, j, k, l;
    
    for(j = 0; j < i; j++){
        soma = soma + *(b + j);
        //essa soma depois vai virar uma media dos elementos do vetor, pra saber se eles sao iguais
        for(k = j + 1; k < i; k++){
            if(*(b + j) > *(b + k)){
                l = *(b + j);
                *(b + j) = *(b + k);
                *(b + k) = l;
            }
        }
    }
    if((soma / i) == *b){
        return 1;
    }else{
        return 0;
    }
    //for(j = 0; j < i; j++){
    //    *(b + j) = 0;
    //}
}
void ex8(){
    //Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de
    //entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável, o segundo menor 
    //valor na variável do meio e o maior valor na última variável. 
    //A função deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes.
    //Exibir os valores ordenados na tela.
    int i = 0, j, r;

    printf("\n\nQuantos valores voce quer inserir?\nR: ");
    scanf("%i", &i);
    int a[i];

    for(j = 0; j < i; j++){
        printf("\nQual o valor do numero %i?\nR: ", j + 1);
        scanf("%i", &a[j]);
        fflush(stdin);
    }
    
    for(j = 0; j < i; j++){
        printf(" %i ", a[j]);
    }

    printf("\n\n");

    r = ex8pont(i, &a[0]);

    if(r == 1){
        printf("\nTodos os valores sao iguais!\n\n");
    }else{
        printf("\nOs numeros sao diferentes!\n\n");
    }
    
    for(j = 0; j < i; j++){
        printf(" %i ", a[j]);
    }
    printf("\n\n");
}

void ex9pont(float nu, int *in, float *fl){

*in = (int)nu;
*fl = nu - *in;

}
void ex9(){
    //Escreva uma função que dado um número real passado como parâmetro,
    //retorne a parte inteira e a parte fracionária deste número.
    //Escreva um programa que chama esta função.
    //Protótipo: void frac(float num, int* inteiro, float* frac);
    int inteiro = 0;
    float num = 0.0, frac = 0.0;

    printf("\n\nInforme um numero real!\nR: ");
    scanf("%f", &num);

    ex9pont(num, &inteiro, &frac);

    printf("\nA parte inteira de %f eh %i e a parte fracionaria eh %f!\n", num, inteiro, frac);
}

void ex10(){
    //Considere a seguinte declaração: int A, *B, **C, ***D;
    //Escreva um programa que leia a variável A e calcule e exiba o dobro,
    //O triplo e o quádruplo desse valor utilizando apenas os ponteiros B, C e D.
    //O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quádruplo
    int A, *B, **C, ***D;

    B = &A;
    C = &B;
    D = &C;

    printf("\n\nInforme a variavel A\nR: ");
    scanf("%i", &A);

    printf("\n\nO dobro de %i eh %i, o seu triplo eh %i e o seu quadruplo eh %i!\n\n", A, 2 * (*B), 3 * (**C), 4 * (***D));
}

void calc_esfera(float R, float *area, float *volume){
    *area = 4.0 * pi * R * R;
    *volume = (4.0 / 3.0) * pi * R * R * R;

}
void ex11(){
    // Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R.
    //Essa função deve obedecer ao protótipo: void calc_esfera(float R, float *area, float *volume)
    //A área da superfície e o volume são dados, respectivamente, por: A = 4 * pi * R2 V = 4/3 * pi * R3
    float raio = 0.1, area = 0.0, volume = 0.0;
    //printf(" %f %f %f ", raio, area, volume);
    printf("\n\n=--=-==-=--=Calculadora da Esfera!=--=-==-=--=\n\nInsira o raio\nR: ");
    scanf("%f", &raio);
    //printf(" %f %f %f ", raio, area, volume);

    calc_esfera(raio, &area, &volume);

    printf("\n\nA area da superficie eh %f, e o volume eh %f!\n\n", area, volume);
}

void ex12f2(float *n1, float *n2, float *ms, float *mp){
    *ms = (*n1 + *n2) / 2;
    *mp = (((*n1) + (2 * (*n2))) / 3);
}
void ex12f1(float *n1, float *n2){
    do{
        printf("\n\nInforme as notas 1 e 2, respectivamente:\n");
        scanf("%f %f", &*n1, &*n2);

        if(*n1 > 100 || *n1 < 0 || *n2 > 100 || *n2 < 0){
            printf("\nInput invalido!");
        }
    }while(*n1 > 100 || *n1 < 0 || *n2 > 100 || *n2 < 0);
}
void ex12(){
    // Faça um programa que possua uma função para ler 2 notas e retorná-las por parâmetro
    //(chamar uma função dedicada a ler 2 notas válidas e devolver os 2 números lidos);
    //calcular a média simples e a média ponderada e retorná-las por parâmetro,
    //onde a segunda nota tem peso 2 media ponderada = (n1 + n2 _ 2)=3;
    float n1 = 0.0, n2 = 0.0, ms = 0.0, mp = 0.0;
    ex12f1(&n1, &n2);
    printf("\nAs notas sao: 1- %f 2- %f!\n", n1, n2);
    ex12f2(&n1, &n2, &ms, &mp);

    printf("\nA media simples eh %f!\nE a ponderada eh %f!\n\n", ms, mp);
}

int raizes(float A,float B,float C,float * X1,float * X2){
    int delta;
    delta = (B * B) - (4 * A * C);

    if(delta < 0){
        printf("\nA sua equacao nao possui raizes reais!\n");
        return 0;
    }else{
        delta = sqrt(delta);
        *X1 = (-B + delta) / (2 * A);
        *X2 = (-B - delta) / (2 * A);
    }
    if(*X1 == *X2){
        printf("\nA equacao so possui uma raiz! ela eh %f!\n\n", *X1);
        return 1;
    }else{
        printf("\nA equacao possui duas raizes! elas sao %f e %f!\n\n", *X1, *X2);
        return 2;
    }


}
void ex13(){
    float A = 0, B, C, X1, X2, num;
    printf("\n\n===---=---===Calculadora Quadratica!===---=---===\n\n");

    while(A == 0){
        printf("Informe o valor de A\nR: ");
        scanf("%f", &A);

        if(A == 0){
            printf("\n\nInput invalido! A precisa ser diferente de 0!\n\n");
        }
    }
    
    printf("\nInforme o valor de B\nR: ");
    scanf("%f", &B);

    printf("\nInforme o valor de C\nR: ");
    scanf("%f", &C);

    num = raizes(A, B, C, &X1, &X2);

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

        case 10:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex10();
        break;

        case 11:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex11();
        break;

        case 12:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex12();
        break;

        case 13:
        printf("\n\n\n\n-=--=-Executando ... exercicio %i!-=--=-\n\n\n\n", e);
            ex13();
        break;

        default:
        printf("\nOpcao invalida!\n");
        break;
    }
}

void exercicio(){
    int resp = 0, ex = 0;

    while(resp != 2){
        printf("1) Escolha um exercicio\n2) Voltar\nR: ");
        
        scanf("%i", &resp);
        switch(resp){
            case 1:
                printf("\nQual exercicio voce deseja analisar?\nR: ");
                scanf("%i", &ex);
                selecionador(ex);
                //Núm do exercicio escolhido pelo usuario é enviado pro selecionador, que vai executar o exercício 
            break;

            case 2:
                printf("\n=-=Voltar!=-=\n\n");
            break;

            default:
                printf("\n\n=---=Opcao invalida!=---=\n\n");
            break;
        }
    }
}