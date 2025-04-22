#pragma once

#include "Tela.h"
#include "Arquivos.h"
#include "UserInput.h"

class Menu : public Tela {  
public:
    Menu();
    ~Menu();
    void run();
private:
    Arquivos arquivos;
    UserInput userInput;
    int novaAventura = 1;
    int carregarAventura = 2;
};