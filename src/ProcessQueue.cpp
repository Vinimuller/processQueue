#include "../inc/classes/ProcessQueue.h"
#include <iostream>
#include <cstdlib>

// Node structure (templated)
template <typename T>
struct Node {
    T data;
    Node* next;
};

// FIFO Queue class (templated)
template <typename T>
class FIFO {
private:
    Node<T>* front;
    Node<T>* rear;

    uint32_t size = 0;

public:
    // Constructor
    FIFO() {
        front = rear = nullptr;
    }

    // Destructor
    ~FIFO() {
        while (front != nullptr) {
            pop();
        }
    }

    // Push method — adds a value to the end of the queue
    void push(const T& value) {
        Node<T>* newNode = new Node<T>();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Pop method — removes and returns the value from the front of the queue
    T pop() {
        if (front == nullptr) {
            throw std::underflow_error("Queue underflow. Cannot pop from an empty queue.");
        }

        Node<T>* temp = front;
        T value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return value;
    }

    // Search method — returns true if value is found, false otherwise
    bool search(const T& value) const {
        Node<T>* current = front;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Display the queue (for debugging)
    void display() const {
        Node<T>* current = front;
        while (current != nullptr) {
            std::cout << *current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    uint32_t getSize(){
        return size;
    }
};

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

        virtual uint8_t execute(){
            std::cout << "executando generico" << std::endl;
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

class Process_Gravacao : public Process {
    public:

        Process_Gravacao(const uint32_t _pid) : Process(_pid) {}
        ~Process_Gravacao(){}

        uint8_t execute() override {
            std::cout << getPID() << " executando gravacao" << std::endl;
            return 0;
        }
};

class Process_Impressao : public Process {
    public:
        Process_Impressao(const uint32_t _pid) : Process(_pid) {}
        ~Process_Impressao(){}

        uint8_t execute() override{
            std::cout << getPID() << " executando impressao" << std::endl;
            return 0;
        }
};

uint8_t executePID(FIFO<Process*> processQueue, uint32_t _pid){
    // std::cout << "\n\n" << "------- Execute PID -------" << "\n\n";
    
    uint32_t size = processQueue.getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;
    
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

// Example usage
int main() {
    std::cout << "\n\n" << "------- Start -------" << "\n\n";

    Process* processo1 = new Process_Gravacao(1);
    Process* processo2 = new Process_Impressao(2);
    Process* processo3 = new Process_Impressao(3);

    FIFO<Process*> processQueue;

    processQueue.push(processo1);
    processQueue.push(processo2);
    processQueue.push(processo3);
    processQueue.push(new Process_Impressao(4));
    processQueue.push(new Process_Impressao(5));
    processQueue.push(new Process_Impressao(6));


    executePID(processQueue, 4);

    return 0;
}
