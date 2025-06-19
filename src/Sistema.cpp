#include"../inc/classes/Sistema.h"

Sistema::Sistema(){
    processQueue = new FIFO<Process*>();
    ids = 0;
}

uint8_t Sistema::executePID(FIFO<Process*> *processQueue, uint32_t _pid){
    // std::cout << "\n\n" << "------- Execute PID ------- " << _pid << "\n\n";
    
    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;
    
    // processQueue.display();

    //Procura por toda fifo.
    for(int i = 0; i < size; i++){
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
    
    uint32_t size = processQueue->getSize();
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue->display();

    temp = processQueue->pop();
    temp->execute();
    delete temp;

    return result;
}

//     processQueue.push(new Writing_Process("20-5", 4));
//     processQueue.push(new Reading_Process(processQueue, 5));

int Sistema::generateNewID(){
    return ++ids;
}

void Sistema::criarProcesso(){
    arquivos.exibirCena("menu-criarProc");
    int processoEscolhido = userInput.rangedReadNumber(1,4);
    bool processoFinalizado = false;
    while(processoFinalizado == false){
        switch (processoEscolhido)
        {
        case COMPUTING_PROCESS:
            {
            cout << "Insira a expressao a ser computada:" << endl;
            bool expressaoCorreta = false;
            string newExpression;
            getline(cin >> ws, newExpression);
            if(computingProcess.verifyExpression(newExpression)){
                cout << "Entrou no if" << endl;
                processQueue->push(new Computing_Process(newExpression, generateNewID()));
                cout << "Deu push na fila" << endl;
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
                bool expressaoCorreta = false;
                string newExpression;
                getline(cin >> ws, newExpression);
                if(computingProcess.verifyExpression(newExpression)){
                    processQueue->push(new Writing_Process(newExpression, generateNewID()));
                    processoFinalizado = true;
                }
                break;
            }
        default:
            break;
        }
    }
    cout << "Processo adicionado à fila!" << endl;
}

void Sistema::executarProximo(){
    uint32_t size = processQueue->getSize();
    if(size == 0){
        cout << "Fila de processos vazia..." << endl;
        return;
    }
    Process* temp = nullptr;
    uint8_t  result = 1;

    std::cout << std::endl;
    processQueue->display();

    temp = processQueue->pop();
    temp->execute();
    delete temp;
}

void Sistema::executarProcessoEspecifico(){
    cout << "Insira pid do processo especifico:" << endl;;
    int pidEspecifico;
    cin >> pidEspecifico;
    
    FIFO<Process*> *temporaryQueue = new FIFO<Process*>();

    bool processoEncontrado = false;

    for(uint32_t i = 0; i < processQueue->getSize(); i++){
        Process* temp = processQueue->getFront();
        if(temp->getPID() == pidEspecifico){
            executarProximo();
            processoEncontrado = true;
        } else {
            temporaryQueue->push(processQueue->pop());
        }
    }

    if(processoEncontrado == false) cout << "Processo não encontrado" << endl;

    processQueue = temporaryQueue;
}

bool Sistema::salvarFilaDeProcessos(){
    return true;
}

bool Sistema::carregarFilaDeProcessos(){
    return true;
}