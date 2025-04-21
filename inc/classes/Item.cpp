#include "Item.h"

Item::Item(string nome, char tipo, int combate, int FA, int dano) : nome(nome), tipo(tipo), combate(combate), FA(FA), dano(dano){}
Item::Item(){}

string Item::getNome() {
    return nome;
}

char Item::getTipo() {
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

void Item::setNome(string nome) {
    this->nome = nome;
}

void Item::setTipo(char tipo) {
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
