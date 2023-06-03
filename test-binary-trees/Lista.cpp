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

int Lista::tamanho() {
    return contador;
}

int Lista::minimo() {
    // Método retorna o menor valor armazenado na lista.
    // Caso a lista esteja vazia retorna -1.
    if(inicio == NULL)
        return -1;

    int ret = inicio->valor;

    for (elemento *p = inicio; p != NULL; p = p->proximoElemento) {
        if(p->valor < ret)
            ret = p->valor;
    }
    return ret;
}

int Lista::maximo() {
    // Método retorna o maior valor armazenado na lista.
    // Caso a lista esteja vazia retorna -1.
    if(inicio == NULL)
        return -1;

    int ret = inicio->valor;

    for (elemento *p = inicio; p != NULL; p = p->proximoElemento) {
        if(p->valor > ret)
            ret = p->valor;
    }
    return ret;
}

int Lista::media() {
    // Método retorna a média dos valores armazenados na lista.
    // Caso a lista esteja vazia retorna -1.
    if(inicio == NULL)
        return -1;

    int ret = 0, contador = 0;

    for (elemento *p = inicio; p != NULL; p = p->proximoElemento) {
        ret += p->valor;
        contador++;
    }
    ret /= contador;
    return ret;
}
