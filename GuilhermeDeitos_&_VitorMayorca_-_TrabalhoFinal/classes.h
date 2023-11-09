using namespace std;
using namespace std::this_thread;     // Para o comando sleep_for
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

void obter_funcionarios();
void alterar_funcionarios();
void obter_clientes();
void alterar_clientes();
void obter_empresa();
void alterar_empresa();
void analisegerente();
void analisenormal();
bool autenticagerente(string senha);
void analiseestagiario();
void alteragerente(string cpf);
void alteranormal(string cpf);
void alteraestagiario(string cpf);
void dadosdocliente(string cpf);
void novocliente();
void alteracliente(string cpf);
void dadosempresa(string cnpj);
void alteraempresa(string cnpj);
void novaempresa();
void inicio();
void dadosfuncionario(string cpf);
void dadosgerente(string cpf);
void dadosestagiario(string cpf);
void alterafuncionarios();
void novogerente();
void escolhe_altera_gerente();
void novogerente();
void escolhe_altera_normal();
void novonormal();
void escolhe_altera_estagiario();
void novoestagiario();
void checafunc(int r);
void checacli(int r);
float calcularFolhaDePagamento(int r);

// Classes
class Pessoa
{
public:
    string nome;
    string getNome();
    void setNome(string nome);
};

class PessoaFisica : public Pessoa
{
public:
    string getCpf();
    void setCpf(string cpf);

private:
    string cpf;
};

class PessoaJuridica : public Pessoa
{
public:
    string getCnpj();
    void setCnpj(string cnpj);
    string getRazaoSocial();
    void setRazaoSocial(string razaoSocial);
    string getNomeFantasia();
    void setNomeFantasia(string nomeFantasia);

private:
    string cnpj;
    string razaoSocial;
    string nomeFantasia;
};

class Funcionario : public PessoaFisica
{
public:
    string getMatricula();
    void setMatricula(string matricula);
    float getSalario();
    void setSalario(float salario);
    float getSalarioBase(); // Adicionado método para obter o salário base
    void setSalarioBase(float salarioBase); // Adicionado método para definir o salário base
    int getCargaHorariaMensal();
    void setCargaHorariaMensal(int cargaHorariaMensal);
    float getQtdHorasTrabalhadas();
    void setQtdHorasTrabalhadas(float qtdHorasTrabalhadas);
    virtual float calculaBonus(); // Declarada como virtual
    float calculaSalarioBruto();

private:
    string matricula;
    float salarioBase;
    float salarioBruto;
    int cargaHorariaMensal;
    float qtdHorasTrabalhadas;
};

class Gerente : public Funcionario
{
public:
    bool autenticar(string senha);
    int getHorasExtras();
    void setHorasExtras(int horasExtras);
    int getQndFuncionariosGerenciados();
    void setQndFuncionariosGerenciados(int qndFuncionariosGerenciados);
    bool alterarSenha(string senhaAtual, string senhaNova);
    float calculaBonus() override; // Adicionado override
private:

    int qndFuncionariosGerenciados;
    int horasExtras;
    string senha;
};

class Estagiario : public Funcionario
{
public:
    int getTempoDeContratoRestante();
    void setTempoDeContratoRestante(int tempoDeContratoRestante);
    int getTipoEstagiario();
    void setTipoEstagiario(int tipoEstagiario);
    float calculaBonus() override; // Adicionado override
private:
    int tempoDeContratoRestante;
    int tipoEstagiario;
};

struct Endereco
{
    string cep;
    int numero;
    string complemento;
};

class Cliente : public PessoaFisica
{
public:
    string getTelefone();
    void setTelefone(string telefone);
    Endereco getEndereco();
    void setEndereco(Endereco endereco);

private:
    string telefone;
    Endereco endereco;
};

class Empresa : public PessoaJuridica{
    public:
        int addFuncionario();
        int addCliente();
        void listarFuncionarios();
        void listarClientes();
        vector<int> vclientes; //Numero do index do cliente no vetor cliente
        vector<int> vfuncionarios; //Numero do index do funcionario no vetor
        vector<int> vestagiarios; //Numero do index do estagiario no vetor
        vector<int> vgerente; //Numero do index do gerente no vetor
};

// Métodos Pessoa
void Pessoa::setNome(string nome) { this->nome = nome; }

string Pessoa::getNome() { return nome; }

// Métodos PessoaFisica
void PessoaFisica::setCpf(string cpf) { this->cpf = cpf; }

string PessoaFisica::getCpf() { return cpf; }

// Métodos PessoaJuridica
void PessoaJuridica::setCnpj(string cnpj) { this->cnpj = cnpj; }

string PessoaJuridica::getCnpj() { return cnpj; }

void PessoaJuridica::setRazaoSocial(string razaoSocial) { this->razaoSocial = razaoSocial; }

string PessoaJuridica::getRazaoSocial() { return razaoSocial; }

void PessoaJuridica::setNomeFantasia(string nomeFantasia) { this->nomeFantasia = nomeFantasia; }

string PessoaJuridica::getNomeFantasia() { return nomeFantasia; }

// Métodos Funcionario
void Funcionario::setMatricula(string matricula) { this->matricula = matricula; }

string Funcionario::getMatricula() { return matricula; }

void Funcionario::setSalario(float salario)
{
    this->salarioBruto = salario;
    if (!this->salarioBase)
    {
        this->salarioBase = salario;
    }
}

float Funcionario::getSalarioBase() { return salarioBase; } // Implementação do método getSalarioBase

float Funcionario::getSalario() { return salarioBruto; }

void Funcionario::setSalarioBase(float salarioBase) { this->salarioBase = salarioBase; } // Implementação do método setSalarioBase

void Funcionario::setCargaHorariaMensal(int cargaHorariaMensal) { this->cargaHorariaMensal = cargaHorariaMensal; }

int Funcionario::getCargaHorariaMensal() { return cargaHorariaMensal; }

void Funcionario::setQtdHorasTrabalhadas(float qtdHorasTrabalhadas)
{
    if (qtdHorasTrabalhadas <= this->cargaHorariaMensal && qtdHorasTrabalhadas > 0)
    {
        this->qtdHorasTrabalhadas = qtdHorasTrabalhadas;
    }
    else
    {
        this->qtdHorasTrabalhadas = this->cargaHorariaMensal;
    }
}

float Funcionario::getQtdHorasTrabalhadas() { return qtdHorasTrabalhadas; }

float Funcionario::calculaBonus()
{
    return 0.0;
}

float Funcionario::calculaSalarioBruto()
{
    return (this->salarioBase * this->qtdHorasTrabalhadas) / (this->cargaHorariaMensal) + calculaBonus();
}

// Métodos Gerente
int Gerente::getHorasExtras() { return horasExtras; }

void Gerente::setHorasExtras(int horasExtras) { this->horasExtras = horasExtras; }

int Gerente::getQndFuncionariosGerenciados() { return qndFuncionariosGerenciados; }

void Gerente::setQndFuncionariosGerenciados(int qndFuncionariosGerenciados) { this->qndFuncionariosGerenciados = qndFuncionariosGerenciados; }

bool Gerente::autenticar(string senhaDigitada)
{
    if (senhaDigitada == this->senha)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Gerente::alterarSenha(string senhaAtual, string senhaNova)
{
    if (this->senha == "")
    {
        this->senha = senhaNova;
        return true;
    }
    else if (senhaAtual == this->senha)
    {
        this->senha = senhaNova;
        return true;
    }
    else
    {
        return false;
    }
}

float Gerente::calculaBonus()
{
    float auxSalario = 0;
    for (int i = 0; i < this->qndFuncionariosGerenciados; i++)
    {
        if ((getSalario() * 0.005) < (getSalarioBase() * 0.3))
        {
            auxSalario += getSalario() * 0.005;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < (getQtdHorasTrabalhadas() - getCargaHorariaMensal()); i++)
    {
        auxSalario += (getSalarioBase() * 1.5) / getCargaHorariaMensal();
    }

    return auxSalario;
}

// Métodos Estagiario

int Estagiario::getTempoDeContratoRestante() { return tempoDeContratoRestante; }

void Estagiario::setTempoDeContratoRestante(int tempoDeContratoRestante) { this->tempoDeContratoRestante = tempoDeContratoRestante; }

int Estagiario::getTipoEstagiario() { return tipoEstagiario; }

void Estagiario::setTipoEstagiario(int tipoEstagiario) { this->tipoEstagiario = tipoEstagiario; }

float Estagiario::calculaBonus()
{
    float auxSalario = 0;
    if (this->tipoEstagiario == 1)
    { // 1 - Jovem Aprendiz
        auxSalario += getSalarioBase() * 0.05 / this->tempoDeContratoRestante;
    }
    else if (this->tipoEstagiario == 2)
    { // 2 - Universitario
        auxSalario += getSalarioBase() * 0.1 / this->tempoDeContratoRestante;
    }

    return auxSalario;
}

// Métodos Cliente

Endereco Cliente::getEndereco() { return endereco; }

void Cliente::setEndereco(Endereco endereco)
{
    this->endereco.numero = endereco.numero;
    this->endereco.cep = endereco.cep;
    this->endereco.complemento = endereco.complemento;
}

string Cliente::getTelefone() { return telefone; }

void Cliente::setTelefone(string telefone) { this->telefone = telefone; }





vector<Cliente> Clientes;
vector<Estagiario> Estagiarios;
vector<Funcionario> Funcionarios;
vector<Gerente> Gerentes;
vector<Empresa> Empresas;

void inicio(){
    struct Endereco j;
    j.cep = "1059792";
    j.complemento = "Casa";
    j.numero = 161;
    Cliente Jorge;
    Jorge.setNome("Jorge da Silva");
    Jorge.setCpf("097.425.159-30");
    Jorge.setTelefone("45 999-852-607");
    Jorge.setEndereco(j);
    Clientes.push_back(Jorge);

    Estagiario Jose;
    Jose.setCargaHorariaMensal(40);
    Jose.setCpf("231231123");
    Jose.setMatricula("Asasc");
    Jose.setNome("Jose Bonifacio");
    Jose.setQtdHorasTrabalhadas(12.4);
    Jose.setSalario(120.60);
    Jose.setSalarioBase(120.60);
    Jose.setTempoDeContratoRestante(6);
    Jose.setTipoEstagiario(1);
    Estagiarios.push_back(Jose);
    
    Funcionario Adair;
    Adair.setCargaHorariaMensal(80);
    Adair.setCpf("23109231");
    Adair.setMatricula("qqweq3wqe12");
    Adair.setNome("Adair Adalvo da Silva");
    Adair.setQtdHorasTrabalhadas(12);
    Adair.setSalario(1200.2);
    Adair.setSalarioBase(1300.4);
    Funcionarios.push_back(Adair);

    Gerente Gilmar;
    Gilmar.setCargaHorariaMensal(100);
    Gilmar.setCpf("qwd3223");
    Gilmar.setHorasExtras(21);
    Gilmar.setMatricula("sd23dwd");
    Gilmar.setNome("Gilmar Gilnei");
    Gilmar.setQndFuncionariosGerenciados(169);
    Gilmar.setQtdHorasTrabalhadas(100.2);
    Gilmar.setSalario(12331.1);
    Gilmar.setSalarioBase(23123.7);
    Gerentes.push_back(Gilmar);
    Gerentes[0].alterarSenha("12345", "12345");

    Empresa Piracanjuba;
    Piracanjuba.setCnpj("12312312");
    Piracanjuba.setNome("Piracanjuba Ltda");
    Piracanjuba.setNomeFantasia("Piracanjuba");
    Piracanjuba.setRazaoSocial("Piraracanjuba");
    Empresas.push_back(Piracanjuba);
    Empresas[0].vclientes.emplace_back(0);
    Empresas[0].vestagiarios.emplace_back(0);
    Empresas[0].vfuncionarios.emplace_back(0);
    Empresas[0].vgerente.emplace_back(0);
}



float calcularFolhaDePagamento(int r){
   float total = 0.0;
   int dd;
    
    for(long long unsigned int i = 0; i < Empresas[r].vfuncionarios.size(); i++){
        dd = Empresas[r].vfuncionarios[i];
        total = total + Funcionarios[dd].calculaSalarioBruto();
    }
    for(long long unsigned int i = 0; i < Empresas[r].vgerente.size(); i++){
        dd = Empresas[r].vgerente[i];
        total = total + Gerentes[dd].calculaSalarioBruto();
    }
    for(long long unsigned int i = 0; i < Empresas[r].vestagiarios.size(); i++){
        dd = Empresas[r].vestagiarios[i];
        total = total + Estagiarios[dd].calculaSalarioBruto();
    }
   return total;
}

