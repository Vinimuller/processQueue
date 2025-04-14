#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {

public:
    Item(string nome, char tipo, int combate, int FA, int dano);
    Item();

    string getNome();
    char getTipo();
    int getCombate();
    int getFA();
    int getDano();

    void setNome(string nome);
    void setTipo(char tipo);
    void setCombate(int combate);
    void setFA(int FA);
    void setDano(int Dano);

protected:
    string nome;
    char tipo; 
    int combate;
    int FA;
    int dano;
};

#endif
