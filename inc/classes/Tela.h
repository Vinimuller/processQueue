#pragma once

#include <chrono>
#include <thread>
#include "Arquivos.h"
#include "UserInput.h"


class Tela {
public:
    Tela();
    ~Tela();
    void exibirConteudoPrincipal(string nomeDoArquivo);
    void exibirConteudoPrincipal(int nomeDoArquivo);
    void limpaTerminal();
    void aguarde();

private:
    Arquivos arquivos;
    UserInput userInput;
};

