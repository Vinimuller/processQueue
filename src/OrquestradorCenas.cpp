#include "../inc/classes/OrquestradorCenas.h"

OrquestradorCenas::OrquestradorCenas(Personagem *heroi){
    this->heroi = heroi;
}

string OrquestradorCenas::getUltimaCena(){
    return ultimaCena;
}

void OrquestradorCenas::setUltimaCena(string ultimaCena){
    this->ultimaCena = ultimaCena;
}

void OrquestradorCenas::carregarDescricao(string cena){
    istringstream stream(cena);
    string descricao;
    string linha;
    while(getline(stream, linha)){
        if(linha.rfind("N:", 0) == 0 || linha.rfind("I:", 0) == 0 || linha.empty()){
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
}



void OrquestradorCenas::runCena(){
    string cena = arquivo.lerArquivo(this->ultimaCena);

    carregarDescricao(cena);
    

    if(ultimaCena.at(0) == 'm'){
        Personagem inimigo;
        inimigo.carregarPersonagem(lerAtributosDoInimigo(cena));

        Batalha batalha(heroi, &inimigo);
        bool resultadoDaBatalha = batalha.run();
        if(resultadoDaBatalha == false){
            cout << "Infelizmente " << heroi->getNome() << " sucumbiu na luta contra " << inimigo.getNome() << "..." << endl;
            cout << "Tente novamente! (reinicie o jogo e vá em carregar)" << endl;
            while(true){}
        }
        // Cena de batalha
        // print da cena
        // print opções padrao
        // espera resposta de usuário
    } else {
        bool escolhaFeitaEValida = false;
        while(escolhaFeitaEValida == false){

        }
        // Cena de escolha ou interação
        // print da cena
        // print das opções descritas na cena
        // espera resposta de usuário
    }
    
}