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
    uint8_t executeNextProcess(FIFO<Process*> *processQueue);

    int generateNewID();
    int ids;
};

#define COMPUTING_PROCESS 1
#define PRINTING_PROCESS 2
#define READING_PROCESS 3
#define WRITING_PROCESS 4

