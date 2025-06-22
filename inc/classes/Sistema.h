#pragma once
#include "ComputingProcess.h"
#include "PrintingProcess.h"
#include "ReadingProcess.h"
#include "WritingProcess.h"
#include "UserInput.h"
#include "Arquivos.h"
#include "Tela.h"

class Sistema{
public:
    Sistema();
    ~Sistema() = default;
    void criarProcesso();
    void executarProximo();
    void executarProcessoEspecifico();
    bool salvarFilaDeProcessos();
    bool carregarFilaDeProcessos();
    
private:
    FIFO<Process*> *processQueue;
    Computing_Process computingProcess;

    Arquivos arquivos;
    UserInput userInput;
    Tela tela;

    uint8_t executePID(FIFO<Process*> *processQueue, uint32_t _pid);
    void createProcess(FIFO<Process*> *processQueue, int type, uint32_t pid, std::string data);

    int generateNewID();
    int ids;
};

