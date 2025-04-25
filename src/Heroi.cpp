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

	arquivo.apagarArquivo("personagem");

	arquivo.escreverArquivo("personagem", newSave);
	
	return true;

}