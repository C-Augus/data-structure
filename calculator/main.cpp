#include <iostream>
#include <string>
#include <locale.h>
#include <conio.h>

using namespace std;

#include "funcoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int x, y, i = 0;
    char op;

    typedef struct
    {
        int x, y, resultado, sOp = 0;
    }Operacao;
    Operacao historico[5];

    cout << "Primeiro operando: "; cin >> historico[0].x;
    system("cls"); cout << historico[i].x << endl;

    cout << "\n[+ - * /]";
    cout << "\nOperação:";
    op = _getch();
    system("cls"); cout << historico[i].x << " " << op << endl;

    cout << "\nSegundo operando: "; cin >> historico[i].y;
    system("cls"); cout << historico[i].x << " " << op << " " << historico[i].y;

    int *sPtr = &historico[i].sOp;
    int *xPtr = &historico[i].x;
    int *yPtr = &historico[i].y;

    historico[i].resultado = calculadora(historico[i].x, historico[i].y, op, sPtr);
    cout << " = " << historico[i].resultado << endl; i++;

    while(true)
    {
        if (i != 0) historico[i].x = historico[i-1].resultado;

        cout << "\n[+ - * /]" << "\n[\".\" - Limpa Histórico]"
        << "\n[\",\" - Exibe Histórico]" << "\n\nOperação: ";
        op = _getch();

        if (op == '.')
        {
            system("cls");
            limpaHistorico(&historico[0].x, &historico[0].y, &historico[0].sOp, &historico[0].resultado);
            cout << "[HISTÓRICO DE OPERAÇÕES ZERADO]" << endl;
            i = 0; continue;
        }
        if (op == ',')
        {
            system("cls");
            listaHistorico(&historico[0].x, &historico[0].y, &historico[0].sOp, &historico[0].resultado, i);
            cout << endl; continue;
        }

        if (i > 4)
        {
            i--;
            for (int j = 0; j < 4; j++)
            {
                historico[j].x = historico[j+1].x;
                historico[j].y = historico[j+1].y;
                historico[j].resultado = historico[j+1].resultado;
                historico[j].sOp = historico[j+1].sOp;
            }
        }

        system("cls"); cout << historico[i].x << " " << op << endl;

        cout << "\nPróximo operando: "; cin >> historico[i].y;
        system("cls"); cout << historico[i].x << " " << op << " " << historico[i].y;

        int *sPtr = &historico[i].sOp;
        if (i != 0)
        {
            int *xPtr = &historico[i-1].resultado;
        }
        else
        {
            int *xPtr = &historico[i].resultado;
        }
        int *yPtr = &historico[i].y;

        historico[i].resultado = calculadora(historico[i].x, historico[i].y, op, sPtr);

        cout << " = " << historico[i].resultado << endl;

        i++;
    }

    return 0;
}
