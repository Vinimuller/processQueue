#pragma once
#include "Process.h"

class Computing_Process : public Process {
    public:

        Computing_Process(){}

        Computing_Process(std::string _expression, const uint32_t _pid) 
            : Process(_pid),
            expression(_expression){}

        ~Computing_Process(){};

        uint8_t execute();

        bool verifyExpression(std::string line);
    private:
        std::string expression;
        ComputationData computationData;

        ComputationData parseLineContent(std::string line);

        double runComputation(ComputationData computationData);
};