#include "../inc/classes/DungeonUtils.h"

DungeonUtils::DungeonUtils(){}

void DungeonUtils::limparTerminal(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems (Linux, macOS)
    #endif
}