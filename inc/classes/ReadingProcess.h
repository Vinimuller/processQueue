#pragma once
#include "Process.h"
#include "Arquivos.h"
#include "ComputingProcess.h"

class Reading_Process : public Process, public Arquivos {
    public:

        Reading_Process(){}
    
        Reading_Process(FIFO<Process*> *_processQueue, const uint32_t _pid) 
            : Process(_pid),
            processQueue(_processQueue),
            fileName("computation") {} 
        
        ~Reading_Process(){}

        uint8_t execute();
    private:
        FIFO<Process*> *processQueue;
        std::string fileName;
};