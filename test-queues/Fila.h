class Fila {
    private:
        struct elemento {
            int id;
            int quantidade;
            string arquivo;
            int valor;
            elemento *proximoElemento;
        };
        typedef elemento *PonteiroElemento;
        PonteiroElemento inicio;
        PonteiroElemento fim;
        int cont_folhas;
        int cont_id;
    public:
        Fila();
        bool vazia();
        bool cheia();
        // alterar
        bool inserir(string arquivo, int folhas);
        bool remover(int &id, string &arquivo, int &folhas);
        // implementar
        string listar();
        int listarFolhas();
        bool inserirFolhas(int auxFolhas);
        bool imprimir();
};