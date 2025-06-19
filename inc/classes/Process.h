#pragma once
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include "FIFO.h"

#define COMPUTING_PROCESS 1
#define PRINTING_PROCESS 2
#define READING_PROCESS 3
#define WRITING_PROCESS 4

class Process{
    public:
        // Constructor

        Process(){};

        Process(const uint32_t _pid) {
            pid = _pid;
        }

        // Destructor
        virtual ~Process() {

        }

        uint32_t getPID(){
            return pid;
        }

        virtual uint8_t execute() = 0;
        
        //Get process type
        virtual uint8_t getType() = 0;

        //Get more process info
        virtual std::string getInfo() = 0;

        // Cast operator to std::string
        operator std::string() const {
            return std::to_string(pid);
        }

        // Stream operator for Process
        friend std::ostream& operator<<(std::ostream& os, Process& p){
            os << p.getPID();
            return os;
        }

    private:
        uint32_t pid;
};
