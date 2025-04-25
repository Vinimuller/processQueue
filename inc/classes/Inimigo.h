#pragma once

#include "Personagem.h"

class Inimigo : public Personagem{
public:
    Inimigo();
    ~Inimigo();

    void carregarPersonagem(string atributosInimigo) override;

};