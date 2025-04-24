#include <iostream>
#include <string>

#include "../inc/classes/Arquivos.h"
#include "../inc/classes/UserInput.h"
#include "../inc/classes/Tela.h"
#include "../inc/classes/Menu.h"
#include "../inc/classes/Personagem.h"
#include "../inc/classes/OrquestradorCenas.h"

Arquivos arquivo;
UserInput userInput;
Tela tela;
Menu menu;
Personagem heroi;

int main() {

    //Tela de Menu
        // 1 -> Nova Aventura
        // 2 -> Carregar Aventura
    

    switch(menu.run()){
        case 1:
            // Nova aventura
            //heroi.criarNovo()
            break;
        case 2:
            // Carregar aventura 
            // Falta implementar o inventario
            heroi.carregarPersonagem();
            break;
        default:
            return 0;
            break;
    }

    OrquestradorCenas orquestradorCenas(&heroi);
    while(true){
        orquestradorCenas.runCena();
        //heroi.save(orquestradorCenas.getUltimaCena());
    }
    return 0;
}
