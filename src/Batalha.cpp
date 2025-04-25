#include "../inc/classes/Batalha.h"

Batalha::Batalha(Personagem *heroi, Personagem *inimigo){
    this->heroi = heroi;
    this->inimigo = inimigo;
}

void Batalha::exibirOpcoes(){
    cout << "1. Atacar" << endl;
    cout << "2. Acessar Inventario" << endl;
}

int Batalha::escolhaDoUsuario(){
    //Aqui é possível melhorar se optar por utilizar leitura de arquivo para opcoes

}

bool Batalha::perguntaQuerUtilizarSorte(){
    cout << "Deseja utilizar sorte? (" << heroi->getSorte() << "ponto(s) de sorte restante(s))";
    cout << "1. Sim" << endl;
    cout << "2. Não" << endl;
    if(userInput.rangedReadNumber(1,2) == 1){
        return true;
    }
}

bool Batalha::run(){
    bool batalhaFinalizada = false;

    while(batalhaFinalizada == false){
        //Inicia turno
        bool usuarioFezEscolha = false;
        while (usuarioFezEscolha = false){
            exibirOpcoes();
            switch (userInput.rangedReadNumber(1, 2))
            {
            case 1:
            usuarioFezEscolha = true;
                cout << "Você tenta atacar seu inimigo, e..." << endl;
                int testeHeroi = heroi->testeDeAtaque(perguntaQuerUtilizarSorte());
                int testeInimigo = inimigo->testeDeAtaque(rand() % 2);
                int diferenca = abs(testeHeroi - testeInimigo);
                if(testeHeroi >= testeInimigo){
                    //heroi vence teste
                    cout << "Você acerta!" << "(" << diferenca << "de dano)" << endl;
                    inimigo->removerEnergia(diferenca);
                } else {
                    //inimigo vence teste
                    cout << "O seu inimigo é mais habilidoso, desviando do seu ataque e acertando-o ";
                    cout << "(" << diferenca << " de dano)" << endl;
                }
                if(heroi->getEnergia() <= 0 || inimigo->getEnergia() <= 0){
                    batalhaFinalizada = true;
                }
                break;
            case 2:
                //heroi.acessaInventario();
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


