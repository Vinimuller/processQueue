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

//     processQueue.push(new Writing_Process("20-5", 4));
//     processQueue.push(new Reading_Process(processQueue, 5));

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
    return true;
}

bool Sistema::carregarFilaDeProcessos(){
    return true;
}