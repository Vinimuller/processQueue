#pragma once
#include "Process.h"
#include "Arquivos.h"
#include "ComputingProcess.h"

class Reading_Process : public Process, public Arquivos {
    public:
        Reading_Process(FIFO<Process*> *_processQueue, const uint32_t _pid) 
            : processQueue(_processQueue),
              fileName("computation.txt"),
              Process(_pid) {} 
        
        ~Reading_Process(){}

        uint8_t execute(){
            std::cout << "-- Executando Reading_Process (pid: " << getPID() << ") --"<< std::endl;
            
            std::string content = lerArquivo(fileName);

            //limparArquivo(fileName); Implementar remoção da pid específica de dentro do arquivo

            std::string buff = "";
            for(int i=0; i < content.length(); i++){
                if(content[i] != '\n'){
                    buff += content[i];
                }else{
                    std::cout << "Expression " << buff << " pushed to process queue " << std::endl;
                    processQueue->push(new Computing_Process(buff + '\n', processQueue->getSize()+1));
                    buff = "";
                }
            }
            return 0;
        }
    private:
        FIFO<Process*> *processQueue;
        std::string fileName;
};