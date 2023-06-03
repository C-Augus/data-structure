#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define MAX 5

#include "Lista.cpp"

int main() {

    Lista minhaLista;

    if (minhaLista.inserir(1, 3))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";

    if (minhaLista.inserir(-1, 3))        
        minhaLista.listar();
    else
        cout << "Não inseriu!\n";

    if (minhaLista.inserir(2, 4))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";

    if (minhaLista.inserir(3, 5))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";

if (minhaLista.inserir(4, 5))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";
    if (minhaLista.inserir(5, 5))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";
if (minhaLista.inserir(3, 5))        
        cout << minhaLista.listar();
    else
        cout << "Não inseriu!\n";
    cout << "\n";
}