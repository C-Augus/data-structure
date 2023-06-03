int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);
int calculadora(int a, int b, char operacao, int *ptr);
int limpaHistorico(int *ptr);
string listaHistorico(int *ptr, int i);


int soma(int a, int b)
{
    int res = a + b;
    return res;
}

int subtracao(int a, int b)
{
    int res = a - b;
    return res;
}

int multiplicacao(int a, int b)
{
    int res = a * b;
    return res;
}

int divisao(int a, int b)
{
    int res;
    if (b == 0)
    {
        system("cls");
        cout << "[OPERAÇÃO INVÁLIDA]" << endl;
        return 0;
    }
    else
    {
        res = a / b;
        return res;
    }
}

int calculadora(int a, int b, char operacao, int *ptr)
{
    switch (operacao)
    {
        case '+':
            *ptr = 43;
            soma(a, b);
            break;
        case '-':
            *ptr = 45;
            subtracao(a, b);
            break;
        case '*':
            *ptr = 42;
            multiplicacao(a, b);
            break;
        case '/':
            *ptr = 47;
            divisao(a, b);
            break;
    }
    if (false){return 0;}
}

int limpaHistorico(int *aptr, int *bptr, int *optr, int *rptr)
{
    for (int j = 0; j < 5; j++)
    {
        *aptr = 0; aptr+=4;
        *bptr = 0; bptr+=4;
        *optr = 0; optr+=4;
        *rptr = 0; rptr+=4;
    }
}

string listaHistorico(int *aptr, int *bptr, int *optr, int *rptr, int k)
{
    int m = 0;
    for (int j = 0; j < k; j++)
    {
        cout << *aptr << " " << (char)*optr << " " << *bptr << " = " << *rptr << endl;
        if (m == 4)
            {
                break;
            }
        aptr+=4; bptr+=4; optr+=4; rptr+=4;
        m++;

    }
}
