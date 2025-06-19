#include "../inc/classes/WritingProcess.h"

uint8_t Writing_Process::execute(){
    std::cout << "-- Executando Writing_Process (pid: " << getPID() << ") --"<< std::endl;
    std::cout << "Expressao: " << expression << std::endl;
    // abrir arquivo em modo append
    // salva expression no arquivo como nova linha
    return escreverArquivo(fileName, expression + "\n");
}