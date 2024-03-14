#include <iostream> // Biblioteca para entrada e saida padrao
#include <fstream>  // Biblioteca para manipulacao de arquivos
#include <string>   // Biblioteca para manipulacao de strings

using namespace std; // Utilizando o namespace padrao

// Definicao da estrutura para representar um bem
struct Bem {
    string nome;
    string categoria;
    string dataAquisicao;
    float peso;
    string endereco; // apenas para imoveis
};

// Funcaoo para cadastrar um novo bem
void cadastrarBem(Bem* bens[], int& numBens) {
    Bem* novoBem = new Bem; // Aloca dinamicamente memoria para um novo bem
    cout << "Nome do bem: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, novoBem->nome); // Recebe o nome do bem
    cout << "Categoria: ";
    cin >> novoBem->categoria; // Recebe a categoria do bem
    cout << "Data de aquisicao: ";
    cin >> novoBem->dataAquisicao; // Recebe a data de aquisicao do bem
    cout << "Peso: ";
    cin >> novoBem->peso; // Recebe o peso do bem
    if (novoBem->categoria == "imovel") { // Verifica se a categoria e imovel
        cout << "Endereco: ";
        cin >> novoBem->endereco; // Se for imovel, recebe o endereco
    }
    bens[numBens++] = novoBem; // Adiciona o novo bem ao array de bens e incrementa o contador de bens
}

// Função para salvar os bens em um arquivo
void salvarBens(Bem* bens[], int numBens) {
    ofstream arquivo("bens.txt"); // Abre o arquivo "bens.txt" para escrita
    for (int i = 0; i < numBens; ++i) { // Loop pelos bens cadastrados
        arquivo << bens[i]->nome << ", " << bens[i]->categoria << ", " << bens[i]->dataAquisicao << ", " << bens[i]->peso; // Escreve os dados do bem no arquivo
        if (bens[i]->categoria == "imovel") { // Se for um imovel
            arquivo << " " << bens[i]->endereco; // Escreve tambem o endereco
        }
        arquivo << endl; // Nova linha para o proximo bem
    }
    arquivo.close(); // Fecha o arquivo
}

int main() {
    const int MAX_BENS = 30; // Define o tamanho maximo do array de bens
    Bem* bens[MAX_BENS]; // Declara o array de ponteiros para bens
    int numBens = 0; // Variavel para controlar o numero de bens cadastrados

    char opcao; // Variavel para armazenar a opcao do menu
    do {
        cout << "Menu:\n"; // Exibe o menu
        cout << "1. Cadastrar novo bem\n";
        cout << "2. Salvar bens\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao; // Recebe a opcao do usuario

        switch(opcao) {
            case '1':
                cadastrarBem(bens, numBens); // Chama a funcao para cadastrar um novo bem
                break;
            case '2':
                salvarBens(bens, numBens); // Chama a funcao para salvar os bens em um arquivo
                cout << "Bens salvos com sucesso!\n"; // Mensagem de sucesso
                break;
            case '3':
                cout << "Saindo...\n"; // Mensagem de saida
                break;
            default:
                cout << "Opcao invalida!\n"; // Mensagem de opcao invalida
        }
    } while (opcao != '3'); // Repete ate que a opcao escolhida seja sair

    for (int i = 0; i < numBens; ++i) { // Libera a memoria alocada para os bens
        delete bens[i];
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}

