void analisenormal(){
    int op = 42;
    do{
        system("cls");
        string cpf;
        cout << "Qual o cpf do funcionario que voce deseja checar?\n-R: ";
        cin.ignore();
        getline(cin, cpf);
        dadosfuncionario(cpf);
        cout << "\n\n=-= Deseja continuar analisando funcionarios normais?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);

}

void dadosfuncionario(string cpf){
    cpf = cpf;
    string temp;
    cpf = cpf;
    for(long long unsigned int r = 0; r < Funcionarios.size(); r++){
        if(cpf == Funcionarios[r].getCpf()){
            cout << "\n\nCPF eh " << Funcionarios[r].getCpf();
            cout << "\nNome eh " << Funcionarios[r].getNome();
            cout << "\nCarga mensal eh " << Funcionarios[r].getCargaHorariaMensal();
            cout << "\nHoras trabalhadas eh " << Funcionarios[r].getQtdHorasTrabalhadas();
            cout << "\nMatricula eh " << Funcionarios[r].getMatricula();
            cout << "\nSalario eh " << Funcionarios[r].getSalario();
            cout << "\nSalario base eh " << Funcionarios[r].getSalarioBase();
            cout << "\nBonus eh " << Funcionarios[r].calculaBonus();
            sleep_for(3000ms);
        }
    }
}

void escolhe_altera_normal(){
    int op = 42;
    int alt;
    string cpf;
    do{
        system("cls");
        cout << "Voce quer adicionar novos funcionarios, ou alterar os dados de um existente?\n1 - Novo, 2 - Alterar\n-R: ";
        cin >> alt;
        switch(alt){
            case 1:
                novonormal();
            break;
            case 2:
                cout << "Qual o cpf do funcionario que voce deseja alterar (string)?\n-R: ";
                cin.ignore();
                getline(cin, cpf);
                alteranormal(cpf);
            break;
            default:
                cout << "\n-=- Opcao invalida!\n" << endl; 
            break;
        }

        cout << "\n\n=-= Deseja continuar alterando funcionarios normais?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void novonormal(){
    Funcionario novo;
    string temp;
    int tp;
    float sal;
    //cpf endereco nome telefone all string
    system("cls");
    cout << "=-= Insira o nome do funcionario (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novo.setNome(temp);//
    cout << "=-= Insira o CPF do funcionario (string)\n-R: ";
    getline(cin, temp);
    novo.setCpf(temp);//
    cout << "=-= Insira a matricula do funcionario (string)\n-R: ";
    getline(cin, temp);
    novo.setMatricula(temp);//
    cout << "=-= Insira a carga horaria mensal (int)\n-R: ";
    cin >> tp;
    novo.setCargaHorariaMensal(tp);//
    cout << "=-= Insira quantas horas ele ja trabalhou (float)\n-R: ";
    cin >> sal;
    novo.setQtdHorasTrabalhadas(sal);//
    cout << "=-= Insira o salario (float)\n-R: ";
    cin >> sal;
    novo.setSalario(sal);//
    cout << "=-= Insira o salario base (float)\n-R: ";
    cin >> sal;
    novo.setSalarioBase(sal);//

    Funcionarios.push_back(novo);
}

void alteranormal(string cpf){
    int op, numero;
    float tp;
    string temp;
    for(long long unsigned int r = 0; r < Funcionarios.size(); r++){
        if(cpf == Funcionarios[r].getCpf()){
            do{
                cout << "=-= Qual informacao voce deseja alterar?\n1 - Nome, 2 - CPF, 3 - Matricula, 4 - Carga Horaria, 5 - Horas trabalhadas, 6 - Salario, 7 - Salario base, 0 - Voltar\n-R: ";
                cin >> op;
                switch(op){
                    case 1:
                        cout << "= Novo nome? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Funcionarios[r].setNome(temp);
                    break;
                    case 2:
                        cout << "= Novo CPF? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Funcionarios[r].setCpf(temp);
                    break;
                    case 3:
                        cout << "=Nova matricula? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Funcionarios[r].setMatricula(temp);
                    break;
                    case 4:
                        cout << "=Nova carga horaria? (int)\n-R: ";
                        cin >> numero;
                        Funcionarios[r].setCargaHorariaMensal(numero);
                    break;
                    case 5:
                        cout << "=Novo horas trabalhadas? (float)\n-R: ";
                        cin >> tp;
                        Funcionarios[r].setQtdHorasTrabalhadas(tp);
                    break;
                    case 6:
                        cout << "=Novo salario? (float)\n-R: ";
                        cin >> tp;
                        Funcionarios[r].setSalario(tp);
                    break;
                    case 7:
                        cout << "=Novo salario base? (float)\n-R: ";
                        cin >> tp;
                        Funcionarios[r].setSalarioBase(tp);
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