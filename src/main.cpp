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
Sistema sistema;
Menu menu(&sistema);

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // usa o locale do sistema
    while(true){
        if(menu.run() == 6) break;
    }
    return 0;
}
