#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 5

#include "Pilha.cpp"

int main() {
    Pilha minhaPilha;
    int recebeValor;
    float recebeMedia;

    minhaPilha.empilhar('A');
    minhaPilha.empilhar('r');
    minhaPilha.empilhar('a');
    minhaPilha.empilhar(5);
    minhaPilha.empilhar(4);

    minhaPilha.desempilhar(recebeValor);
    minhaPilha.desempilhar(recebeValor);

    minhaPilha.inverter();

    minhaPilha.listar();

    minhaPilha.maior(recebeValor);
    cout << "maior: " << recebeValor << endl;

    minhaPilha.menor(recebeValor);
    cout << "menor: " << recebeValor << endl;

    minhaPilha.media(recebeMedia);
    cout << "media: " << recebeMedia << endl;

    minhaPilha.impar();

    cout << "Palindromo?" << minhaPilha.palindromo() << endl;
}


