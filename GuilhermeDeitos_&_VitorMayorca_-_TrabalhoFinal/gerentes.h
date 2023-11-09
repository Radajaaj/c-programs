void analisegerente(){
    int op = 42;
    do{
        system("cls");
        string cpf;
        cout << "Qual o cpf do gerente que voce deseja checar?\n-R: ";
        cin.ignore();
        getline(cin, cpf);
        dadosgerente(cpf);
        cout << "\n\n=-= Deseja continuar analisando gerentes?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void dadosgerente(string cpf){
    cpf = cpf;
    string temp;
    cpf = cpf;
    for(long long unsigned int r = 0; r < Gerentes.size(); r++){
        if(cpf == Gerentes[r].getCpf()){
            cout << "\n\nCPF eh " << Gerentes[r].getCpf();
            cout << "\nNome eh " << Gerentes[r].getNome();
            cout << "\nCarga mensal eh " << Gerentes[r].getCargaHorariaMensal();
            cout << "\nHoras trabalhadas eh " << Gerentes[r].getQtdHorasTrabalhadas();
            cout << "\nMatricula eh " << Gerentes[r].getMatricula();
            cout << "\nSalario eh " << Gerentes[r].getSalario();
            cout << "\nSalario base eh " << Gerentes[r].getSalarioBase();
            cout << "\nHoras extras eh " << Gerentes[r].getHorasExtras();
            cout << "\nFuncionarios gerenciados: " << Gerentes[r].getQndFuncionariosGerenciados();
            cout << "\nBonus eh " << Gerentes[r].calculaBonus();
            sleep_for(3000ms);
        }
    }
}

void escolhe_altera_gerente(){
    int op = 42;
    int alt;
    string cpf;
    do{
        system("cls");
        cout << "Voce quer adicionar novos gerentes, ou alterar os dados de um existente?\n1 - Novo, 2 - Alterar\n-R: ";
        cin >> alt;
        switch(alt){
            case 1:
                novogerente();
            break;
            case 2:
                cout << "Qual o cpf do gerente que voce deseja alterar (string)?\n-R: ";
                cin.ignore();
                getline(cin, cpf);
                alteragerente(cpf);
            break;
            default:
                cout << "\n-=- Opcao invalida!\n" << endl; 
            break;
        }

        cout << "\n\n=-= Deseja continuar alterando gerentes?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void novogerente(){
    Gerente novo;
    string temp;
    int tp;
    float sal;
    //cpf endereco nome telefone all string
    system("cls");
    cout << "=-= Insira o nome do gerente (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novo.setNome(temp);//
    cout << "=-= Insira o CPF do gerente (string)\n-R: ";
    getline(cin, temp);
    novo.setCpf(temp);//
    cout << "=-= Insira a matricula do gerente (string)\n-R: ";
    getline(cin, temp);
    novo.setMatricula(temp);//
    cout << "=-= Insira a carga horaria mensal (int)\n-R: ";
    cin >> tp;
    novo.setCargaHorariaMensal(tp);//
    cout << "=-= Insira quantas horas extras ele ja fez (int)\n-R: ";
    cin >> tp;
    novo.setHorasExtras(tp);//
    cout << "=-= Insira quantos funcionarios ele gerencia (int)\n-R: ";
    cin >> tp;
    novo.setQndFuncionariosGerenciados(tp);//
    cout << "=-= Insira quantas horas ele ja trabalhou (float)\n-R: ";
    cin >> sal;
    novo.setQtdHorasTrabalhadas(sal);//
    cout << "=-= Insira o salario (float)\n-R: ";
    cin >> sal;
    novo.setSalario(sal);//
    cout << "=-= Insira o salario base (float)\n-R: ";
    cin >> sal;
    novo.setSalarioBase(sal);//

    Gerentes.push_back(novo);
}

void alteragerente(string cpf){
    int op, numero;
    float tp;
    string temp, senha;
    for(long long unsigned int r = 0; r < Gerentes.size(); r++){
        if(cpf == Gerentes[r].getCpf()){
            do{
                cout << "=-= Qual informacao voce deseja alterar?\n1 - Nome, 2 - CPF, 3 - Matricula, 4 - Carga Horaria, 5 - Horas Extras, 6 - Funcionarios gerenciados, 7 - Horas trabalhadas, 8 - Salario, 9 - Salario base, 10 - Alterar senha, 0 - Voltar\n-R: ";
                cin >> op;
                switch(op){
                    case 1:
                        cout << "= Novo nome? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Gerentes[r].setNome(temp);
                    break;
                    case 2:
                        cout << "= Novo CPF? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Gerentes[r].setCpf(temp);
                    break;
                    case 3:
                        cout << "=Nova matricula? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Gerentes[r].setMatricula(temp);
                    break;
                    case 4:
                        cout << "=Nova carga horaria? (int)\n-R: ";
                        cin >> numero;
                        Gerentes[r].setCargaHorariaMensal(numero);
                    break;
                    case 5:
                        cout << "=Novas horas extras trabalhadas? (int)\n-R: ";
                        cin >> numero;
                        Gerentes[r].setHorasExtras(numero);
                    break;
                    case 6:
                        cout << "=Novo n de funcionarios gerenciados? (int)\n-R: ";
                        cin >> numero;
                        Gerentes[r].setQndFuncionariosGerenciados(numero);
                    break;
                    case 7:
                        cout << "=Novo horas trabalhadas? (float)\n-R: ";
                        cin >> tp;
                        Gerentes[r].setQtdHorasTrabalhadas(tp);
                    break;
                    case 8:
                        cout << "=Novo salario? (float)\n-R: ";
                        cin >> tp;
                        Gerentes[r].setSalario(tp);
                    break;
                    case 9:
                        cout << "=Novo salario base? (float)\n-R: ";
                        cin >> tp;
                        Gerentes[r].setSalarioBase(tp);
                    break;
                    case 10:
                        cout << "=Nova senha? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        cout << "=Senha antiga? (string)\n-R: ";
                        getline(cin, senha);
                        if(Gerentes[r].alterarSenha(senha, temp) == true){
                            cout << "\nSenha alterada com sucesso!";
                            sleep_for(1500ms);
                        }else{
                            cout << "\nSenha atual invalida! Desligando o sistema!";
                             sleep_for(99999s);
                        }
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
