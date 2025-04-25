#include "../inc/classes/Inimigo.h"

Inimigo::Inimigo(){}
Inimigo::~Inimigo(){}

void Inimigo::carregarPersonagem(string atributosInimigo){
    istringstream iss(atributosInimigo);
    string linha;
    map<char, std::string> atributos;

    while (getline(iss, linha)) {
        if (linha.find(':') != string::npos) {
            char chave = linha[0];
            std::string valor = linha.substr(3); // ignora "X: "
            atributos[chave] = valor;
        } else if (linha.find(';') != string::npos) {
            atributos['X'] = linha; // posição final
        }
    }

	this->nome = atributos['N'];
	this->habilidade = stoi(atributos['H']);
	this->sorte = stoi(atributos['S']);
	this->energia = stoi(atributos['E']);
	this->quantidadeDeProvisoes = stoi(atributos['P']);
	
	cout << "Personagem carregado: " << this->nome << endl;
}