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
            std::cout << "-- Executando Printing_Process (pid: " << getPID() << ") --"<< std::endl;

            uint32_t size = processQueue->getSize();
            Process* temp = nullptr;
            uint8_t  result = 1;          

            //Procura por toda fifo.
            for(int i = 0; i < size; i++){
                temp = processQueue->pop();

                printProcess(temp);

                processQueue->push(temp);

            }
            return 0;
        }

        uint8_t getType(){
            return PRINTING_PROCESS;
        }

        std::string getInfo(){
            return "";
        }

    private:
        FIFO<Process*> *processQueue;

        void printProcess(Process* process){
            switch(process->getType()){
                case COMPUTING_PROCESS:
                    std::cout << "-- PID: " << process->getPID() << " | Computing Process" << " | " << process->getInfo() << std::endl;
                    break;
                case PRINTING_PROCESS:
                    std::cout << "-- PID: " << process->getPID() << " | Printing Process" << std::endl;
                    break;
                case WRITING_PROCESS:
                    std::cout << "-- PID: " << process->getPID() << " | Writing Process" << "   | " << process->getInfo() << std::endl;
                    break;
                case READING_PROCESS:
                    std::cout << "-- PID: " << process->getPID() << " | Reading Process" << "   | " << process->getInfo() << std::endl;
                    break;
                default:
                    break;
            }

        }
};