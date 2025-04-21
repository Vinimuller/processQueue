#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "LeitorArquivo.h"

LeitorArquivo leitorArquivo;

int main() {
    int cena = 1;
    const int totalCenas = 10;

    while (cena <= totalCenas) {
        std::cout << "\n=== Cena " << cena << " ===\n\n";
        leitorArquivo.exibirCena(cena);

        int escolha = leitorArquivo.obterEscolhaUsuario();
        if (escolha == 0) {
            std::cout << "Você abandonou a dungeon. Fim de jogo.\n";
            break;
        }

        cena++;
    }

    if (cena > totalCenas) {
        std::cout << "\nVocê completou a Dungeon de Thal'Zul! Parabéns!\n";
    }

    return 0;
}
