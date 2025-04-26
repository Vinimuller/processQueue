#include "../inc/classes/Tela.h"

Tela::Tela(){};
Tela::~Tela(){};

void Tela::exibirConteudoPrincipal(string nomeDoArquivo){
    arquivos.exibirCena(nomeDoArquivo);

};

void Tela::exibirConteudoPrincipal(int nomeDoArquivo){
    arquivos.exibirCena(nomeDoArquivo);
    
};

void Tela::limpaTerminal(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems (Linux, macOS)
    #endif
}