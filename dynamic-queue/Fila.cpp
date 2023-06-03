#include <cstdlib>
#include "Fila.h"

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
}

bool Fila::vazia() {
    return (inicio == NULL);
}

bool Fila::cheia() {
    return false;
}

bool Fila::inserir(int x) {
    PonteiroElemento p;
    p = new elemento;
    p->valor = x;
    if (vazia()) {
        inicio = p;
        fim = p;
    } else {
        fim->proximoElemento = p;
        fim = p;
    }
    p->proximoElemento = NULL;

    return true;
}

bool Fila::remover(int &x) {
    PonteiroElemento p;
    if (vazia())
        return false;
    x = inicio->valor;
    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL)
        fim = NULL;

    return true;
}


bool Fila::primeiro(int &x) {
	// caso a lista esteja vazia retornar falso,
	// retorna em x o valor do primeiro elemento da lista
    if (vazia())
        return false;

    x = inicio->valor;

	return true;
}

bool Fila::ultimo(int &x) {
	// caso a lista esteja vazia retornar falso,
	// retorna em x o valor do último elemento da lista
    if (vazia())
        return false;

    x = fim->valor;

    return true;
}

bool Fila::esvaziar() {
	// caso a lista esteja vazia retornar falso, remove todos os elementos da lista
    if (vazia())
        return false;

    int x;
    while (remover(x));

	return true;
}

int Fila::tamanho() {
	// retorna o tamanho da lista, 0 se estiver vazia
    if (vazia())
        return 0;

    int tam = 1;
    elemento *p = inicio;

    while(p->proximoElemento != NULL) {
        p = p->proximoElemento;
        tam++;
    }
    
    return tam;
}

bool Fila::inverter() {
	// caso a lista esteja vazia retornar falso, inverte a ordem dos elementos da lista
    if (vazia())
        return 0;
    
    int vetorAux[tamanho()];
    elemento *p = inicio, *q = inicio;

    for (int i = tamanho() - 1; i >= 0; i--) {
        vetorAux[i] = p->valor;
        if (p->proximoElemento != NULL)
            p = p->proximoElemento;
    }
    for (int i = 0; i < tamanho(); i++) {
        q->valor = vetorAux[i];
        if (q->proximoElemento != NULL)
            q = q->proximoElemento;
    }

	return true;
}

string Fila::listar() {
	// retornar string com todos os elementos da lista separados por ;
	// exemplo: 1 ; 3 ; 5. String vazia se a lista estiver vazia
    if (vazia())
        return "";

    string lista = "";
    elemento *p = inicio;

    lista += to_string(p->valor);

    for (int i = 0; i < tamanho() - 1; i++) {
        lista += " ; ";
        if (p->proximoElemento != NULL)
            p = p->proximoElemento;
        lista += to_string(p->valor);
    }

    return lista;
}

bool Fila::estaNaFila(int x) {
	// retorna verdadeiro caso o valor x seja localizado na fila
    elemento *p = inicio;

    for (int i = 0; i < tamanho(); i++) {
        if (x == p->valor)
            return true;
        if (p->proximoElemento != NULL)
            p = p->proximoElemento;
    }
	return false;
}

Fila Fila::interseccao(Fila auxFila) {
	// retorna objeto Fila contendo a intersecção com a lista atual
	// elementos em comum com as 2 listas, sem repetição de elementos
    elemento *p = inicio;
    Fila retorno;
    
    if (auxFila.vazia() || vazia()) {
		return retorno;
	} 

    for (elemento *i = inicio; i != nullptr; i = i->proximoElemento) {
        if (!retorno.estaNaFila(i->valor))
            if (auxFila.estaNaFila(i->valor))
                retorno.inserir(i->valor);
    }

    return retorno;
}

Fila Fila::uniao(Fila auxFila) {
	// retorna objeto Fila contendo a união com a lista atual
	// elementos das 2 listas, sem repetição de elementos
    Fila retorno, filaAux;
    int x;

	if (auxFila.vazia() || vazia()) {
		return retorno;
	} 
	
	while (remover(x)) {
		if (!retorno.estaNaFila(x))
			retorno.inserir(x);
		filaAux.inserir(x);
	}
	while (filaAux.remover(x)) {
		inserir(x);
	}
	while (auxFila.remover(x)) {
		if (!retorno.estaNaFila(x))
			retorno.inserir(x);
		filaAux.inserir(x);
	}
	while (filaAux.remover(x)) {
		auxFila.inserir(x);
	}

	return retorno;
}