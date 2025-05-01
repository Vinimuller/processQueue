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

	string arquivoParaSalvar = "Saves/";
	arquivoParaSalvar += this->nome;

	adicionarResumoDePersonagens();

	arquivo.apagarArquivo(arquivoParaSalvar);
	return arquivo.escreverArquivo(arquivoParaSalvar, newSave);

}

void Heroi::adicionarResumoDePersonagens(){
	
	string arquivoResumoPersonagens = arquivo.lerArquivo("Saves/savesDisponiveis");

	arquivo.exibirCena("Saves/savesDisponiveis");

	stringstream ss(arquivoResumoPersonagens);
	string linha;
	
	while(getline(ss, linha)){
		if(linha.find(this->nome) == 0){
			linha.erase();
		}
	}
	
	string resumoPersonagem;
	resumoPersonagem += "Nome:"; resumoPersonagem += this->nome; resumoPersonagem += "|  ";
	resumoPersonagem += "Habilidade:"; resumoPersonagem += to_string(this->habilidade); resumoPersonagem += "|  ";
	resumoPersonagem += "Sorte:"; resumoPersonagem += to_string(this->sorte); resumoPersonagem += "|  ";
	resumoPersonagem += "Energia:"; resumoPersonagem += to_string(this->energia); resumoPersonagem += "|  ";
	resumoPersonagem += "Provisões:"; resumoPersonagem += to_string(this->quantidadeDeProvisoes); resumoPersonagem += "|  ";
	resumoPersonagem += "\n";
	//resumoPersonagem += "T:"; resumoPersonagem += this->tesouro; resumoPersonagem += ";  ";

	arquivoResumoPersonagens += resumoPersonagem;
	
	arquivo.escreverArquivo("Saves/SavesDisponiveis", arquivoResumoPersonagens);
}

string Heroi::getSavesDisponiveis(){

	string savesDisponiveis = arquivo.lerArquivo("Saves/SavesDisponiveis");

	if(savesDisponiveis == ""){
		return "";
	}

	stringstream ss(savesDisponiveis);
	string linha;

	map<int, std::string> saves;
	int indiceSave = 1;

	cout << "Escolha o Personagem que deseja carregar:" << endl;

	while(getline(ss, linha)){
		if(linha.rfind('N', 0) == 0){
			size_t inicio = linha.find("Nome:") + 5;
			size_t fim = linha.find('|', inicio);
			saves[indiceSave] = linha.substr(inicio, fim - inicio);
			cout << "> " << indiceSave << " - " << linha << endl;
			indiceSave++;
		}
	}

	cout << endl;

	int escolha = userInput.rangedReadNumber(1, indiceSave);

	return ("Saves/" + saves[escolha]);

}

bool Heroi::carregarPersonagem()
{
	string arquivoDoPersonagem = getSavesDisponiveis();

	if(arquivoDoPersonagem == ""){
		return false;
	}

	string personagemFormatado = arquivo.lerArquivo(arquivoDoPersonagem);

	stringstream iss(personagemFormatado);
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

	return true;
}