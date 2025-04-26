// Inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <iostream>
#include <string>

#include "Item.h"

using namespace std;

class Inventario {
public:
    void adicionarItem(Item& item);
    void listarItens();
    bool equiparItem(std::string& nome);
    void usarItem(std::string& nome);
    string getListaDeItens();

private:
    std::vector<Item> itens;  // Lista de itens no invent�rio
    Item itemEquipado;  // Item que est� atualmente equipado
};

#endif // INVENTARIO_H
