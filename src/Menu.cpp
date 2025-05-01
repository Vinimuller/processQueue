#include "../inc/classes/Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

int Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.rangedReadNumber(1,3);
    return input;
}