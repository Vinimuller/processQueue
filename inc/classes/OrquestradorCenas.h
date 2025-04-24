#pragma once

#include "Tela.h"
#include "Menu.h"
#include "Personagem.h"

class OrquestradorCenas{
public:
    OrquestradorCenas(Personagem *heroi);
    
    void runCena();
    string getUltimaCena();
    void setUltimaCena(string ultimaCena);

private:
    Personagem *heroi;
    string ultimaCena;

};