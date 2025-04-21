#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class LeitorArquivo
{
public:
	void exibirCena(int cenaAtual);
	void exibirCena(string cenaAtual);

	int obterEscolhaUsuario();

private:

};

#endif
