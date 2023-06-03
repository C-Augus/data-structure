class Pilha {
        private:
        int contador;
        int capacidade;
        int conteudo[MAX];
        public:
        Pilha();
        bool vazia();
        bool cheia();
        bool empilhar(int valor);
        bool desempilhar(int &valor);
        bool retornaTopo(int &valor);
	    bool inverter();
	    bool maior(int &valor);
        bool menor(int &valor);
	    bool media(float &valor);
        bool impar();
        bool palindromo();
        bool imprimir();
        bool listar();
    };