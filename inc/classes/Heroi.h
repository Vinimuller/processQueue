#pragma once

#include <string>

#include "Personagem.h"

class Heroi : public Personagem{
public:
    Heroi();
    ~Heroi();

    void setUltimaCena(string ultimaCena);
    string getUltimaCena();
    bool save();
private:
    string ultimaCena;
};