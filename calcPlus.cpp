#include <iostream>
#include <string>
#include <sstream> // Para utilizar stringstream
#include <limits>
#include <locale>
#include "CALC_HEADER.h"

using namespace std;

// Protótipos de Funções
void clean();
void pause();
void menu(int&);
void calculadora(double&, double&, char&);

int main() {
    setlocale(LC_ALL, "portuguese");

    double res, num;
    char operator;

    int op;
    menu(op);

    do {
        clean();
        calculadora(res, num, operator);
        pause();
    } while (true);

    cout << "Saindo..." << endl;

    return 0;
}