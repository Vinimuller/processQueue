#pragma once

#include "Tela.h"
#include "Menu.h"
#include "Inimigo.h"
#include "Heroi.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "Batalha.h"

class OrquestradorCenas{
public:
    OrquestradorCenas(Heroi *heroi);
    
    void runCena();
    string getUltimaCena();
    void setUltimaCena(string ultimaCena);

private:
    Heroi *heroi;
    string ultimaCena;
    Arquivos arquivo;
    UserInput userInput;

    string lerAtributosDoInimigo(string cena);
    void carregarDescricao(string cena);
    void getProximasCenas(string cena);

    string proximaCenaSucesso;
    string proximaCenaFracaso;
    string proximaCenaA;
    string proximaCenaB;

};