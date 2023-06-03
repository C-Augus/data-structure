#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;


#include "ArvoreBinaria.cpp"

int main() {

    ArvoreBinaria minhaArvore;

    int valor, posicao, valores[10];
    string retorno;

    valores[0] = 6;
    valores[1] = 2;
    valores[2] = 8;
    valores[3] = 11;
    valores[4] = 7;
    valores[5] = 1;
    valores[6] = 3;


    for (int i = -1 ; i < 7 ; i++){
        if (i > -1){
            cout << "Valor: " << valores[i] << endl;
            minhaArvore.inserir(valores[i]);
        }

        valor = minhaArvore.totalElementos();
        cout << "Elementos: " << valor << endl;

        valor = minhaArvore.totalFolhas();
        cout << "Folhas   : " << valor << endl;

        valor = minhaArvore.altura();
        cout << "Altura   : " << valor << endl;

        retorno = minhaArvore.listarPreOrdem();
        cout << "Pré: " << retorno << endl;

        retorno = minhaArvore.listarInOrdem();
        cout << "In : " << retorno << endl;

        retorno = minhaArvore.listarPosOrdem();
        cout << "Pós: " << retorno << endl;

        valor = minhaArvore.maximo();
        cout << "Com: " << valor << endl;

        valor = minhaArvore.estritamenteBinaria();
        cout << "Bin: " << valor << endl;

        cout << "---" << endl;
    }
}
