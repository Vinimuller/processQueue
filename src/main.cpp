#include <iostream>
#include <string>
#include <locale>

#include "../inc/classes/Arquivos.h"
#include "../inc/classes/UserInput.h"
#include "../inc/classes/Tela.h"
#include "../inc/classes/Menu.h"

using namespace std;

Arquivos arquivo;
UserInput userInput;
Tela tela;
Menu menu;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // usa o locale do sistema

    switch(menu.run()){
        case 1:
            // Nova aventura
            break;
        case 2:
            // Carregar aventura 
            break;
        default:
            return 0;
            break;
    }

    return 0;
}
