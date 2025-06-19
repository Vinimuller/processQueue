#pragma once
#include "Process.h"

class Printing_Process : public Process {
    public:

        Printing_Process(){}

        Printing_Process(FIFO<Process*> *_processQueue, const uint32_t _pid) 
            : processQueue(_processQueue),
              Process(_pid) {}

        ~Printing_Process(){}

        uint8_t execute(){
            std::cout << getPID() << " executando Printing_Process" << std::endl;

            processQueue->display();

            /*
            (PrintingProcess): tem por objetivo simplesmente imprimir na tela o pool de processos a
            serem executados. Imprimindo o pid, o tipo do processo e atributos relacionados, se for o caso.
            */

            return 0;
        }

    private:
        FIFO<Process*> *processQueue;
};