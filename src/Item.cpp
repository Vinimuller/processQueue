// Item.cpp
#include "../inc/classes/Item.h"

Item::Item(std::string nome, string tipo, int combate, int FA, int dano)
    : nome(nome), tipo(tipo), combate(combate), FA(FA), dano(dano) {
}

Item::Item() : nome(""), tipo(""), combate(0), FA(0), dano(0) {}

string Item::getNome() {
    return nome;
}

string Item::getTipo() {
    return tipo;
}

int Item::getCombate() {
    return combate;
}

int Item::getFA() {
    return FA;
}

int Item::getDano() {
    return dano;
}

void Item::setNome(std::string nome) {
    this->nome = nome;
}

void Item::setTipo(string tipo) {
    this->tipo = tipo;
}

void Item::setCombate(int combate) {
    this->combate = combate;
}

void Item::setFA(int FA) {
    this->FA = FA;
}

void Item::setDano(int dano) {
    this->dano = dano;
}
