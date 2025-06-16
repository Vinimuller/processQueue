#include <iostream>
#include <cstdlib>
#include "../include/Arquivos.h"

// Node structure (templated)
template <typename T>
struct Node {
    T data;
    Node* next;
};

struct ComputationData {
    char op;
    int operand1;
    int operand2;
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
        std::cout << "FIFO: ";
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

class Computing_Process : public Process {
    public:

        Computing_Process(std::string _expression, const uint32_t _pid) 
            : expression(_expression),
              Process(_pid) {}

        ~Computing_Process(){}

        uint8_t execute() override {
            std::cout << "-- Executando Computing_Process (pid: " << getPID() << ") --"<< std::endl;
            // parse da expressao
            ComputationData computationData = parseLineContent(expression);
            // executa expressao
            double result = runComputation(computationData);

            std::cout << computationData.operand1  
                            << computationData.op 
                            << computationData.operand2  
                            << " = " 
                            << result  
                            << std::endl;
            /*
            (ComputingProcess): executa o cálculo de uma expressão e imprime o resultado do cálculo.
            Uma expressão é formada por dois operandos e uma operação (que pode ser +, -, * ou /). A expressão deve saber
            como se executar. Por exemplo, se é uma soma, então o resultado do cálculo é a soma dos dois operandos.
            */

            return 0;
        }
    private:
        std::string expression;
        ComputationData computationData;

        ComputationData parseLineContent(std::string line){
            ComputationData computationData;

            // Parse the line (assuming format: number1 operator number2)
            size_t op_pos = line.find_first_of("+-*/");
            if (op_pos == std::string::npos) {
                std::cerr << "Invalid operation format: " << line << "\n";
            }

            try {
                computationData.operand1 = std::stoi(line.substr(0, op_pos));
                computationData.operand2 = std::stoi(line.substr(op_pos + 1));
                computationData.op = line[op_pos];
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << " (" << e.what() << ")\n";
            }
            return computationData;
        }

        double runComputation(ComputationData computationData){
            // Perform the operation
            double result = 0;
            switch (computationData.op) {
                case '+':
                    result = computationData.operand1 + computationData.operand2;
                    break;
                case '-':
                    result = computationData.operand1 - computationData.operand2;
                    break;
                case '*':
                    result = computationData.operand1 * computationData.operand2;
                    break;
                case '/':
                    if (computationData.operand2 == 0) {
                        std::cout << "Division by zero" << "\n";
                    }
                    result = computationData.operand1 / (double)computationData.operand2;
                    break;
                default:
                    std::cout << "Unknown operator\n";
            }
            return result;
        }
};

class Writing_Process : public Process, public Arquivos{
    public:
        Writing_Process(std::string _expression, const uint32_t _pid)
            : expression(_expression),
              fileName("computation.txt"),
              Process(_pid){}
        
        ~Writing_Process(){}

        uint8_t execute() override{
            std::cout << "-- Executando Writing_Process (pid: " << getPID() << ") --"<< std::endl;
            std::cout << "Expressao: " << expression << std::endl;
            // abrir arquivo em modo append
            // salva expression no arquivo como nova linha
            return escreverArquivo(fileName, expression + "\n");
        }

    private:
        std::string expression;
        std::string fileName;
};

class Reading_Process : public Process, public Arquivos {
    public:
        Reading_Process(FIFO<Process*> &_processQueue, const uint32_t _pid) 
            : processQueue(_processQueue),
              fileName("computation.txt"),
              Process(_pid) {} 
        
        ~Reading_Process(){}

        uint8_t execute() override{
            std::cout << "-- Executando Reading_Process (pid: " << getPID() << ") --"<< std::endl;
            
            std::string content = lerArquivo(fileName);

            limparArquivo(fileName);

            std::string buff = "";
            for(int i=0; i < content.length(); i++){
                if(content[i] != '\n'){
                    buff += content[i];
                }else{
                    std::cout << "Expression " << buff << " pushed to process queue " << std::endl;
                    processQueue.push(new Computing_Process(buff + '\n', processQueue.getSize()+1));
                    buff = "";
                }
            }


                /*
                    (ReadingProcess): deve ler completamente o arquivo de computações (computation.txt) e,
                    para cada registro lido do arquivo deve criar um objeto de processo de cálculo (ComputingProcess) e adicioná-lo
                    na lista de processos do sistema. Ao final da leitura, o processo deve “limpar” o arquivo. Vale lembrar que cada
                    linha do arquivo é uma expressão aritmética.
                */


            return 0;
        }
    private:
        FIFO<Process*> &processQueue;
        std::string fileName;
};

class Printing_Process : public Process {
    public:
        Printing_Process(FIFO<Process*> _processQueue, const uint32_t _pid) 
            : processQueue(_processQueue),
              Process(_pid) {}

        ~Printing_Process(){}

        uint8_t execute() override{
            std::cout << getPID() << " executando Printing_Process" << std::endl;

            processQueue.display();

            /*
            (PrintingProcess): tem por objetivo simplesmente imprimir na tela o pool de processos a
            serem executados. Imprimindo o pid, o tipo do processo e atributos relacionados, se for o caso.
            */

            return 0;
        }

    private:
        FIFO<Process*> processQueue;
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

// Example usage
int main() {
    std::cout << "\n\n" << "------- Start -------" << "\n\n";

    FIFO<Process*> processQueue;
    processQueue.push(new Writing_Process("1+1", 1));
    processQueue.push(new Writing_Process("3*4", 2));
    processQueue.push(new Writing_Process("4/4", 3));
    processQueue.push(new Writing_Process("20-5", 4));
    processQueue.push(new Reading_Process(processQueue, 5));

    while(processQueue.getSize() > 0){
        executeNextProcess(processQueue);
    }

    return 0;
}
