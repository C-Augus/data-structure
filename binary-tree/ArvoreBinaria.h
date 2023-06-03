class ArvoreBinaria { 
    private:
        struct elemento {
            int valor;
            elemento *elementoEsquerda;
            elemento *elementoDireita;
        };
        typedef elemento *PonteiroElemento; 
        PonteiroElemento raiz;
        int totalElementos(PonteiroElemento &e);
        int totalFolhas(PonteiroElemento &e);
        int altura(PonteiroElemento &e);
        // implementar
        string listarPreOrdem(PonteiroElemento &e);
        string listarInOrdem(PonteiroElemento &e);
        string listarPosOrdem(PonteiroElemento &e);
        bool estritamenteBinaria(PonteiroElemento &e);
    public:
        ArvoreBinaria();
        bool vazia();
        bool cheia();
        void inserir(int x);
        void remover(int x);
        bool pesquisar(int x);
        int totalElementos();
        int totalFolhas();
        int altura();
        string listarPreOrdem();
        string listarInOrdem();
        string listarPosOrdem();
        bool estritamenteBinaria();
        // implementar
        bool maximo();
};