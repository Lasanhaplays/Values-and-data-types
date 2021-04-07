#include <iostream>
#include <string>
#include <iterator>
#include <map>

using namespace std;


class Pessoa{

    public:
    string Nome;
    string CPF;
    string Profissao;
    string Data_Nascimento;

};
Pessoa Objeto;
// Definicao do mapeamento
map<string, Pessoa> Mapeamento_LP;
// Definicao do iterator para buscas e plotagens na tela
map<string, Pessoa>::iterator itr;

Pessoa insere_dados(){
    Pessoa Objeto;

    cout << "Nome do cliente: ";
    cin.ignore();
    getline (cin, Objeto.Nome);
    cout << "CPF: ";
    cin >> Objeto.CPF;
    cout << "Profissao: ";
    cin >> Objeto.Profissao;
    cout << "Data de nascimento: ";
    cin >> Objeto.Data_Nascimento;

    return Objeto;
}

void Pesquisa (){
    string busca;
    cout<<"[1] Digite uma chave para buscar dados"<<endl;
    cin >> busca;
    itr = Mapeamento_LP.find(busca); // Busca um elemento específico por meio da chave associada ao referido elemento
    if (itr !=Mapeamento_LP.end() )
      cout << "Valor da Chave Buscada => " << itr->second.Nome << '\n';
    else
     cout << "Chave buscada nao encontrada " << '\n';
}

void imprimirDados(){
    cout << "\nO mapa e: \n";
    cout << "\tChave\t\tNome\t\tCPF\t\tProfissao\n";
    for (itr = Mapeamento_LP.begin(); itr != Mapeamento_LP.end(); ++itr) {
        cout << '\t' << itr->first
        << "\t" << itr->second.Nome
        << "\t" << itr->second.CPF
        << "\t" << itr->second.Profissao
        << '\n';
    }
    cout << endl;
}

void alterarDados(){
    string busca;
    int opc;
    cout <<"[1] Digite uma chave para buscar os dados da pessoa a serem alterados"<<endl;
    cin >> busca;
    itr = Mapeamento_LP.find(busca);
    if (itr !=Mapeamento_LP.end()){
        do{
            cout<<"[1] Alterar nome"<<endl;
            cout<<"[2] Alterar data de nascimento"<<endl;
            cout<<"[3] Alterar profissao"<<endl;
            cout<<"[4] Sair"<<endl;
            cin>>opc;
            system("clear || cls");

            switch (opc){
                case 1:
                    cout << "Novo nome do cliente: ";
                    cin.ignore();
                    getline (cin, itr->second.Nome);
                    cout<<"Nome alterado com sucesso!"<<endl;
                    break;
                case 2:
                    cout << "Nova data de nascimento: ";
                    cin >> itr->second.Data_Nascimento;
                    cout<<"Data de nascimento alterada com sucesso!"<<endl;
                    break;
                case 3:
                    cout << "Nova profissao: ";
                    cin >> itr->second.Profissao;
                    cout<<"Profissao alterada com sucesso!"<<endl;
                    break;
                default:
                    cout<<"Opcao invalida"<<endl;
                }
            }while(opc != 4);
    }
    else{
        cout << "Chave buscada nao encontrada " << '\n';
        return;
    }
}

void excluiDados(){
    string busca;
    int opc;
    cout <<"[1] Digite uma chave para buscar os dados da pessoa a serem excluidos"<<endl;
    cin >> busca;
    itr = Mapeamento_LP.find(busca);
    if (itr !=Mapeamento_LP.end()){
        Mapeamento_LP.erase(busca);
        cout << "Chave buscada deletada " << '\n';
    }
    else{
        cout << "Chave buscada nao encontrada " << '\n';
        return;
    }
}

int main()
{

 int opc;
    do{
        cout<<"[1] Incluir pessoa"<<endl;
        cout<<"[2] Imprimir dados de pessoa"<<endl;
        cout<<"[3] Buscar dados de pessoa"<<endl;
        cout<<"[4] Alterar dados de pessoa"<<endl;
        cout<<"[5] Excluir dados de pessoa"<<endl;
        cout<<"[6] Obter tamanho do Map de pessoa"<<endl;
        cout<<"[7] Sair"<<endl;
        cin>>opc;
        system("clear || cls");

        switch (opc){
            case 1:    // Insere elementos
                Objeto = insere_dados();
                Mapeamento_LP.insert(pair<string, Pessoa>(Objeto.CPF, Objeto));
                break;

            case 2:
                imprimirDados();
                break;

            case 3:
                Pesquisa();
                break;

            case 4:
                alterarDados();
                break;
            case 5:
                excluiDados();
                break;
            case 6:
                cout << "O tamanho do map e: ";
                cout << Mapeamento_LP.size();
                cout << "\n\n";
                break;
            case 7:

                break;

            default:
                cout<<"Opcao invalida"<<endl;
        }
    }while(opc != 7);


}
