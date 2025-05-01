#include "../inc/classes/Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

int Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.rangedReadNumber(1,3);
    if(input == 3){
        arquivos.exibirCena("creditos");
        userInput.rangedReadNumber(1,1);
        return run();

    }
    return input;
}