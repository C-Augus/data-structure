#include <iostream>
#include "Fila.cpp"


//	Altere a classe que implementa a fila adicionando os seguintes métodos:
//  a.	Um método primeiro que deve retornar o primeiro elemento da fila;
//  b.	Um método último que deve retornar o último elemento da fila;
//  c.	Um método esvaziar que remova todos os elementos da fila;
//  d.	Um método tamanho que retorne o tamanho atual da fila;
//  e.	Um método inverter que inverta a ordem dos elementos atuais da fila;
//  f.	Um método listar que retorne um vetor contendo todos os elementos da fila;
//  g.	Um método que verifica se um dado valor se encontra na fila;
//  h.	Um método que receba uma lista e retorne a intersecção com essa lista;
//  i.	Um método que receba uma lista e retorne a união com essa lista;
//
// Implementar utilizando sempre somente os metódos inserir e remover.


using namespace std;

int main() {
    Fila minhaFila, fila01, fila02, intersection, iunion;
    int x, y;

    if (minhaFila.vazia()) {
        cout << "Esta vazia!\n";
    } 
    
    cout << "Inserir: " << minhaFila.inserir(1) << "\n";
    cout << "Inserir: " << minhaFila.inserir(2) << "\n";
    cout << "Inserir: " << minhaFila.inserir(3) << "\n";
    cout << "Inserir: " << minhaFila.inserir(4) << "\n";

    cout << "Tamanho: " << minhaFila.tamanho() << "\n";

    cout << "Esta vazia: " << minhaFila.vazia() << "\n";

    minhaFila.inverter();

    cout << "Lista: " << minhaFila.listar() << endl;

    cout << 4 << " esta na lista: " << minhaFila.estaNaFila(4) << endl;

    cout << "Lista: " << minhaFila.listar() << endl;

    cout << "Inserir: " << fila01.inserir(2) << "\n";
    cout << "Inserir: " << fila01.inserir(3) << "\n";
    cout << "Inserir: " << fila01.inserir(5) << "\n";
    cout << "Inserir: " << fila01.inserir(6) << "\n";

    cout << "Lista: " << fila01.listar() << endl;

    cout << "Tamanho: " << minhaFila.tamanho() << "\n";
    cout << "Lista Interseccao: " << minhaFila.interseccao(fila01).listar() << endl;
    cout << "Lista Uniao: " << minhaFila.uniao(fila02).listar() << endl;
}
