#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float pi = 3.141592;

void ex1(){
    typedef struct{
        char nome[50];
        char curso[100];
        int matricula;
    }aluno;
    aluno a[5];
    for(int c = 0; c < 5; c++){
        fflush(stdin);
        printf("Nome do aluno?\nR: ");
        gets(a[c].nome);
        fflush(stdin);

        printf("\nCurso do aluno?\nR: ");
        gets(a[c].curso);
        fflush(stdin);

        printf("\nNumero de matricula?\nR: ");
        scanf("%i", &a[c].matricula);
        fflush(stdin);
    }

    for(int c = 0; c < 5; c++){
        printf("\nNome do aluno %i: %s", c + 1, a[c].nome);
        
        printf("\nCurso do aluno %i: %s", c + 1, a[c].curso);

        printf("\nNumero de matricula %i: %i", c + 1, a[c].matricula);
    }
}

void ex2(){
    struct funcionario{
        char nome[100];
        int idade;
        char sexo;
        int cpf;
        char nascimento[30];
        int codigo;
        char cargo[30];
        float salario;
    }funcionario;
    printf("\nNome?\nR: ");
    gets(funcionario.nome);
    fflush(stdin);

    printf("\nIdade?\nR: ");
    scanf("%i", &funcionario.idade);
    fflush(stdin);

    printf("\nSexo?\nR: ");
    scanf("%c", &funcionario.sexo);
    fflush(stdin);

    printf("\nCPF?\nR: ");
    scanf("%i", &funcionario.cpf);
    fflush(stdin);

    printf("\nNascimento?\nR: ");
    gets(funcionario.nascimento);
    fflush(stdin);

    printf("\nCodigo do Setor?\nR: ");
    scanf("%i", &funcionario.codigo);
    fflush(stdin);

    printf("\nCargo?\nR: ");
    gets(funcionario.cargo);
    fflush(stdin);

    printf("\nSalario?\nR: ");
    scanf("%f", &funcionario.salario);


    printf("Nome: %s\nIdade: %i\nSexo: %c\nCPF: %i\nNascimento: %s\nCodigo do setor: %i\nCargo: %s\nSalario: %i\n", funcionario.nome, funcionario.idade, funcionario.sexo, funcionario.cpf, funcionario.nascimento, funcionario.codigo, funcionario.codigo, funcionario.salario);



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
    int ex = 0;

    printf("\n\nQual exercicio voce deseja analisar?\nR: ");
    scanf("%i", &ex);
    selecionador(ex);
    //Núm do exercicio escolhido pelo usuario é enviado pro selecionador, que vai executar o exercício 
            
    
}