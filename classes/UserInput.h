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

    // Lê uma string do usuário
    string readString();
};


#endif
