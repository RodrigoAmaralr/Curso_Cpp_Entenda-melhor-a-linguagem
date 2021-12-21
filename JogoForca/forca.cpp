#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

//g++ .\forca.cpp -o forca.exe ; .\forca.exe -std=c++11
//mingw32-make forca        Windows
//make forca                linux
//g++ *.cpp -o forca.exe



int main(){
    string palavra_secreta;
    map<char, bool> chutou;
    vector<char> chutes_errados;

    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){
        imprime_erros(chutes_errados);
        imprime_palavra(palavra_secreta, chutou);
        chuta(chutou, chutes_errados, palavra_secreta);
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavrar" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
}