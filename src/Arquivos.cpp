#include "../inc/classes/Arquivos.h"


void Arquivos::exibirCena(int cenaAtual) {
    std::string nomeArquivo = "textos/" + std::to_string(cenaAtual) + ".txt";
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Não foi possível abrir o arquivo da cena " << cenaAtual << ".\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::cout << linha << std::endl;
    }

    arquivo.close();
}

void Arquivos::exibirCena(string cenaAtual) {
    std::string nomeArquivo = "textos/" + cenaAtual + ".txt";
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Não foi possível abrir o arquivo da cena " << cenaAtual << ".\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::cout << linha << std::endl;
    }

    arquivo.close();
}


// Escreve conteúdo em um arquivo
bool Arquivos::escreverArquivo(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para escrita: " << filename << "\n";
        return false;
    }
    file << content;
    file.close();
    return true;
}

// Lê conteúdo de um arquivo e retorna como string
string Arquivos::lerArquivo(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para leitura: " << filename << "\n";
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

    file.close();
    return content;
}
