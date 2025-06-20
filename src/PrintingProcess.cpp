#include "../inc/classes/PrintingProcess.h"

void Printing_Process::printProcess(Process* process){
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

uint8_t Printing_Process::execute(){
    std::cout << "-- Executando Printing_Process (pid: " << getPID() << ") --"<< std::endl;

    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;

    //Procura por toda fifo.
    for(uint32_t i = 0; i < size; i++){
        temp = processQueue->pop();

        printProcess(temp);

        processQueue->push(temp);

    }
    return 0;
}