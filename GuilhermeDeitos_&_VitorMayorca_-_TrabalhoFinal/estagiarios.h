void analiseestagiario(){
    int op = 42;
    do{
        system("cls");
        string cpf;
        cout << "Qual o cpf do estagiario que voce deseja checar?\n-R: ";
        cin.ignore();
        getline(cin, cpf);
        dadosestagiario(cpf);
        cout << "\n\n=-= Deseja continuar analisando estagiarios?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void dadosestagiario(string cpf){
    cpf = cpf;
    string temp;
    cpf = cpf;
    for(long long unsigned int r = 0; r < Estagiarios.size(); r++){
        if(cpf == Estagiarios[r].getCpf()){
            cout << "\n\nCPF eh " << Estagiarios[r].getCpf();
            cout << "\nNome eh " << Estagiarios[r].getNome();
            cout << "\nCarga mensal eh " << Estagiarios[r].getCargaHorariaMensal();
            cout << "\nHoras trabalhadas eh " << Estagiarios[r].getQtdHorasTrabalhadas();
            cout << "\nMatricula eh " << Estagiarios[r].getMatricula();
            cout << "\nSalario eh " << Estagiarios[r].getSalario();
            cout << "\nSalario base eh " << Estagiarios[r].getSalarioBase();
            cout << "\nTempo de contrato restante eh " <<Estagiarios[r].getTempoDeContratoRestante();
            if(Estagiarios[r].getTipoEstagiario() == 1){
                cout << "\nTipo de estagio: 1, Jovem Aprendiz";
            }else{
                cout << "\nTipo de estagio: 2, Universitario";
            }
            cout << "\nBonus eh " << Estagiarios[r].calculaBonus();
            sleep_for(3000ms);
        }
    }
}

void alterafuncionarios(){
    int op = 99, func = 0;
    do{
        func = 0;
        system("cls");
        do{
            cout << "=-=-= Que tipo de funcionario voce deseja alterar?\n1 - Gerente, 2 - Normal, 3 - Estagiario\n-R: ";
            cin >> func;
            switch(func){
                case 1:
                    escolhe_altera_gerente();
                break;
                case 2:
                    escolhe_altera_normal();
                break;
                case 3:
                    escolhe_altera_estagiario();
                break;
                default:
                    cout << "\n-=- Opcao invalida!";
                break;
            }
        }while(!(func == 1 || func == 2 || func == 3));
        system("cls");
        cout << "\n=-= Deseja continuar alterando funcionarios?\n1 - Sim, 0 - Nao\n-R: ";
        cin >> op;
    }while(op != 0);
}

void escolhe_altera_estagiario(){
    int op = 42;
    int alt;
    string cpf;
    do{
        system("cls");
        cout << "Voce quer adicionar novos estagiarios, ou alterar os dados de um existente?\n1 - Novo, 2 - Alterar\n-R: ";
        cin >> alt;
        switch(alt){
            case 1:
                novoestagiario();
            break;
            case 2:
                cout << "Qual o cpf do estagiario que voce deseja alterar?\n-R: ";
                cin.ignore();
                getline(cin, cpf);
                alteraestagiario(cpf);
            break;
            default:
                cout << "\n-=- Opcao invalida!\n" << endl; 
            break;
        }

        cout << "\n\n=-= Deseja continuar alterando estagiarios?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);


}

void novoestagiario(){
    Estagiario novo;
    string temp;
    int tp;
    float sal;
    //cpf endereco nome telefone all string
    system("cls");
    cout << "=-= Insira o nome do estagiario (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novo.setNome(temp);//
    cout << "=-= Insira o CPF do estagiario (string)\n-R: ";
    getline(cin, temp);
    novo.setCpf(temp);//
    cout << "=-= Insira a matricula do estagiario (string)\n-R: ";
    getline(cin, temp);
    novo.setMatricula(temp);//
    cout << "=-= Insira a carga horaria mensal (int)\n-R: ";
    cin >> tp;
    novo.setCargaHorariaMensal(tp);//
    cout << "=-= Insira o tempo de contrato restante (int)\n-R: ";
    cin >> tp;
    novo.setTempoDeContratoRestante(tp);//

    do{
        tp = 0;
        cout << "=-= Insira o tipo de contrato (int) (1 - Jovem Aprendiz, 2 - Universitario)\n-R: ";
        cin >> tp;
        novo.setTipoEstagiario(tp);//
    }while(!(tp == 1 || tp == 2));

    cout << "=-= Insira quantas horas ele ja trabalhou (float)\n-R: ";
    cin >> sal;
    novo.setQtdHorasTrabalhadas(sal);//
    cout << "=-= Insira o salario (float)\n-R: ";
    cin >> sal;
    novo.setSalario(sal);//
    cout << "=-= Insira o salario base (float)\n-R: ";
    cin >> sal;
    novo.setSalarioBase(sal);//

    Estagiarios.push_back(novo);

}

void alteraestagiario(string cpf){
    int op, numero;
    float tp;
    string temp;
    for(long long unsigned int r = 0; r < Estagiarios.size(); r++){
        if(cpf == Estagiarios[r].getCpf()){
            do{
                cout << "=-= Qual informacao voce deseja alterar?\n1 - Nome, 2 - CPF, 3 - Matricula, 4 - Carga Horaria, 5 - Horas trabalhadas, 6 - Salario, 7 - Salario base, 8 - Tempo restante, 9 - Tipo de estagio, 0 - Voltar\n-R: ";
                cin >> op;
                switch(op){
                    case 1:
                        cout << "= Novo nome? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Estagiarios[r].setNome(temp);
                    break;
                    case 2:
                        cout << "= Novo CPF? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Estagiarios[r].setCpf(temp);
                    break;
                    case 3:
                        cout << "=Nova matricula? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Estagiarios[r].setMatricula(temp);
                    break;
                    case 4:
                        cout << "=Nova carga horaria? (int)\n-R: ";
                        cin >> numero;
                        Estagiarios[r].setCargaHorariaMensal(numero);
                    break;
                    case 5:
                        cout << "=Novo horas trabalhadas? (float)\n-R: ";
                        cin >> tp;
                        Estagiarios[r].setQtdHorasTrabalhadas(tp);
                    break;
                    case 6:
                        cout << "=Novo salario? (float)\n-R: ";
                        cin >> tp;
                        Estagiarios[r].setSalario(tp);
                    break;
                    case 7:
                        cout << "=Novo salario base? (float)\n-R: ";
                        cin >> tp;
                        Estagiarios[r].setSalarioBase(tp);
                    break;
                    case 8:
                        cout << "=Nova tempo restante? (int)\n-R: ";
                        cin >> numero;
                        Estagiarios[r].setTempoDeContratoRestante(numero);
                    break;
                    case 9:
                        cout << "=Nova tipo de estagio? (int)\n-R: ";
                        cin >> numero;
                        Estagiarios[r].setTipoEstagiario(numero);
                    break;
                    case 0:

                    break;
                    default:
                        cout << "-=- Opcao invalida!! -=-" << endl;
                    break;
                }
            }while(op != 0);
        }
    }
}