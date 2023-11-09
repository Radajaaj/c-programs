#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <string>

#include "classes.h"
#include "clientes.h"
#include "funcionarios.h"
#include "gerentes.h"
#include "empresas.h"
#include "estagiarios.h"

int main(){
    int lupe = 99;
    
    inicio();
    do{
        system("cls");
        cout << "\n\n\n\n==-===------=====---==---=====------===-==" << endl;
        cout << "=-= Boas-Vindas ao Sistema da Empresa! =-=" << endl;
        cout << "==-===------=====---==---=====------===-==\n" << endl;
        cout << "=--= O que voce deseja fazer?\n[1] Obter informacoes de funcionarios\n[2] Adicionar / alterar funcionarios\n[3] Obter informacoes de clientes\n[4] Adicionar / alterar clientes\n[5] Obter informacoes da empresa\n[6] Adicionar / alterar empresa\n[0] Sair\n\n-R: ";
        cin >> lupe;

        switch(lupe){
            case 1:
                obter_funcionarios(); //Feito
            break;
            case 2:
                alterafuncionarios(); //Feito
            break;
            case 3:
                obter_clientes(); //Feito
            break;
            case 4:
                alterar_clientes(); //Feito
            break;
            case 5:
                obter_empresa(); //Feito
            break;
            case 6:
                alterar_empresa(); //Feito
            break;

            case 0:
                cout << "\n=--= Tchau! =--=\n\n";
                sleep_for(1200ms);
            break;
            default:
                cout << "\n-=- Opcao invalida! Tente de novo...";
                sleep_for(1200ms);
            break;
        }
    }while(lupe != 0);

    return 0;
}































































void obter_funcionarios(){
    int op = 99, func = 0;
    do{
        func = 0;
        system("cls");
        do{
            cout << "=-=-= Que tipo de funcionario voce deseja checar?\n1 - Gerente, 2 - Normal, 3 - Estagiario\n-R: ";
            cin >> func;
            switch(func){
                case 1:
                    analisegerente();
                break;
                case 2:
                    analisenormal();
                break;
                case 3:
                    analiseestagiario();
                break;
                default:
                    cout << "\n-=- Opcao invalida!";
                break;
            }
        }while(!(func == 1 || func == 2 || func == 3));
        system("cls");
        cout << "\n=-= Deseja continuar checando funcionarios?\n1 - Sim, 0 - Nao\n-R: ";
        cin >> op;
    }while(op != 0);
}








