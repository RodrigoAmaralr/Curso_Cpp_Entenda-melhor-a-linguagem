#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>
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

static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;
//static array<char, 5> chutes_errados;

int main(){
    namespace f = Forca;
    f::imprime_cabecalho();

    palavra_secreta = Forca::sorteia_palavra();

    while(f::nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){
        f::imprime_erros(chutes_errados);
        Forca::imprime_palavra(palavra_secreta, chutou);
        f::chuta(chutou, chutes_errados, palavra_secreta);
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if(f::nao_acertou(palavra_secreta, chutou)){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavrar" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            Forca::adiciona_palavra();
        }
    }
}