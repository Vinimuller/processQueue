#pragma once

#include <string>

#include "Personagem.h"
#include "UserInput.h"

class Heroi : public Personagem{
public:
    Heroi();
    ~Heroi();

    void setUltimaCena(string ultimaCena);
    string getUltimaCena();
    bool carregarPersonagem();
    void adicionarResumoDePersonagens();
    string getSavesDisponiveis();
    
    bool save();
private:
    string gerarSaveInventario();
    string ultimaCena;
    UserInput userInput;
};