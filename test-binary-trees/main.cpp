#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;

#include "ArvoreBinaria.cpp"
#include "Lista.cpp"

int main() {

    ArvoreBinaria minhaArvore;
    Lista minhaLista;

    int valor, posicao, valores[10];
    string uga;

    valores[0] = 6;
    valores[1] = 2;
    valores[2] = 8;
    valores[3] = 11;
    valores[4] = 7;
    valores[5] = 1;
    valores[6] = 3;

    for (int i = -1 ; i < 7 ; i++){
        if (i > -1){
            cout << "Valor : " << valores[i] << " - i: " << i << endl;
            minhaArvore.inserir(valores[i]);
            minhaLista.inserir(1, valores[i]);
        }

        valor = minhaArvore.minimo();
        cout << "arvore minimo: " << valor << endl;

        valor = minhaArvore.maximo();
        cout << "arvore maximo: " << valor << endl;

        valor = minhaArvore.media();
        cout << "arvore media : " << valor << endl;

        cout << "---" << endl;

        valor = minhaLista.minimo();
        cout << "lista minimo: " << valor << endl;

        valor = minhaLista.maximo();
        cout << "lista maximo: " << valor << endl;

        valor = minhaLista.media();
        cout << "lista media : " << valor << endl;

        cout << "---" << endl;
    }
}
