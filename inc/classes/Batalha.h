#pragma once

#include "Arquivos.h"
#include "Tela.h"
#include "Heroi.h"
#include "Inimigo.h"
#include "UserInput.h"

class Batalha {
public:
    Batalha(Heroi* heroi, Inimigo* inimigo);
    ~Batalha();
    bool run();
    void exibirOpcoes();
    bool perguntaQuerUtilizarSorte();


private:
    Arquivos arquivos;
    Heroi *heroi;
    Inimigo *inimigo;
    UserInput userInput;
    void mostrarStatus(Heroi *heroi, Inimigo *inimigo);

};

