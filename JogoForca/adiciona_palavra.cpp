#include <iostream>
#include <string>
#include "adiciona_palavra.hpp"
#include "le_arquivo.hpp"
#include "salvar_arquivo.hpp"

void Forca::adiciona_palavra(){
    std::cout << "Digite a nova palavra, usando letras maiusculas. " << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;
    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    salvar_arquivo(lista_palavras);
}