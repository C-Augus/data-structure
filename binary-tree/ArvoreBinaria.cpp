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

// Método Público
string ArvoreBinaria::listarInOrdem() {
    return listarInOrdem(raiz);
}

// Método Público
string ArvoreBinaria::listarPosOrdem() {
    return listarPosOrdem(raiz);
}

// Método Público
bool ArvoreBinaria::estritamenteBinaria() {
    return estritamenteBinaria(raiz);
}

// Implementar

// Método Privado
string ArvoreBinaria::listarPreOrdem(PonteiroElemento &e) { 
    // Retorna string com elementos ordenados em PreOrdem.
    // Sequência: raiz - esquerda - direita
    string ret;

    if(e!=NULL) {
        ret += "[" + to_string(e->valor) + "]";
        ret += listarPreOrdem(e->elementoEsquerda);
        ret += listarPreOrdem(e->elementoDireita);
        }
    return ret;
}

// Método Privado
string ArvoreBinaria::listarInOrdem(PonteiroElemento &e)
{ 
    // Retorna string com elementos ordenados em InOrdem.
    // Sequência: Esquerda - Raiz - Direita
    string ret;


    if(e!=NULL) {
        ret += listarInOrdem(e->elementoEsquerda);
        ret += "[" + to_string(e->valor) + "]";
        ret += listarInOrdem(e->elementoDireita);
        }
    return ret;
}

// Método Privado
string ArvoreBinaria::listarPosOrdem(PonteiroElemento &e)
{ 
    // Retorna string com elementos ordenados em PósOrdem.
    // Sequência: Esquerda - Direita - Raiz
    string ret;

    if(e!=NULL) {
        ret += listarPosOrdem(e->elementoEsquerda);
        ret += listarPosOrdem(e->elementoDireita);
        ret += "[" + to_string(e->valor) + "]";
        }
    return ret;
}

// Método Privado
bool ArvoreBinaria::estritamenteBinaria(PonteiroElemento &e)
{ 
    // Árvore estritamente binária é uma árvore binária em que cada nó tem 0 ou 2 filhos.
    // O método deve retornar verdadeiro caso a árvore seja estritamente binária.
    // Caso contrário deve retornar falso.

    if (e == NULL)
    return true;

    if (e->elementoEsquerda == NULL && e->elementoDireita == NULL)
    return true;

    if ((e->elementoEsquerda) && (e->elementoDireita))
    return (estritamenteBinaria(e->elementoEsquerda) && estritamenteBinaria(e->elementoDireita));

  return false;
}

// Método Público
bool ArvoreBinaria::maximo() {
    // Número máximo de nós:
    // - Para uma árvore de grau 2:
    // - Quando todos os nós possuírem 2 subárvores, exceto suas folhas.
    // Verifica a altura atual da árvore.
    // Verifica se para essa altura a árvore atingiu seu número máximo de nós.
    // Se atingiu retornar verdadeiro.
    // Caso contrário retornar falso.

    int h = altura(), total = 0;

    for(int i = 0; i <= h; i++)
        total += pow(2, i);

    if (total == totalElementos(raiz))
        return true;

    return false;
}


