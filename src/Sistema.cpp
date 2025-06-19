#include"../inc/classes/Sistema.h"
#include <sstream>

Sistema::Sistema(){
    processQueue = new FIFO<Process*>();
    ids = 0;
}

uint8_t Sistema::executePID(FIFO<Process*> *processQueue, uint32_t _pid){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    //Procura por toda fifo.
    for(uint32_t i = 0; i < size; i++){
        temp = processQueue->pop();
        if(temp->getPID() != _pid){
            //Não é o pid, devolve pra fila
            processQueue->push(temp);
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

uint8_t Sistema::executeNextProcess(FIFO<Process*> *processQueue){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue->display();

    temp = processQueue->pop();
    temp->execute();
    delete temp;

    return result;
}

int Sistema::generateNewID(){
    return ++ids;
}

void Sistema::criarProcesso(){
    arquivos.exibirCena("menu-criarProc");
    int processoEscolhido = userInput.rangedReadNumber(1,5);
    bool processoFinalizado = false;
    tela.limpaTerminal();
    while(processoFinalizado == false){
        switch (processoEscolhido)
        {
        case COMPUTING_PROCESS:
            {
            cout << "Insira a expressao a ser computada:" << endl;
            string newExpression;
            getline(cin >> ws, newExpression);
            if(computingProcess.verifyExpression(newExpression)){
                processQueue->push(new Computing_Process(newExpression, generateNewID()));
                processoFinalizado = true;
                cout << "Expressão inserida com sucesso" << endl;
            } else {
                cout << "Expressão inválida" << endl;
            }
            break;
            }
        case PRINTING_PROCESS:
            {
                processQueue->push(new Printing_Process(processQueue, generateNewID()));
                processoFinalizado = true;
            }
            break;
        case READING_PROCESS:
            {
                processQueue->push(new Reading_Process(processQueue, generateNewID()));
                processoFinalizado = true;
            break;
            }
        case WRITING_PROCESS:
            {
                cout << "Insira a expressao escrita no arquivo:" << endl;
                string newExpression;
                getline(cin >> ws, newExpression);
                if(computingProcess.verifyExpression(newExpression)){
                    processQueue->push(new Writing_Process(newExpression, generateNewID()));
                    processoFinalizado = true;
                } else {
                    cout << "Expressão inválida" << endl;
                }
                break;
            }
        default:
            return;
            break;
        }
    }
    tela.limpaTerminal();
    cout << "Processo adicionado à fila!" << endl;
    tela.aguarde();
}

void Sistema::executarProximo(){
    if(processQueue->getSize() == 0){
        cout << "Fila de processos vazia..." << endl;
        tela.aguarde();
        return;
    }
    Process* temp = nullptr;

    std::cout << std::endl;
    processQueue->display();

    temp = processQueue->pop();
    temp->execute();
    delete temp;
    tela.aguarde();
}

void Sistema::executarProcessoEspecifico(){
    cout << "Insira pid do processo especifico:" << endl;;
    uint32_t pidEspecifico;
    cin >> pidEspecifico;
    
    FIFO<Process*> *temporaryQueue = new FIFO<Process*>();

    bool processoEncontrado = false;

    int tamanhoProcessQueue = processQueue->getSize();

    for(int i = 0; i < tamanhoProcessQueue; i++){
        Process* temp = processQueue->getFront();

        if(temp->getPID() == pidEspecifico){
            executarProximo();
            processoEncontrado = true;
        } else {
            temporaryQueue->push(processQueue->pop());
        }
    }

    if(processoEncontrado == false){
      cout << "Processo não encontrado" << endl; 
      cin.get(); 
    } 

    processQueue = temporaryQueue;

    tela.aguarde();
}

bool Sistema::salvarFilaDeProcessos(){
    std::string filename = "telas/queue.txt";
     std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    processQueue->display();

    //Procura por toda fifo.
    for(uint32_t i = 0; i < size; i++){
        temp = processQueue->pop();

        file << temp->getType() << "|"
            << temp->getPID() << "|"
            << temp->getInfo() << std::endl;

        processQueue->push(temp);
    }

    file.close();
    std::cout << "Queue saved to " << filename << "\n";
    cin.get(); 

    return true;
}

void createProcess(FIFO<Process*> *processQueue, int type, uint32_t pid, std::string data){
    std::istringstream  iss(data);
    std::string         token;
     switch (type){
        case COMPUTING_PROCESS:
            iss >> token;
            iss >> token;
            std::cout << "Loded Computing process | PID: " << pid << " Exp: " << token << std::endl;
            processQueue->push(new Computing_Process(token, pid));
            break;
        case PRINTING_PROCESS:
            std::cout << "Loded Printing process | PID: " << pid << std::endl;
            processQueue->push(new Printing_Process(processQueue, pid));
            break;
        case READING_PROCESS:
            std::cout << "Loded Reading process | PID: " << pid << std::endl;
            processQueue->push(new Reading_Process(processQueue, pid));
            break;
        case WRITING_PROCESS:
            iss >> token;
            iss >> token;
            std::cout << "Loded Writing process | PID: " << pid << " Exp: " << token << std::endl;
            processQueue->push(new Writing_Process(token, pid));
            break;
        default:
            std::cout << " TIPO NAO IDENTIFICADO " << std::endl;
            break;
        }

}

bool Sistema::carregarFilaDeProcessos(){

    std::string filename = "telas/queue.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    processQueue->display();

    std::string content((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
    
    std::string buff = "";
    for(size_t i=0; i < content.length(); i++){
        if(content[i] != '\n'){
            buff += content[i];
        }else{
            std::istringstream iss(buff);
            std::string token;

            std::getline(iss, token, '|');
            char type = (token.c_str()[0]);
            
            std::getline(iss, token, '|');
            uint32_t pid = std::stoi(token);

            std::getline(iss, token, '|');
            std::string data = token;

            // std::cout << "type: " << type << " pid: " << pid << " data " << data << std::endl;
            buff = "";

            createProcess(processQueue, type, pid, data);
        }
    }

    file.close();
    processQueue->display();
    std::cout << "Queue loaded from " << filename << "\n";
    cin.get(); 

    return true;
}