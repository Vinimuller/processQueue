#include "../inc/classes/Personagem.h"

Personagem::Personagem(){};

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
	this->energia += energiaAdicionada;
}

void Personagem::addHabilidade(int energiaAdicionada)
{
	this->habilidade += energiaAdicionada;
}

int Personagem::getHabilidade(){
	return this->habilidade;
}


void Personagem::addSorte(int sorteAdicionada)
{
	this->sorte += sorteAdicionada;
}

//void Personagem::addMagia(Magia novaMagia)
//{
//	//adicionar magias no grim�rio do personagem
//}
//
//void Personagem::addItem(Item novoItem)
//{
//	//adiciona itens no inventario do personagem
//}
//
//void Personagem::addTesouro(Item novoTesouro)
//{
//	//adiciona tesouros no inventario do personagem
//}

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
		//adicionar l�gica para n�o ultrapassar o m�ximo de enrgia
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
	// Declara as vari�veis locais
	int numeroRandomizado = rand() % 12;
	int resultado = abs(sorte - numeroRandomizado);
	// Se o n�mero randomizado for maior que a sorte, ele teve m� sorte
	if (numeroRandomizado % 12 > sorte) {
		resultado = resultado*(-1);
	}
	sorte--;
	return resultado;
}

void Personagem::mostrarInventario(){
	
    cout << "Inventário de " << nome << ":" << endl;
	inventario.listarItens();
}

void Personagem::adicionarItemAoInventario(string item) {
	Item novoItem;

	stringstream ss(item);
	string campo;

	// Primeiro campo: Nome
	getline(ss, campo, ';');
	novoItem.setNome(campo);

	// Segundo campo: Tipo
	getline(ss, campo, ';');
	novoItem.setTipo(campo);

	// Terceiro campo: Combate
	getline(ss, campo, ';');
	cout << campo << endl;
	novoItem.setCombate(stoi(campo)); // converte string para int

	// Quarto campo: FA
	getline(ss, campo, ';');
	novoItem.setFA(stoi(campo));

	// Quinto campo: Dano
	getline(ss, campo, '\n');
	novoItem.setDano(stoi(campo));
		
    inventario.adicionarItem(novoItem);
}

void Personagem::adicionarItemAoInventario(Item& item) {
   inventario.adicionarItem(item);
}

void Personagem::equiparItem(string& nome) {
    inventario.equiparItem(nome);
}

void Personagem::usarItem(string& nome) {
    inventario.usarItem(nome);
}