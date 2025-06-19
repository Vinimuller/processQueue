#pragma once

#include "Tela.h"
#include "Arquivos.h"
#include "UserInput.h"
#include "Sistema.h"

class Menu : public Tela {  
public:
    Menu(Sistema *sistema);
    ~Menu();
    int run();
private:
    Arquivos arquivos;
    UserInput userInput;
    Sistema *sistema;
    int novaAventura = 1;
    int carregarAventura = 2;
};