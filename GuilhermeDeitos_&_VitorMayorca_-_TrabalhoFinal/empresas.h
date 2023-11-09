void obter_empresa(){
    int foo, op = 42;
    string senha;
    do{
        system("cls");
        string cpf;
        cout << "=-= Insira qualquer numero (int)\n-R: ";
        cin >> foo;
        cout << "=-= Insira a senha de gerente (string)\n-R: ";
        cin.ignore();
        getline(cin, senha);
        if(autenticagerente(senha) == true){
            cout << "Qual o cnpj da empresa que voce deseja checar (string)?\n-R: ";
            getline(cin, cpf);
            dadosempresa(cpf);
        }else{
            cout << "\nSenha invalida!";
        }
        cout << "\n\n=-= Deseja continuar analisando empresas?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}


void dadosempresa(string cnpj){
    int resp;
    for(long long unsigned int r = 0; r < Empresas.size(); r++){
        if(cnpj == Empresas[r].getCnpj()){
            cout << "\n\nCNPJ eh " << Empresas[r].getCnpj();
            cout << "\nNome eh " << Empresas[r].getNome();
            cout << "\nNome fantasia eh " << Empresas[r].getNomeFantasia();
            cout << "\nRazao social eh " << Empresas[r].getRazaoSocial();
            sleep_for(3000ms);
            cout << "\n\n=-= Deseja checar os funcionarios? (1 - Sim, !1 - Nao)\n-R: ";
            cin >> resp;
            if(resp == 1){
                checafunc(r);
            }
            cout << "\n\n=-= Deseja checar os clientes? (1 - Sim, !1 - Nao)\n-R: ";
            cin >> resp;
            if(resp == 1){
                checacli(r);
            }
            cout << "\n\n=-= Deseja checar a folha de pagamento? (1 - Sim, !1 - Nao)\n-R: ";
            cin >> resp;
            if(resp == 1){
                cout << "Total a se pagar " << calcularFolhaDePagamento(r); 
                //O compilador simplesmente nao aceitava essa função como um método da classe Empresa. Então eu tive que fazer uma função separada
            }
        }
    }
}

void checafunc(int r){
    int dd;
    for(long long unsigned int i = 0; i < Empresas[r].vfuncionarios.size(); i++){
        dd = Empresas[r].vfuncionarios[i];
        cout << "\n\nMatricula " << Funcionarios[dd].getMatricula();
        cout << "\nNome " << Funcionarios[dd].getNome();
        cout << "\nSalario " << Funcionarios[dd].calculaSalarioBruto();
    }
    for(long long unsigned int i = 0; i < Empresas[r].vgerente.size(); i++){
        dd = Empresas[r].vgerente[i];
        cout << "\n\nMatricula " << Gerentes[dd].getMatricula();
        cout << "\nNome " << Gerentes[dd].getNome();
        cout << "\nSalario " << Gerentes[dd].calculaSalarioBruto();
    }
    for(long long unsigned int i = 0; i < Empresas[r].vestagiarios.size(); i++){
        dd = Empresas[r].vestagiarios[i];
        cout << "\n\nMatricula " << Estagiarios[dd].getMatricula();
        cout << "\nNome " << Estagiarios[dd].getNome();
        cout << "\nSalario " << Estagiarios[dd].calculaSalarioBruto();
    }
}
void checacli(int r){
    int dd;
    struct Endereco sus;
    for(long long unsigned int i = 0; i < Empresas[r].vclientes.size(); i++){
        dd = Empresas[r].vclientes[i];
        cout << "\nNome " << Clientes[dd].getNome();
        cout << "\nTelefone " << Clientes[dd].getTelefone();

        sus = Clientes[dd].getEndereco();
        
        cout << "\nCEP " << sus.cep;
        cout << "\nNumero " << sus.numero;
        cout << "\nComplemento " << sus.complemento;
    }
}

void alterar_empresa(){
    int op = 42, foo;
    int alt;
    string cpf, senha;
    do{
        cout << "=-= Insira qualquer numero (int)\n-R: ";
        cin >> foo;
        cout << "=-= Insira a senha de gerente (string)\n-R: ";
        cin.ignore();
        getline(cin, senha);
        if(autenticagerente(senha) == true){
            system("cls");
            cout << "Voce quer adicionar novas empresas, ou alterar os dados de uma existente?\n1 - Novo, 2 - Alterar\n-R: ";
            cin >> alt;
            switch(alt){
                case 1:
                    novaempresa();
                break;
                case 2:
                    cout << "Qual o cnpj da empresa que voce deseja alterar (string)?\n-R: ";
                    cin.ignore();
                    getline(cin, cpf);
                    alteraempresa(cpf);
                break;
                default:
                    cout << "\n-=- Opcao invalida!\n" << endl; 
                break;
            }
        }else{
            cout << "\n-=- Senha invalida!";
        }
        cout << "\n\n=-= Deseja continuar alterando empresas?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void novaempresa(){
    Empresa novo;
    struct Endereco novoo;
    string temp;
    int pt;
    //cpf endereco nome telefone all string
    system("cls");
    cout << "=-= Insira o nome da empresa (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novo.setNome(temp);
    cout << "=-= Insira o CNPJ da empresa (string)\n-R: ";
    getline(cin, temp);
    novo.setCnpj(temp);
    cout << "=-= Insira o nome fantasia da empresa (string)\n-R: ";
    getline(cin, temp);
    novo.setNomeFantasia(temp);
    cout << "=-= Insira a razao social (string)\n-R: ";
    getline(cin, temp);
    novo.setRazaoSocial(temp);
    do{
        pt = 0;
        cout << "=-= Funcionarios! Insira o id dos seus funcionarios, numero negativo para sair (int)\n-R: ";
        cin >> pt;
        novo.vfuncionarios.push_back(pt);
    }while(pt >= 0);
    
    do{
        pt = 0;
        cout << "=-= Gerentes! Insira o id dos seus gerentes, numero negativo para sair (int)\n-R: ";
        cin >> pt;
        novo.vgerente.push_back(pt);
    }while(pt >= 0);

    do{
        pt = 0;
        cout << "=-= Estagiarios! Insira o id dos seus estagiarios, numero negativo para sair (int)\n-R: ";
        cin >> pt;
        novo.vestagiarios.push_back(pt);
    }while(pt >= 0);

    do{
        pt = 0;
        cout << "=-= Clientes! Insira o id dos seus clientes, numero negativo para sair (int)\n-R: ";
        cin >> pt;
        novo.vclientes.push_back(pt);
    }while(pt >= 0);

    Empresas.push_back(novo);
    //sleep_for(4000ms);
}


void alteraempresa(string cnpj){
    int op, nono;
    long long unsigned int nini;
    string temp;
    struct Endereco novo;
    for(long long unsigned int r = 0; r < Empresas.size(); r++){
        if(cnpj == Empresas[r].getCnpj()){
            do{
                cout << "=-= Qual informacao voce deseja alterar?\n1 - Nome, 2 - CNPJ, 3 - Nome fantasia, 4 - Razao social, 5 - Novo funcionario, 6 - Novo cliente, 0 - Voltar\n-R: ";
                cin >> op;
                switch(op){
                    case 1:
                        cout << "= Novo nome? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Empresas[r].setNome(temp);
                    break;
                    case 2:
                        cout << "= Novo CNPJ? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Empresas[r].setCnpj(temp);
                    break;
                    case 3:
                       cout << "= Novo nome fantasia? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Empresas[r].setNomeFantasia(temp);
                    break;
                    case 4:
                        cout << "= Nova razao social? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Empresas[r].setRazaoSocial(temp);
                    break;
                    case 5:
                        cout << "1 - Funcionario, 2 - Gerente, 3 - Estagiario\n-R: ";
                        cin >> nono;
                        switch(nono){
                            case 1:
                                cout << "ID do funcionario?\n-R: ";
                                cin >> nini;
                                if(nini >= Empresas[r].vfuncionarios.size()){
                                    cout << "\nEsse funcionario ainda nao foi criado!\n";
                                }else{
                                    Empresas[r].vfuncionarios.emplace_back(nini);
                                }
                            break;
                            case 2:
                                cout << "ID do gerente?\n-R: ";
                                cin >> nini;
                                if(nini >= Empresas[r].vgerente.size()){
                                    cout << "\nEsse gerente ainda nao foi criado!\n";
                                }else{
                                    Empresas[r].vgerente.emplace_back(nini);
                                }
                            break;
                            case 3:
                                cout << "ID do estagiario?\n-R: ";
                                cin >> nini;
                                if(nini >= Empresas[r].vestagiarios.size()){
                                    cout << "\nEsse estagiario ainda nao foi criado!\n";
                                }else{
                                    Empresas[r].vestagiarios.emplace_back(nini);
                                }
                            break;
                        }
                    break;
                    case 6:
                        cout << "ID do cliente?\n-R: ";
                        cin >> nini;
                        if(nini >= Empresas[r].vclientes.size()){
                            cout << "\nEsse cliente ainda nao foi criado!\n";
                        }else{
                            Empresas[r].vclientes.emplace_back(nini);
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

bool autenticagerente(string senha){

    for(long long unsigned int r = 0; r < Gerentes.size(); r++){
        if(Gerentes[r].autenticar(senha) == true){
            return true;
        }
    }
    return false;
}