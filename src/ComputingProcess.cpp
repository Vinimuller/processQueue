#include "../inc/classes/ComputingProcess.h"

uint8_t Computing_Process::execute() {
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

bool Computing_Process::verifyExpression(std::string line){
    // Parse the line (assuming format: number1 operator number2)
    size_t op_pos = line.find_first_of("+-*/");
    if (op_pos == std::string::npos) {
        std::cerr << "Invalid operation format: " << line << "\n";
        return false;
    }

    try {
        std::stoi(line.substr(0, op_pos));
        std::stoi(line.substr(op_pos + 1));
    } catch (const std::exception& e) {
        std::cerr << "Error parsing line: " << line << " (" << e.what() << ")\n";
        return false;
    }            

    return true;
}


ComputationData Computing_Process::parseLineContent(std::string line){
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

double Computing_Process::runComputation(ComputationData computationData){
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