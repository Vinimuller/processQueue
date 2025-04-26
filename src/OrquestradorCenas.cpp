#include "../inc/classes/OrquestradorCenas.h"

OrquestradorCenas::OrquestradorCenas(Heroi *heroi){
    this->heroi = heroi;
}

string OrquestradorCenas::getUltimaCena(){
    return ultimaCena;
}

void OrquestradorCenas::setUltimaCena(string ultimaCena){
    this->ultimaCena = ultimaCena;
}

void OrquestradorCenas::clearTheTerminal(){
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems (Linux, macOS)
    #endif

}

void OrquestradorCenas::carregarDescricao(string cena){
    istringstream stream(cena);
    string descricao;
    string linha;
    while(getline(stream, linha)){
        if(linha.rfind("N:", 0) == 0 || linha.rfind("I:", 0) == 0 || isdigit(linha[0])){
            break;
        } else {
            descricao += linha + "\n";
        }
    }
    cout << descricao << endl;
}

string OrquestradorCenas::lerAtributosDoInimigo(string cena){
    istringstream stream(cena);
    string atributos;
    string linha;
    while(getline(stream, linha)){
        if (linha.find(':') != string::npos) {
            atributos += linha + "\n"; // apenas adiciona a linha à string
        }
    }
    return atributos;
}

void OrquestradorCenas::getProximasCenas(string cena){
    istringstream stream(cena);
    string ultimaLinhaNumeros;
    string linha;
    while (getline(stream, linha)) {
        if (linha.find(';') != string::npos && linha.find(':') == string::npos) {
            ultimaLinhaNumeros = linha; // armazena a última que parece ser "NumeroA;NumeroB"
        }
    }

    // Extrai os dois números da última linha encontrada
    if (!ultimaLinhaNumeros.empty()) {
        size_t pos = ultimaLinhaNumeros.find(';');
        proximaCenaA = ultimaLinhaNumeros.substr(0, pos);
        proximaCenaB = ultimaLinhaNumeros.substr(pos + 1);
    }
}

string OrquestradorCenas::getItensDaCena

void OrquestradorCenas::runCena(){
    string cena = arquivo.lerArquivo(this->ultimaCena);
    
    carregarDescricao(cena);
    getProximasCenas(cena);

    if(ultimaCena.at(0) == 'm'){
        Inimigo inimigo;
        inimigo.carregarPersonagem(lerAtributosDoInimigo(cena));

        Batalha batalha(heroi, &inimigo);
        bool resultadoDaBatalha = batalha.run();
        if(resultadoDaBatalha == false){
            cout << "Infelizmente " << heroi->getNome() << " sucumbiu na luta contra " << inimigo.getNome() << "..." << endl;
            cout << "Tente novamente! (reinicie o jogo e vá em carregar)" << endl;
            while(true){}
            //Modificar para verificar próxima cena
        } else {
            ultimaCena = proximaCenaA;
        }
        clearTheTerminal();
        // Cena de batalha
        // print da cena
        // print opções padrao
        // espera resposta de usuário
    } else {
        if(userInput.rangedReadNumber(1,2) == 1){
            ultimaCena = proximaCenaA;
        } else {
            ultimaCena = proximaCenaB;
        }
        heroi->setUltimaCena(ultimaCena);
        clearTheTerminal();
        // Cena de escolha ou interação
        // print da cena
        // print das opções descritas na cena
        // espera resposta de usuário
    }
}