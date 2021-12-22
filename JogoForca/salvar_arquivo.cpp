#include <iostream>
#include <fstream>
#include "salvar_arquivo.hpp"

namespace Forca {
    void salvar_arquivo(const std::vector<std::string>& nova_lista) {
        std::ofstream arquivo;
        arquivo.open("palavras.txt");
        if (arquivo.is_open()) {
            arquivo << nova_lista.size() << std::endl;
            for (std::string palavra : nova_lista) {
                arquivo << palavra << std::endl;
            }
            arquivo.close();
        }
        else {
            std::cout << "Nao foi possivel acessar o banco de palavrars. " << std::endl;
            exit(0);
        }
    }
}