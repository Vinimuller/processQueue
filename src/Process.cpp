#include <iostream>
#include <cstdlib>
#include "../inc/classes/Process.h"

class Process{
    public:
        // Constructor
        Process(const uint32_t _pid) {
            pid = _pid;
        }

        // Destructor
        virtual ~Process() {

        }

        uint32_t getPID(){
            return pid;
        }

        virtual uint8_t execute();

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


uint8_t executePID(FIFO<Process*> &processQueue, uint32_t _pid){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue.getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;
    
    // processQueue.display();

    //Procura por toda fifo.
    for(int i = 0; i < size; i++){
        temp = processQueue.pop();
        if(temp->getPID() != _pid){
            //Não é o pid, devolve pra fila
            processQueue.push(temp);
        }else{
            //É o PID. Executa
            temp->execute();
            delete temp;
            result = 0;
        }
    }

    // 1 -> processo não encontrado
    // 0 -> processo executado
    return result;
}

uint8_t executeNextProcess(FIFO<Process*> &processQueue){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue.getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue.display();

    temp = processQueue.pop();
    temp->execute();
    delete temp;

    return result;
}

// // Example usage
// int main() {
//     std::cout << "\n\n" << "------- Start -------" << "\n\n";

//     FIFO<Process*> processQueue;
//     processQueue.push(new Writing_Process("1+1", 1));
//     processQueue.push(new Writing_Process("3*4", 2));
//     processQueue.push(new Writing_Process("4/4", 3));
//     processQueue.push(new Writing_Process("20-5", 4));
//     processQueue.push(new Reading_Process(processQueue, 5));

//     while(processQueue.getSize() > 0){
//         executeNextProcess(processQueue);
//     }

//     return 0;
// }
