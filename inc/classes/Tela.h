#pragma once

#include "Arquivos.h"

class Tela {
public:
    Tela();
    ~Tela();
    void exibirConteudoPrincipal(string nomeDoArquivo);
    void exibirConteudoPrincipal(int nomeDoArquivo);
    void limpaTerminal();

private:
    Arquivos arquivos;
};

