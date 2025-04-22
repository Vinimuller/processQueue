#include "../inc/classes/Menu.h"

Menu::Menu(){};

Menu::~Menu(){};

void Menu::run(){
    arquivos.exibirCena("menu");
    int input = userInput.readNumber();
    if(input == novaAventura){
        //novaAventura
    } else if (input == carregarAventura){
        //carregarAventura
    }
}