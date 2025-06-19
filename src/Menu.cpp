#include "../inc/classes/Menu.h"

Menu::Menu(Sistema *sistema){
    this->sistema = sistema;
}

Menu::~Menu(){}

int Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.rangedReadNumber(1,6);

    switch(input){
        case 1:
            //Cria processo
            cout << "Criar processo" << endl;
            sistema->criarProcesso();
            break;
        case 2:
            //Executa proximo processo
            cout << "Executar próximo processo" << endl;
            sistema->executarProximo();
            break;
        case 3:
            //Executa processo especifico
            cout << "Executar processo específico" << endl;
            sistema->executarProcessoEspecifico();
            break;
        case 4:
            //Salva fila de processos
            cout << "Salvar fila de processos" << endl;
            break;
        case 5:
            //Carregar do arquivo a fila de processos
            cout << "Carregar arquivo" << endl;
            break;
        case 6:
            cout << "Encerrando sistema" << endl;
            break;
        default:
            cout << "Comando não existe" << endl;
            return run();
            break;
    }
    return input;
}