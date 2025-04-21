#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class Arquivos
{
public:
	void exibirCena(int cenaAtual);
	void exibirCena(string cenaAtual);

	// Escreve em arquivo
	bool escreverArquivo(const string& filename, const string& content);

	// Lê conteúdo de um arquivo e retorna como string
	string lerArquivo(const std::string& filename);

private:

};

#endif
