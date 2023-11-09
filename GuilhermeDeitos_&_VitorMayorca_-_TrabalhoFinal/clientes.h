void dadosdocliente(string cpf){
    cpf = cpf;
    string temp;
    struct Endereco novo;
    cpf = cpf;
    for(long long unsigned int r = 0; r < Clientes.size(); r++){
        if(cpf == Clientes[r].getCpf()){
            cout << "\n\nCPF eh " << Clientes[r].getCpf();
            novo = Clientes[r].getEndereco();
            cout << "\nCEP eh " << novo.cep;
            cout << "\nNumero eh " << novo.numero;
            cout << "\nComplemento eh " << novo.complemento;
            cout << "\nNome eh " << Clientes[r].getNome();
            cout << "\nTelefone eh " << Clientes[r].getTelefone();
            sleep_for(3000ms);

        }
    }
}

void novocliente(){
    Cliente novo;
    struct Endereco novoo;
    string temp;
    int tp;
    //cpf endereco nome telefone all string
    system("cls");
    cout << "=-= Insira o nome do cliente (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novo.setNome(temp);
    cout << "=-= Insira o CPF do cliente (string)\n-R: ";
    getline(cin, temp);
    novo.setCpf(temp);
    cout << "=-= Insira o telefone do cliente (string)\n-R: ";
    getline(cin, temp);
    novo.setTelefone(temp);
    cout << "=-= Insira o CEP do cliente (string)\n-R: ";
    getline(cin, temp);
    novoo.cep = temp;
    cout << "=-= Insira o numero do endereco (int)\n-R: ";
    cin >> tp;
    novoo.numero = tp;
    cout << "=-= Insira um complemento (string)\n-R: ";
    cin.ignore();
    getline(cin, temp);
    novoo.complemento = temp;
    novo.setEndereco(novoo);

    Clientes.push_back(novo);

    //sleep_for(4000ms);
}

void alteracliente(string cpf){
    int op, numero;
    string temp;
    struct Endereco novo;
    cpf = cpf;
    for(long long unsigned int r = 0; r < Clientes.size(); r++){
        if(cpf == Clientes[r].getCpf()){
            do{
                cout << "=-= Qual informacao voce deseja alterar?\n1 - Nome, 2 - CPF, 3 - Endereco, 4 - Telefone, 0 - Voltar\n-R: ";
                cin >> op;
                switch(op){
                    case 1:
                        cout << "= Novo nome? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Clientes[r].setNome(temp);
                    break;
                    case 2:
                        cout << "= Novo CPF? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Clientes[r].setCpf(temp);
                    break;
                    case 4:
                        cout << "= Novo Telefone? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        Clientes[r].setTelefone(temp);
                    break;
                    case 3:
                        cout << "Novo CEP? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        novo.cep = temp;
                        cout << "Novo numero? (int)\n-R: ";
                        cin >> numero;
                        novo.numero = numero;
                        cout << "Novo complemento? (string)\n-R: ";
                        cin.ignore();
                        getline(cin, temp);
                        novo.complemento = temp;
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

void alterar_clientes(){
    int op = 42;
    int alt;
    string cpf;
    do{
        system("cls");
        cout << "Voce quer adicionar novos clientes, ou alterar os dados de um existente?\n1 - Novo, 2 - Alterar\n-R: ";
        cin >> alt;
        switch(alt){
            case 1:
                novocliente();
            break;
            case 2:
                cout << "Qual o cpf do cliente que voce deseja alterar (string)?\n-R: ";
                cin.ignore();
                getline(cin, cpf);
                alteracliente(cpf);
            break;
            default:
                cout << "\n-=- Opcao invalida!\n" << endl; 
            break;
        }

        cout << "\n\n=-= Deseja continuar alterando clientes?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}

void obter_clientes(){
    int op = 42;
    do{
        system("cls");
        string cpf;
        cout << "Qual o cpf do cliente que voce deseja checar (string)?\n-R: ";
        cin.ignore();
        getline(cin, cpf);
        dadosdocliente(cpf);
        cout << "\n\n=-= Deseja continuar analisando clientes?\n 1 - Sim, 0 - Nao\nR: ";
        cin >> op;
    }while(op != 0);
}