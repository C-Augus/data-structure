#include "Lista.h"


Lista::Lista() {
    contador = 0;
    for (int i = 0 ; i < capacidade ; i ++) {
        elementos[i] = 0;
    }
}


bool Lista::vazia() {
    return contador == 0;
}


bool Lista::cheia() {
    return contador == capacidade;
}

string Lista::listar() {
    string ret = "";
    for (int i = 0 ; i < contador ; i ++) {
        ret = ret + "[" + to_string(elementos[i]) + "] ";
    }
    ret = ret;
    return ret;
}

bool Lista::inserir(int p, int x) {
    // Inserção de elemento em determinada posição.
    // Esta posição deve ser um valor entre 1 (primeiro elemento da lista)
    // e último + 1 (após o último elemento da lista).
    // As entradas posteriores ao elemento inserido devem ter suas posições 
    // incrementadas em uma unidade.
    if ((p < 1) or (p > contador + 1) || cheia())
        return false;

    for (int i = contador; i > p - 1; i--) {
        elementos[i] = elementos[i - 1];
    }
    contador++;
    elementos[p - 1] = x;

    return true;
}

bool Lista::remover(int p, int &x) {
    // Remoção de elemento em determinada posição.
    // Esta posição deve ser um valor entre 1 (primeiro elemento da lista)
    // e último (último elemento da lista).
    // As entradas posteriores ao elemento removido devem ter suas posições 
    // decrementadas em uma unidade.
    if ((p < 1) || (p > contador) || vazia())
        return false;

    x = elementos[p - 1];
    for (int i = p - 1; i < contador; i++) {
        elementos[i] = elementos[i + 1];
    }
    contador--;

    return true;
}

bool Lista::retornar(int p, int &x) {
    // Retorna elemento armazenado em determinada posição.
    // Esta posição deve ser um valor entre 1 (primeiro elemento da lista)
    // e último (último elemento da lista).
    // Seu código aqui
    if ((p < 1) || (p > contador) || vazia())
        return false;
    x = elementos[p - 1];

    return true;
}

bool Lista::substituir(int p, int x) {
    // Substitui elemento armazenado em determinada posição.
    // Esta posição deve ser um valor entre 1 (primeiro elemento da lista)
    // e último (último elemento da lista).
    // Seu código aqui
    if ((p < 1) || (p > contador) || vazia())
        return false;
    elementos[p - 1] = x;

    return true;
}
