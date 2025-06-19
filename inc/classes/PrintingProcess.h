#pragma once
#include "Process.h"

class Printing_Process : public Process {
    public:
        Printing_Process(){}
        Printing_Process(FIFO<Process*> *_processQueue, const uint32_t _pid) 
            : Process(_pid),
            processQueue(_processQueue){}

        ~Printing_Process(){}

        uint8_t execute();

        uint8_t getType(){
            return PRINTING_PROCESS;
        }

        std::string getInfo(){
            return "";
        }

    private:
        FIFO<Process*> *processQueue;

        void printProcess(Process* process);
};