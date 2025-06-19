#include "../inc/classes/PrintingProcess.h"

uint8_t Printing_Process::execute(){
    std::cout << getPID() << " executando Printing_Process" << std::endl;

    processQueue->display();

    /*
    (PrintingProcess): tem por objetivo simplesmente imprimir na tela o pool de processos a
    serem executados. Imprimindo o pid, o tipo do processo e atributos relacionados, se for o caso.
    */

    return 0;
}