#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class Perceptron
{
    private:
        double w[3];
        double y = 0;
        double N = 0.1;
        const int BIAS = 1;
        const int MAX_EPOCAS = 1000;
        int operacao = 0;
        int e [4][8]= {
			{ 0, 0, 0, 0, 1, 1, 0, 1 },
			{ 0, 1, 1, 0, 0, 1, 1, 0 },
			{ 1, 0, 1, 0, 0, 1, 1, 0 },
			{ 1, 1, 1, 1, 0, 0, 0, 1 }
			};
    public:
        Perceptron(int op);
        int executar(int x1, int x2);
        bool treinar();
        void corrigirPeso(int exemplo, int saida);
        void testar();
};
#endif // PERCEPTRON_H
