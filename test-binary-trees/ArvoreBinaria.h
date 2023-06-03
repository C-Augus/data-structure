class ArvoreBinaria { 
    private:
        struct elemento {
            int valor;
            elemento *elementoEsquerda;
            elemento *elementoDireita;
        };
        typedef elemento *PonteiroElemento; 
        PonteiroElemento raiz;
        // outras operações: métodos auxiliares
        int totalElementos(PonteiroElemento &e);
        int totalFolhas(PonteiroElemento &e);
        int altura(PonteiroElemento &e);
        string listarPreOrdem(PonteiroElemento &e);
        string listarInOrdem(PonteiroElemento &e);
        string listarPosOrdem(PonteiroElemento &e);
        bool estritamenteBinaria(PonteiroElemento &e);

        int maximo(PonteiroElemento &e);
        int minimo(PonteiroElemento &e);
        int soma(PonteiroElemento &e);
    public:
        ArvoreBinaria();
        bool vazia();
        bool cheia();
        void inserir(int x);
        void remover(int x);
        bool pesquisar(int x);
        // outras operações
        int totalElementos();
        int totalFolhas();
        int altura();
        string listarPreOrdem();
        string listarInOrdem();
        string listarPosOrdem();
        bool completa();
        bool estritamenteBinaria();

        int maximo();
        int minimo();
        int media();
};