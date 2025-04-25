#ifndef CRIACAO_DE_PERSONAGEM_H
#define CRIACAO_DE_PERSONAGEM_H

#include <string>
#include "Heroi.h"
#include "UserInput.h"

using namespace std;

class CriacaoDePersonagem {
public:
    // Construtor
    CriacaoDePersonagem();

    void run(Heroi *heroi);

private:
    UserInput userInput;

};

#endif // CRIACAO_DE_PERSONAGEM_H