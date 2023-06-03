#include "Pilha.h"

Pilha::Pilha() {
        contador = 0;
        capacidade = MAX;
    };

    bool Pilha::vazia() {
        if (contador == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Pilha::cheia() {
        if (contador == capacidade) {
            return true;
        } else {
            return false;
        }
    }

    bool Pilha::empilhar(int valor) {
        if (cheia())
            return false;
        conteudo[contador] = tolower(valor);
        contador++;
        return true;
    }

    bool Pilha::desempilhar(int &valor) {
        if (vazia())
            return false;
        contador--;
        valor = conteudo[contador];
        return true;
    }

    bool Pilha::retornaTopo(int &valor) {
        if (vazia())
            return false;
        valor = conteudo[contador-1];
        return true;
    }

    bool Pilha::inverter() {
        int strAux[contador];

        for (int i = 0; i < contador; i++) {
            strAux[i] = conteudo[contador - i-1];
        }
        for (int i = 0; i < contador; i++) {
            conteudo[i] = strAux[i];
        }
    }

    bool Pilha::maior(int &maior) {
        if (vazia())
            return false;
        maior = 0;
        for (int i = 0; i < contador; i++) {
            maior = maior < conteudo[i] ? conteudo[i] : maior;
        }

        return true;
    }

    bool Pilha::menor(int &menor) {
        if (vazia())
            return false;
        menor = conteudo[0];
        for (int i = 0; i < contador; i++) {
            menor = menor > conteudo[i] ? conteudo[i] : menor;
        }

        return true;
    }

    bool Pilha::media(float &media) {
        if (vazia())
            return false;
        media = 0;
        for (int i = 0; i < contador; i++) {
            media += (float)conteudo[i];
        }
        media /= (float)contador;

        return true;
    }

    bool Pilha::impar() {
        if (vazia())
            return false;
        for (int i = 0; i < contador; i++) {
            if (conteudo[i]%2 != 0)
                cout << conteudo[i] << " e impar." << endl;
        }

        return true;
    }

    bool Pilha::palindromo() {
        if (vazia())
            return false;

        int strAux[contador];

        for (int i = 0; i < contador; i++) {
            strAux[i] = conteudo[contador - i-1];
        }
        for (int i = 0; i < contador; i++) {
            if (conteudo[i] != strAux[i])
                return false;
        }

        return true;
    }

    bool Pilha::listar()
    {
        for (int i = 0; i < contador; i++) {
            cout << "lista" << conteudo[i] << endl;
        }

        return true;
    }