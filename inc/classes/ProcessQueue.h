#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "FIFO.h"

class Process{
    public:
        // Constructor
        Process(const uint32_t _pid) {
            pid = _pid;
        }

        // Destructor
        ~Process() {

        }

        uint32_t getPID(){
            return pid;
        }

        uint8_t execute(){
            //execute process
            return 0;
        }

        // Cast operator to std::string
        operator std::string() const {
            return std::to_string(pid);
        }

        // Stream operator for Process
        friend std::ostream& operator<<(std::ostream& os, Process& p) {
            os << p.getPID();
            return os;
        }

    private:
        uint32_t pid;
};