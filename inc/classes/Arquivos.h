#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

class Arquivos
{
public:
	void exibirCena(int cenaAtual);
	void exibirCena(string cenaAtual);
	
	void apagarArquivo(const std::string& filename);

	// Escreve em arquivo
	bool escreverArquivo(const string& filename, const string& content);

	// Lê conteúdo de um arquivo e retorna como string
	string lerArquivo(const string& filename);

private:
	string folderPath = "telas/";

};

#endif
