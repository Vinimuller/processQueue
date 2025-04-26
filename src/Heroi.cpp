#include "../inc/classes/Heroi.h"

Heroi::Heroi(){}
Heroi::~Heroi(){}

void Heroi::setUltimaCena(string ultimaCena){
    this->ultimaCena = ultimaCena;
}

string Heroi::getUltimaCena(){
    return this->ultimaCena;
}

bool Heroi::save(){
	string newSave;
	newSave += "N: ";
	newSave += this->nome;
	newSave += "\n";

	newSave += "H: ";
	newSave += to_string(this->habilidade);
	newSave += "\n";

	newSave += "S: ";
	newSave += to_string(this->sorte);
	newSave += "\n";

	newSave += "E: ";
	newSave += to_string(energia);
	newSave += "\n";

	// newSave += "T: ";
	// newSave += this->tesouro;
	// newSave += "\n";

	newSave += "P: ";
	newSave += to_string(this->quantidadeDeProvisoes);
	newSave += "\n";

	newSave += "C: ";
	newSave += this->ultimaCena;
	newSave += "\n";

	newSave += inventario.getListaDeItens();

	arquivo.apagarArquivo("personagem");

	arquivo.escreverArquivo("personagem", newSave);
	
	return true;

}

void Heroi::carregarPersonagem(string nomePersonagem)
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
	this->ultimaCena = atributos['C'];
	this->quantidadeDeProvisoes = stoi(atributos['P']);
	
	//cout << "Personagem carregado: " << this->nome << endl;
}