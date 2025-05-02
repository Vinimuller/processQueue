#ifndef CRIACAO_DE_PERSONAGEM_H
#define CRIACAO_DE_PERSONAGEM_H

#include <string>
#include "Heroi.h"
#include "UserInput.h"
#include "DungeonUtils.h"

using namespace std;

class CriacaoDePersonagem {
public:
    // Construtor
    CriacaoDePersonagem();

    void run(Heroi *heroi);

private:
    DungeonUtils dungeonUtils;
    UserInput userInput;

};

#endif // CRIACAO_DE_PERSONAGEM_H