#include "../inc/classes/Tela.h"

Tela::Tela(){};
Tela::~Tela(){};

void Tela::exibirConteudoPrincipal(string nomeDoArquivo){
    arquivos.exibirCena(nomeDoArquivo);

};

void Tela::exibirConteudoPrincipal(int nomeDoArquivo){
    arquivos.exibirCena(nomeDoArquivo);
    
};

void Tela::recebeInputDoJogador(){};