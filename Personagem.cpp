#include "Personagem.h"

Personagem::Personagem(string nome, int energia, int sorte)
{
	this->nome = nome;
	this->energia = energia;
	this->sorte = sorte;
}

Personagem::Personagem()
{
}

void Personagem::setNome(string nome)
{
	this->nome = nome;
}

void Personagem::setEnergia(int energia)
{
	this->energia = energia;
}

void Personagem::setSorte(int sorte)
{
	this->sorte = sorte;
}

void Personagem::setProvisoes(int provisoes)
{
	this->quantidadeDeProvisoes = provisoes;
}

string Personagem::getNome()
{
	return this->nome;
}

int Personagem::getEnergia()
{
	return this->energia;
}

int Personagem::getSorte()
{
	return this->sorte;
}

int Personagem::getProvisoes()
{
	return this->quantidadeDeProvisoes;
}

void Personagem::addEnergia(int energiaAdicionada)
{
	this->energia = energiaAdicionada;
}

void Personagem::addSorte(int sorteAdicionada)
{
	this->sorte = sorteAdicionada;
}

void Personagem::addMagia(Magia novaMagia)
{
	//adicionar magias no grimório do personagem
}

void Personagem::addItem(Item novoItem)
{
	//adiciona itens no inventario do personagem
}

void Personagem::addTesouro(Item novoTesouro)
{
	//adiciona tesouros no inventario do personagem
}

void Personagem::addProvisao(int provisaoAdicionada)
{
	this->quantidadeDeProvisoes += provisaoAdicionada;
}

void Personagem::removerEnergia(int energiaRemovida)
{
	this->energia -= energiaRemovida;
}

void Personagem::removerSorte(int sorteRemovida)
{
	this->sorte -= sorteRemovida;
}

bool Personagem::utilizarProvisao()
{
	if (quantidadeDeProvisoes > 0) {
		quantidadeDeProvisoes--;
		energia += energiaRecuperadaPorProvisao;
		//adicionar lógica para não ultrapassar o máximo de enrgia
	}
	return false;
}

int Personagem::testeDeAtaque(bool usarSorte)
{
	int resultado = 0;
	while(resultado == 0) resultado = rand() % 10;
	
	resultado += habilidade;

	if (usarSorte) {
		resultado += this->usarSorte();
	}

	return resultado;
}


int Personagem::usarSorte() {
	// Declara as variáveis locais
	int numeroRandomizado = rand() % 12;
	int resultado = abs(sorte - numeroRandomizado);
	// Se o número randomizado for maior que a sorte, ele teve má sorte
	if (numeroRandomizado % 12 > sorte) {
		resultado = resultado*(-1);
	}
	sorte--;
	return resultado;
}