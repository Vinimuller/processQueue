#pragma once
#include "Process.h"
#include "Arquivos.h"

class Writing_Process : public Process, public Arquivos{
    public:

        Writing_Process(){}

        Writing_Process(std::string _expression, const uint32_t _pid)
            : expression(_expression),
              fileName("computation"),
              Process(_pid){}
        
        ~Writing_Process(){}

        uint8_t execute(){
            std::cout << "-- Executando Writing_Process (pid: " << getPID() << ") --"<< std::endl;
            std::cout << "Expressao: " << expression << std::endl;
            // abrir arquivo em modo append
            // salva expression no arquivo como nova linha
            return escreverArquivo(fileName, expression + "\n");
        }

        uint8_t getType(){
            return WRITING_PROCESS;
        }

        std::string getInfo(){
            return "Arquivo utilizado: " + fileName;
        }

    private:
        std::string expression;
        std::string fileName;
};

