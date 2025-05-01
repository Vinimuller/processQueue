#include <iostream>
#include <string>
#include <locale>

#include "../inc/classes/Arquivos.h"
#include "../inc/classes/UserInput.h"
#include "../inc/classes/Tela.h"
#include "../inc/classes/Menu.h"
#include "../inc/classes/Personagem.h"
#include "../inc/classes/OrquestradorCenas.h"
#include "../inc/classes/Heroi.h"
#include "../inc/classes/CriacaoDePersonagem.h"

using namespace std;

Arquivos arquivo;
UserInput userInput;
Tela tela;
Menu menu;
Heroi heroi;
CriacaoDePersonagem criacaoDePersonagem;


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // usa o locale do sistema
    //Tela de Menu
        // 1 -> Nova Aventura
        // 2 -> Carregar Aventura
    
        OrquestradorCenas orquestradorCenas(&heroi);

    switch(menu.run()){
        case 1:
            // Nova aventura
            criacaoDePersonagem.run(&heroi);
            orquestradorCenas.setUltimaCena("1");
            break;
        case 2:
            // Carregar aventura 
            // Falta implementar o inventario
            if(heroi.carregarPersonagem() == false){
                cout << "Não foi possível carregar o personagem desejado, reinicie o jogo..." << endl;
                return 0;
            }
            orquestradorCenas.setUltimaCena(heroi.getUltimaCena());
            break;
        default:
            return 0;
            break;
    }

    heroi.adicionarItemAoInventario("Adaga Meia-Lua;A;1;1;40");

    while(true){
        orquestradorCenas.runCena();
        heroi.save();
    }
    return 0;
}
