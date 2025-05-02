#include "../inc/classes/CriacaoDePersonagem.h"

// Construtor
CriacaoDePersonagem::CriacaoDePersonagem() {
    // Inicialização, se necessário
}

void CriacaoDePersonagem::run(Heroi *heroi) {
    
	//string nome;
	// int energia;
	// int sorte;
	// int habilidade;
	// int quantidadeDeProvisoes;

    dungeonUtils.limparTerminal();

    std::cout << "=== Criação de Personagem ===" << endl;
    

    std::cout << "Digite o nome do herói: ";
    heroi->setNome(userInput.readString());
    cout << heroi->getNome() << endl;
    std::cout << endl;
    
    bool distribuicaoDePontosFinalizada = false;
    int pontosParaDistribuir = 12;
    std::cout << "Você tem 12 pontos para distribuir entre seus atributos!" << endl;
    std::cout << "Escolha qual atributo você quer digitando o número dele e pressionando a tecla (enter)" << endl;
    std::cout << "Então escreva a quantidade de pontos quer adicionar naquele atributo\n"<< endl ;

    while(distribuicaoDePontosFinalizada == false){
    std::cout << "Valor atual de Energia: " << heroi->getEnergia() << endl;
    std::cout << "Valor atual de Habilidade: " << heroi->getHabilidade() << endl;
    std::cout << "Valor atual de Sorte: " << heroi->getSorte() << endl;

    std::cout << " Adicionar valor em: " << endl;
    std::cout << "> 1 Energia "<< endl;
    std::cout << "> 2 Habilidade: "<< endl;
    std::cout << "> 3 Sorte: " << endl;

    std::cout << "Pontos para distribuicao restantes: " << pontosParaDistribuir << endl;

    int opcao = userInput.rangedReadNumber(1,3);
    int valorAdicionar = 0;
    if(opcao == 1){
        valorAdicionar = userInput.rangedReadNumber(0, pontosParaDistribuir);
        if((valorAdicionar + heroi->getEnergia()) > 24){
         std::cout << "Valor ultrapassou o limite" << endl;
        } else {
            heroi->addEnergia(valorAdicionar);
            pontosParaDistribuir -= valorAdicionar;
        }
    } else if(opcao == 2){
        valorAdicionar = userInput.rangedReadNumber(0, pontosParaDistribuir);
        if((valorAdicionar + heroi->getHabilidade()) > 12){
         std::cout << "Valor ultrapassou o limite" << endl;
        } else {
            heroi->addHabilidade(valorAdicionar);
            pontosParaDistribuir -= valorAdicionar;

        }
    }else if(opcao == 3){
        valorAdicionar = userInput.rangedReadNumber(0, pontosParaDistribuir);
        if((valorAdicionar + heroi->getSorte()) > 12){
         std::cout << "Valor ultrapassou o limite" << endl;
        } else {
            heroi->addSorte(valorAdicionar);
            pontosParaDistribuir -= valorAdicionar;

        }
    }
    if(pontosParaDistribuir == 0){
        distribuicaoDePontosFinalizada = true;
    }
    
    heroi->setMaximoDeEnergia(heroi->getEnergia());

    dungeonUtils.limparTerminal();
    
    }
    std::cout << "Herói criado com sucesso!" << endl;

    }