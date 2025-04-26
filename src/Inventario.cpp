// Inventario.cpp
#include "../inc/classes/Inventario.h"

// Adiciona um item ao invent�rio
void Inventario::adicionarItem(Item& item) {
    itens.push_back(item);
}

// Lista todos os itens do invent�rio
void Inventario::listarItens(){
    if (itens.empty()) {
        std::cout << "Inventário vazio!" << std::endl;
    }
    else {
        for (auto& item : itens) {
            std::cout << "Nome: " << item.getNome() << ", Tipo: " << item.getTipo()
                << ", Combate: " << item.getCombate() << ", FA: " << item.getFA()
                << ", Dano: " << item.getDano() << std::endl;
        }
    }
}

string Inventario::getListaDeItens(){
    if (itens.empty()) {
        return "";
    }
    else {
        string listaDeItens = "";
        for (auto& item : itens) {
            listaDeItens += item.getNome(); listaDeItens += ";";
            listaDeItens += item.getTipo(); listaDeItens += ";";
            listaDeItens += to_string(item.getCombate()); listaDeItens += ";";
            listaDeItens += to_string(item.getFA()); listaDeItens += ";";
            listaDeItens += to_string(item.getDano()); listaDeItens += ";";
            listaDeItens += "\n";
        }
        return listaDeItens;
    }
}

// Equipar um item
bool Inventario::equiparItem(std::string& nome) {
    for (auto& item : itens) {
        if (item.getNome() == nome) {
            itemEquipado = item;  // Equipando o item
            std::cout << "Item " << nome << " equipado!" << std::endl;
            return true;
        }
    }
    std::cout << "Item não encontrado no inventário!" << std::endl;
    return false;
}

// Usar um item
void Inventario::usarItem(std::string& nome) {
    for (auto& item : itens) {
        if (item.getNome() == nome) {
            std::cout << "Você usou " << nome << "!" << std::endl;
            // Aqui podemos implementar o efeito do uso do item (ex: aumentar FA, sa�de, etc.)
            return;
        }
    }
    std::cout << "Item não encontrado no inventário!" << std::endl;
}
