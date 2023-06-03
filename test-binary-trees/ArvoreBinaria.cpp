
#include "ArvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

bool ArvoreBinaria::vazia() {
    return raiz == nullptr;
}

bool ArvoreBinaria::cheia() {
    return false;
}

void ArvoreBinaria::inserir(int x) {
    PonteiroElemento p = nullptr, q=raiz, r;
    while (q != nullptr) {
        p = q; 
        if (x < q->valor) {
            q = q->elementoEsquerda;
        } else {
            q = q->elementoDireita;
        }
    }
    r = new elemento;
    r->valor = x;
    r->elementoEsquerda = nullptr;
    r->elementoDireita = nullptr;

    if (p == nullptr) {
        raiz = r;
    } else {
        if (x < p->valor) {
            p->elementoEsquerda = r;
        } else {
            p->elementoDireita = r;
        }
    }
}

// Método Público
int ArvoreBinaria::totalElementos() {
    return totalElementos(raiz);
}

// Método Privado
int ArvoreBinaria::totalElementos(PonteiroElemento &e) { 
    if (e == nullptr) {
        return 0;
    } else {
        int E, D;
        E = totalElementos(e->elementoEsquerda);
        D = totalElementos(e->elementoDireita);
        return 1 + E + D;
    }
}

// Método Público
int ArvoreBinaria::totalFolhas() { 
    return totalFolhas(raiz);
}

// Método Privado
int ArvoreBinaria::totalFolhas(PonteiroElemento &e) {
    if (e == nullptr) {
        return 0;
    } else {
        if (e->elementoEsquerda == nullptr and e->elementoDireita == nullptr) {
            return 1;
        } else {
            int E, D;
            E = totalFolhas(e->elementoEsquerda);
            D = totalFolhas(e->elementoDireita);
            return E + D;
        }
    }
}

// Método Público
int ArvoreBinaria::altura() { 
    return altura(raiz);
}

// Método Privado
int ArvoreBinaria::altura(PonteiroElemento &e) { 
    if (e == nullptr) {
        return -1;
    } else {
        int E, D;
        E = altura(e->elementoEsquerda);
        D = altura(e->elementoDireita);
        if (E > D) {
            return E + 1;
        }  else {
            return D + 1;
        }
    }
}

// Método Público
string ArvoreBinaria::listarPreOrdem() {
    return listarPreOrdem(raiz);
}

// Método Privado
string ArvoreBinaria::listarPreOrdem(PonteiroElemento &e)
{ 
    string ret;
    if (e != nullptr) {
        ret = ret + "[" + to_string(e->valor) + "]";
        //cout << e->valor << "\n";
        ret = ret + listarPreOrdem(e->elementoEsquerda);
        ret = ret + listarPreOrdem(e->elementoDireita);
    }
    return ret;
}


// Método Público
string ArvoreBinaria::listarInOrdem() {
    return listarInOrdem(raiz);
}

// Método Privado
string ArvoreBinaria::listarInOrdem(PonteiroElemento &e)
{ 
    string ret;
    if (e != nullptr) {
        ret = ret + listarInOrdem(e->elementoEsquerda);
        ret = ret + "[" + to_string(e->valor) + "]";
        ret = ret + listarInOrdem(e->elementoDireita);
    }
    return ret;
}



// Método Público
string ArvoreBinaria::listarPosOrdem() {
    return listarPosOrdem(raiz);
}

// Método Privado
string ArvoreBinaria::listarPosOrdem(PonteiroElemento &e)
{ 
    string ret;
    if (e != nullptr) {
        ret = ret + listarPosOrdem(e->elementoEsquerda);
        ret = ret + listarPosOrdem(e->elementoDireita);
        ret = ret + "[" + to_string(e->valor) + "]";
    }
    return ret;
}

// Método Público
bool ArvoreBinaria::estritamenteBinaria() {
    return estritamenteBinaria(raiz);
}

// Método Privado
bool ArvoreBinaria::estritamenteBinaria(PonteiroElemento &e)
{ 

    if (e == nullptr) {
        return true;
    }

    if ((e->elementoEsquerda == nullptr && e->elementoDireita != nullptr) || (e->elementoEsquerda != nullptr && e->elementoDireita == nullptr)) {
        return false;
    }

    return estritamenteBinaria(e->elementoEsquerda) && estritamenteBinaria(e->elementoDireita);
}

// Método Público
bool ArvoreBinaria::completa() {
    
    if (vazia()) {
        return true;       
    }
    
    int tot=0;
    for (int i = 0 ; i <= altura() ; i++) {
        tot = tot + pow(2, i);
    }
    
    //cout << tot << "\n";
    //cout << totalElementos() << "\n";
    if (tot == totalElementos()) {
        return true;
    }


    return false;
}

int ArvoreBinaria::minimo() {
    return minimo(raiz);
}

int ArvoreBinaria::maximo() {
    return maximo(raiz);
}

int ArvoreBinaria::minimo(PonteiroElemento &e) {
    // Método retorna o menor valor armazenado na árvore.
    // Caso a árvore esteja vazia retorna -1.
    if(raiz == NULL)
        return -1;

    PonteiroElemento p = e;
    int min = e->valor;
    
    while(p->elementoEsquerda != NULL){
        p = p->elementoEsquerda;
        min = p->valor;
    }
    return min;
}

int ArvoreBinaria::maximo(PonteiroElemento &e) {
    // Método retorna o maior valor armazenado na árvore.
    // Caso a árvore esteja vazia retorna -1.
    if(raiz == NULL)
        return -1;

    PonteiroElemento p = e;
    int max = e->valor;
    
    while(p->elementoDireita != NULL){
        p = p->elementoDireita;
        max = p->valor;
    }
    return max;
}

int ArvoreBinaria::soma(PonteiroElemento &e) {
    // Método retorna a soma dos valores armazenados na árvore.
    // Caso a árvore esteja vazia retorna -1.
    // Método auxiliar para o cálculo da média.
    if(raiz == NULL)
        return -1;

    int sum = 0;

    if(e != nullptr)
        sum = e->valor + soma(e->elementoEsquerda) + soma(e->elementoDireita);
    return sum;
}

int ArvoreBinaria::media() {
    // Método retorna a média dos valores armazenados na árvore.
    // Caso a árvore esteja vazia retorna -1.
    if(raiz == NULL)
        return -1;

    int contador = totalElementos(), sum = soma(raiz);
    return sum/contador;
}
