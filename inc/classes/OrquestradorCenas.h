#pragma once

#include "Tela.h"
#include "Menu.h"
#include "Personagem.h"

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "Batalha.h"

class OrquestradorCenas{
public:
    OrquestradorCenas(Personagem *heroi);
    
    void runCena();
    string getUltimaCena();
    void setUltimaCena(string ultimaCena);

private:
    Personagem *heroi;
    string ultimaCena;
    Arquivos arquivo;
    UserInput userInput;

    string lerAtributosDoInimigo(string cena);
    void carregarDescricao(string cena);
    

};