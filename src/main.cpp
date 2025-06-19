#include <iostream>
#include <string>
#include <locale>

#include "../inc/classes/Menu.h"
#include "../inc/classes/Sistema.h"

using namespace std;

Sistema sistema;
Menu menu(&sistema);

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // usa o locale do sistema
    while(true){
        if(menu.run() == 6) break;
    }
    return 0;
}
