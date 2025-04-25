#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class UserInput {
public:
    // Lê um número inteiro do usuário
    int readNumber();

    //Lê um número inteiro do usuário desde que ele esteja dentro do intervalo especificado
    int rangedReadNumber(int min, int max);

    // Lê uma string do usuário
    string readString();
};


#endif
