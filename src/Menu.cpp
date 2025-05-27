#include "../inc/classes/Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

int Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.rangedReadNumber(1,5);

    switch(input){
        case 1:
            //Cria processo
            cout << "Criar processo" << endl;
            break;
        case 2:
            //Executa proximo processo
            cout << "Executar próximo processo" << endl;
            break;
        case 3:
            //Executa processo especifico
            cout << "Executar processo específico" << endl;
            break;
        case 4:
            //Salva fila de processos
            cout << "Salvar fila de processos" << endl;
            break;
        case 5:
            //Carregar do arquivo a fila de processos
            cout << "Carregar arquivo" << endl;
            break;
        default:
            cout << "Comando não existe" << endl;
            while(1);
            break;
    }


    if(input == 3){
        arquivos.exibirCena("creditos");
        userInput.rangedReadNumber(1,1);
        return run();

    }
    return input;
}