#include "../inc/classes/Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

int Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.readNumber();
    if(input == novaAventura){
        return 1;
    } else if (input == carregarAventura){
        return 2;
    }
    else{
        return run();
    }
    return 0;
}