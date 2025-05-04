// Inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <iostream>
#include <string>

#include "Item.h"
#include "UserInput.h"

using namespace std;

class Inventario {
public:
    void run();
    void adicionarItem(Item& item);
    void listarItens();
    bool equiparItem(string nome);
    void usarItem(std::string& nome);
    string getListaDeItens();

    int getDanoItemEquipado();
    int getFAItemEquipado();
    string getNomeItemEquipado();

private:
    std::vector<Item> itens;  // Lista de itens no invent�rio
    Item itemEquipado;  // Item que est� atualmente equipado
    UserInput userInput;
    string nomeItemEquipado;
};

#endif // INVENTARIO_H
