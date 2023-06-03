#include "Lista.h"

Lista::Lista() {
    inicio = nullptr;
    contador = 0;
}

bool Lista::vazia() {
    return inicio == nullptr;
}

bool Lista::cheia() {
     return false;
}

bool Lista::setaPosicao(int posicao, PonteiroElemento &atual) {
    atual = inicio;
    for(int i = 1 ; i < posicao ; i++) {
        atual = atual->proximoElemento;
    }    
    return true;
}

bool Lista::inserir(int posicao, int x) {
    PonteiroElemento p, atual;
    
    if (posicao < 1 or posicao > contador + 1) {
        return false;
    }

    p = new elemento;
    p->valor = x;
    
    if (posicao == 1) {
        p->proximoElemento = inicio;
        inicio = p;
    } else {
        setaPosicao(posicao - 1, atual);
        p->proximoElemento = atual->proximoElemento;
        atual->proximoElemento = p;
    }
    contador++;

    return true;    
}

bool Lista::remover(int posicao, int &x) {
    PonteiroElemento p, atual;
    
    if (posicao < 1 or posicao > contador) {
        return false;
    }

    if(posicao == 1) {
        p = inicio;
        inicio = inicio->proximoElemento;
    } else {
        setaPosicao(posicao - 1, atual);
        p = atual->proximoElemento;
        atual->proximoElemento = p->proximoElemento;
    }
    x = p->valor;
    delete p;
    contador --;
    
    return true;
}

bool Lista::substituir(int posicao, int valor) {
    if (posicao < 1 || posicao > contador || vazia())
        return false;

    PonteiroElemento p = inicio;

    setaPosicao(posicao, p);
    p->valor = valor;

    return true;
}

string Lista::listar() {
    string ret = "";

    for (elemento *p = inicio; p != NULL; p = p->proximoElemento) {
        ret = ret + "[" + to_string(p->valor) + "]";
    }

    return ret;
}

int Lista::tamanho() {
    int tam = 0;
    
    for (elemento *p = inicio; p != NULL; p = p->proximoElemento)
        tam++;

    return tam;
}

bool Lista::retornar(int posicao, int &valor) {
    if (posicao < 1 || posicao > contador || vazia())
        return false;

    elemento *p = inicio;

    setaPosicao(posicao, p);
    valor = p->valor;

    return true;
}

bool Lista::localizar(int &posicao, int valor) {
    posicao = 1;
    for (elemento *p = inicio; p != NULL; p = p->proximoElemento) {
        if (p->valor == valor)
            return true;
        posicao++;
    }
    posicao = 0;

    return false;
}

bool Lista::localizarUltimo(int &posicao, int valor) {
    elemento *p;

    posicao = contador;
    for (int i = contador; i > 0; i--) {
        setaPosicao(i, p);
        if (p->valor == valor)
            return true;
        posicao--;
    }
    posicao = 0;

    return false;
}
