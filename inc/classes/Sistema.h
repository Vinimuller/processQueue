#pragma once
#include "ComputingProcess.h"
#include "PrintingProcess.h"
#include "ReadingProcess.h"
#include "WritingProcess.h"
#include "UserInput.h"
#include "Arquivos.h"

class Sistema{
public:
    Sistema();
    void criarProcesso();
    void executarProximo();
    void executarProcessoEspecifico();
    bool salvarFilaDeProcessos();
    bool carregarFilaDeProcessos();

private:

    FIFO<Process*> *processQueue;
    Computing_Process computingProcess;
    Printing_Process printingProcess;
    Reading_Process readingProcess;
    Writing_Process writingProcess;

    Arquivos arquivos;
    UserInput userInput;

    uint8_t executePID(FIFO<Process*> &processQueue, uint32_t _pid);
    uint8_t executeNextProcess(FIFO<Process*> &processQueue);

    int generateNewID();
    int ids;
};

#define COMPUTING_PROCESS 1
#define PRINTING_PROCESS 2
#define READING_PROCESS 3
#define WRITING_PROCESS 4

uint8_t Sistema::executePID(FIFO<Process*> &processQueue, uint32_t _pid){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue.getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;
    
    // processQueue.display();

    //Procura por toda fifo.
    for(int i = 0; i < size; i++){
        temp = processQueue.pop();
        if(temp->getPID() != _pid){
            //Não é o pid, devolve pra fila
            processQueue.push(temp);
        }else{
            //É o PID. Executa
            temp->execute();
            delete temp;
            result = 0;
        }
    }

    // 1 -> processo não encontrado
    // 0 -> processo executado
    return result;
}

uint8_t Sistema::executeNextProcess(FIFO<Process*> &processQueue){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue.getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue.display();

    temp = processQueue.pop();
    temp->execute();
    delete temp;

    return result;
}

//     processQueue.push(new Writing_Process("20-5", 4));
//     processQueue.push(new Reading_Process(processQueue, 5));

int Sistema::generateNewID(){
    return ++ids;
}

void Sistema::criarProcesso(){
    arquivos.exibirCena("menu-criarProc");
    int processoEscolhido;
    cin >> processoEscolhido;
    bool processoFinalizado = false;
    while(processoFinalizado == false){
        switch (processoEscolhido)
        {
        case COMPUTING_PROCESS:
            {
            cout << "Insira a expressao a ser computada:" << endl;
            cin.get();
            bool expressaoCorreta = false;
            string newExpression;
            getline(cin, newExpression);
            if(computingProcess.verifyExpression(newExpression)){
                processQueue->push(new Computing_Process(newExpression, generateNewID()));
                processoFinalizado = true;
            }
            break;
            }
        case PRINTING_PROCESS:
            {
                processQueue->push(new Printing_Process(processQueue, generateNewID()));
                processoFinalizado = true;
            }
            break;
        case READING_PROCESS:
            {
                processQueue->push(new Reading_Process(processQueue, generateNewID()));
                processoFinalizado = true;
            break;
            }
        case WRITING_PROCESS:
            {
                cout << "Insira a expressao a ser computada:" << endl;
                cin.get();
                bool expressaoCorreta = false;
                string newExpression;
                getline(cin, newExpression);
                if(computingProcess.verifyExpression(newExpression)){
                    processQueue->push(new Writing_Process(newExpression, generateNewID()));
                    processoFinalizado = true;
                }
            }
            break;
        default:
            break;
        }
    }
}

void Sistema::executarProximo(){
    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue->display();

    temp = processQueue->pop();
    temp->execute();
    delete temp;
}

void Sistema::executarProcessoEspecifico(){
    cout << "Insira pid do processo especifico";
    int pidEspecifico;
    cin >> pidEspecifico;
    
    FIFO<Process*> *temporaryQueue = new FIFO<Process*>();

    for(uint32_t i = 0; i < processQueue->getSize(); i++){
        Process* temp = processQueue->getFront();
        if(temp->getPID() == pidEspecifico){
            executarProximo();
        } else {
            temporaryQueue->push(temp);
        }
    }
    processQueue = temporaryQueue;
}

