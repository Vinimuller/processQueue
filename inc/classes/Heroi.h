#pragma once

#include <string>

#include "Personagem.h"

class Heroi : public Personagem{
public:
    Heroi();
    ~Heroi();

    void setUltimaCena(string ultimaCena);
    string getUltimaCena();
    void carregarPersonagem(string nomePersonagem) override;
    
    bool save();
private:
    string ultimaCena;
};