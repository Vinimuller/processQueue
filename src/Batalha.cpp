#include "../inc/classes/Batalha.h"

Batalha::Batalha(Heroi *heroi, Inimigo *inimigo){
    this->heroi = heroi;
    this->inimigo = inimigo;
}

Batalha::~Batalha(){}

void Batalha::exibirOpcoes(){
    cout << "1. Atacar" << endl;
    cout << "2. Acessar Inventario" << endl;
}

bool Batalha::perguntaQuerUtilizarSorte(){
    cout << endl;
    cout << "Deseja utilizar sorte? (" << heroi->getSorte() << " ponto(s) de sorte restante(s))" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    if(userInput.rangedReadNumber(1,2) == 1){
        return true;
    }
    return false;
}

void Batalha::mostrarStatus(Heroi *heroi, Inimigo *inimigo){
    cout << endl;
    cout << inimigo->getNome() << endl;
    cout << "Energia: ";
    for(int i = 0; i < inimigo->getEnergia(); i++){
        cout << "#";
    }

    cout << "\n\n";
    cout << heroi->getNome() << endl;
    cout << "Energia: ";
    for(int i = 0; i < heroi->getEnergia(); i++){
        cout << "#";
    }
    cout << endl;
    cout << endl;

}

bool Batalha::run(){
    bool batalhaFinalizada = false;

    while(batalhaFinalizada == false){
        //Inicia turno
        bool usuarioFezEscolha = false;
        while (usuarioFezEscolha == false){
            mostrarStatus(heroi, inimigo);
            exibirOpcoes();
            switch (userInput.rangedReadNumber(1, 2))
            {
            case 1:
                {
                usuarioFezEscolha = true;
                cout << "Voce tenta atacar seu inimigo, e..." << endl;
                int testeHeroi = heroi->testeDeAtaque(perguntaQuerUtilizarSorte());
                int testeInimigo = inimigo->testeDeAtaque(rand() % 2);
                int diferenca = abs(testeHeroi - testeInimigo);
                if(testeHeroi >= testeInimigo){
                    //heroi vence teste
                    cout << "Voce acerta!" << "(" << diferenca << " de dano)" << endl;
                    inimigo->removerEnergia(diferenca);
                } else {
                    //inimigo vence teste
                    cout << "O seu inimigo é mais habilidoso, desviando do seu ataque e acertando-o ";
                    cout << "(" << diferenca << " de dano)" << endl;
                    heroi->removerEnergia(diferenca);
                }
                if(heroi->getEnergia() <= 0 || inimigo->getEnergia() <= 0){
                    batalhaFinalizada = true;
                }
                }
                break;
            case 2:
                heroi->mostrarInventario();
                break;
            default:
                break;
            }
        }
    }
    if(heroi->getEnergia() <= 0){
        return false;
    } else {
        return true;
    }

}


