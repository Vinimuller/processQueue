#include "../inc/classes/UserInput.h"

// Lê um número inteiro do usuário
int UserInput::readNumber() {
    int number;
    while (true) {
        cin >> number;

        if (cin.fail()) {
            cin.clear(); // limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada inválida
            cout << "Entrada inválida. Tente novamente.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa qualquer sobra no buffer
            return number;
        }
    }
}


int UserInput::rangedReadNumber(int min, int max) {
    int number;
    while (true) {
        cin >> number;

        if (cin.fail() || number < min || number > max) {
            cin.clear(); // limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada inválida
            cout << "Entrada inválida. Tente novamente.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa qualquer sobra no buffer
            return number;
        }
    }
}

// Lê uma string do usuário
string UserInput::readString() {
    string input;
    getline(cin, input);
    return input;
}

