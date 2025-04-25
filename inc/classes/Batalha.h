#pragma once

#include "Arquivos.h"
#include "Tela.h"
#include "Personagem.h"
#include "UserInput.h"

class Batalha {
public:
    Batalha(Personagem* heroi, Personagem* inimigo);
    ~Batalha();
    bool run();
    void exibirOpcoes();
    int escolhaDoUsuario();
    bool perguntaQuerUtilizarSorte();


private:
    Arquivos arquivos;
    Personagem *heroi;
    Personagem *inimigo;
    UserInput userInput;
};

