// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    // Construtores
    Item(std::string nome, string tipo, int combate, int FA, int dano);
    Item();  // Construtor padr�o

    // M�todos getters
    std::string getNome();
    string getTipo();
    int getCombate();
    int getFA();
    int getDano();

    // M�todos setters
    void setNome(std::string nome);
    void setTipo(string tipo);
    void setCombate(int combate);
    void setFA(int FA);
    void setDano(int dano);

protected:
    std::string nome;
    string tipo;  // Tipo do item (Ex: 'A' para arma, 'P' para po��o, etc)
    int combate; // Pode ser valor associado a dano ou defesa
    int FA;  // For�a de Ataque (FA)
    int dano;  // Dano do item
};

#endif // ITEM_H
