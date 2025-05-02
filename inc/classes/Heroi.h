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
    void setMaximoDeEnergia(int maxEnergia);
    bool carregarPersonagem();
    void adicionarResumoDePersonagens();
    string getSavesDisponiveis();
    void usarProvisao();
    void getProvisao(int quantidade);
    bool save();
    void printStats();

private:
    string gerarSaveInventario();
    string ultimaCena;
    UserInput userInput;

    int maximoDeEnergia;
};