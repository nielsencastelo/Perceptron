#include "Perceptron.h"

Perceptron::Perceptron(int op)
{
    srand( (unsigned)time(NULL) );

    if ((op >= 0) && (op < 6))
    {
        operacao = op + 2;
    }
    for (int i = 0; i < 3; i++)
    {
        w[i] = -1 + ( rand() % 1 ); // [-1,1]
    }
}
void Perceptron::corrigirPeso(int exemplo, int saida)
{
    w[0] = w[0] + (N * (e[exemplo][operacao] - saida) * (BIAS));
    w[1] = w[1] + (N * (e[exemplo][operacao] - saida) * e[exemplo][0]);
	w[2] = w[2] + (N * (e[exemplo][operacao] - saida) * e[exemplo][1]);
}
bool Perceptron::treinar()
{
    bool treinou;
    int epoca = 0;
    do
    {
        treinou = true;
		for (int i = 0; i < 4; i++)
		{
            int s = executar(e[i][0], e[i][1]);
			if (s != e[i][operacao])
			{
                corrigirPeso(i, s);
				treinou = false;
            }
        }
		epoca++;
    } while ((treinou == false) && (epoca < MAX_EPOCAS));

    cout << "The algorithm trained " << epoca  << " epochs..." << endl;

	if (treinou == false)
	{
        cout << "The algorithm could not converge..." << endl;
	}
    return treinou;
}
void Perceptron::testar()
{
    bool sair = false;
    while (!sair)
    {
        cout << "-- Please enter 9 to exit --" << endl;
        cout << "x1 : ";

        int x1;
        cin >> x1;
        if (x1 == 9)
        {
            sair = true;
        } else
        {
            cout << "x2 : ";
            int x2;
            cin >> x2;

			int y = executar(x1, x2);
            cout << " y : "  << y << endl;
        }
    }
}
int Perceptron::executar(int x1, int x2)
{
    // Somatorio NET
    y = ((BIAS) * w[0]) + (x1 * w[1]) + (x2 * w[2]);
	// Funcao de Transferencia
	if (y > 0)
    {
        return 1;
    }
    return 0;
}
