#include "Fila.h"

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
    cont_folhas = 0;
    cont_id = 1;
}

bool Fila::vazia() {
    return (inicio == NULL);
}

bool Fila::cheia() {
    return false;
}

bool Fila::inserir(string arquivo, int folhas) {
    // Inserir um arquivo na fila de impressão;
    // Altere o método inserir:
    PonteiroElemento p;
    p = new elemento;

    if (folhas > cont_folhas)
        return false;
    if (vazia()) {
        inicio = p;
        fim = p;
    } else {
        fim->proximoElemento = p;
        fim = p;
    }
    p->id = cont_id;
    p->arquivo = arquivo;
    p->quantidade = folhas;

    cont_id++;
    cont_folhas -= folhas;

    p->proximoElemento = NULL;
    return true;
}

bool Fila::remover(int &id, string &arquivo, int &folhas) {
    // Remover um arquivo da fila da impressão (imprimir);
    // Altere o método remover:
    PonteiroElemento p;
    if (vazia())
        return false;

    id = inicio->id;
    arquivo = inicio->arquivo;
    folhas = inicio->quantidade;

    cont_folhas += folhas;
    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL)
        fim = NULL;
    return true;
}

string Fila::listar() {
	// Implementar listagem da fila de impressão;
    // Retornar string no formato:
	// <idImpressao1> - <nomeArquivo1> - <folhas1>\n
	// <idImpressao2> - <nomeArquivo2> - <folhas2>\n
    if (vazia())
        return "";

    string lista = "";
    elemento *p = inicio;

    for (elemento *p = inicio; p != fim->proximoElemento; p = p->proximoElemento) {
        lista += to_string(p->id) + (" - ") + p->arquivo + (" - ") + to_string(p->quantidade) + "\n";
    }
    return lista;
}

bool Fila::inserirFolhas(int auxFolhas) {
    // Inserir mais folhas na impressora;
    cont_folhas += auxFolhas;
    return true;
}

int Fila::listarFolhas() {
    // Retorna o total de folhas disponíveis na impressora;
    return cont_folhas;
}