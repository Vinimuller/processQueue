#pragma once

#include "Personagem.h"

class DistribuicaoAtributos{
public:
    void run(Personagem *personagem);
private:
    void addNome(string nomePersonagem);
    void addEnergia(int energia);
    void addSorte(int sorte);

};