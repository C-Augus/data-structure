class Lista {
    private:
        struct elemento {
            int valor;
            elemento *proximoElemento;
        };
        typedef elemento *PonteiroElemento;
        PonteiroElemento inicio;
        int contador;
    public:
        Lista();
        bool vazia();
        bool cheia();
        bool inserir(int posicao, int x);
        bool remover(int posicao, int &x);
        int tamanho();
        //implementar
        int maximo();
        int minimo();
        int media();
    private:
        bool setaPosicao(int posicao, PonteiroElemento &atual);
};