#include "../inc/classes/Personagem.h"

Personagem::Personagem(){};

void Personagem::carregarPersonagem(string nomePersonagem)
{
	string personagemFormatado = arquivo.lerArquivo(nomePersonagem);

	istringstream iss(personagemFormatado);
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