#pragma once
#include "Process.h"
#include "Arquivos.h"

class Writing_Process : public Process, public Arquivos{
    public:

        Writing_Process(){}

        Writing_Process(std::string _expression, const uint32_t _pid)
            : Process(_pid),
            expression(_expression),
            fileName("computation"){}
        
        ~Writing_Process(){}

        uint8_t execute();

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

