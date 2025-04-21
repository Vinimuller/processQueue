#include <iostream>
#include <string>

#include "../inc/classes/Arquivos.h"
#include "../inc/classes/UserInput.h"

Arquivos arquivo;
UserInput userInput;

int main() {

    //Tela de Menu
        // 1 -> Nova Aventura
        // 2 -> Carregar Aventura
    arquivo.exibirCena("menu");
    int menuSelection = userInput.readNumber();

    switch(menuSelection){
        case 1:
            // Nova aventura
            cout << "nova adv" << endl;
            break;
        case 2:
            // Carregar aventura 
            cout << "carregar adv" << endl;
            break;
        default:
            cout << "nothing here" << endl;
            break;
    }


    // exemplo escrita arquivo
    arquivo.escreverArquivo("testFile.txt", "teste\nteste\ntest");

    //exemplo leitura aquivo
    string readFile = arquivo.lerArquivo("testFile.txt");

    cout << readFile << endl << endl << endl;



    //codigo teste de carregamento cenas >>>>
    int cena = 1;
    const int totalCenas = 10;
    while (cena <= totalCenas) {
        std::cout << "\n=== Cena " << cena << " ===\n\n";
        arquivo.exibirCena(cena);

        int escolha = userInput.readNumber();
        if (escolha == 0) {
            std::cout << "Você abandonou a dungeon. Fim de jogo.\n";
            break;
        }

        cena++;
    }

    if (cena > totalCenas) {
        std::cout << "\nVocê completou a Dungeon de Thal'Zul! Parabéns!\n";
    }

    //codigo teste de carregamento cenas <<<<<

    return 0;
}
