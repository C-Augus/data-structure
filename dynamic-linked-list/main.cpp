#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;


#include "Lista.cpp"

int main() {

    Lista minhaLista;
    int valor, posicao;

    minhaLista.inserir(1, 10);
    minhaLista.inserir(2, 20);
    minhaLista.inserir(3, 1);
    minhaLista.inserir(4, 2);
    minhaLista.inserir(5, 7);

    minhaLista.localizar(posicao, 10);

    minhaLista.substituir(1, 11);

    cout << minhaLista.listar() << endl;

    minhaLista.retornar(3, valor);

    minhaLista.localizarUltimo(posicao, 1);
}
