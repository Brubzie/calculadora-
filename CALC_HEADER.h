#ifndef CALC_HEADER
#define CALC_HEADER

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Prot�tipos de Fun��es
void clean();
void pause();
void menu(int &menu);
void calculadora(double &resposta, double &numero, char &operador);

// Fun��es
void clean() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    #endif
}

void menu(int &menu) {
    menu = 0;

    cout << "=== Menu ===" << endl
         << "1 - Iniciar Calculadora" << endl
         << "2 - Sair" << endl
         << "Op��o: ";
    cin >> menu;
}

void calculadora(double &resultado, double &numero, char &operador) {
    // Solicita��o da express�o matem�tica
    cout << "=== Calculadora ===" << endl
         << ": ";
    string expressao;
    getline(cin, expressao);

    // Avalia��o da express�o usando stringstream
    stringstream ss(expressao);
    
    resultado = 0.0;
    operador = '+';

    // Loop para avaliar a express�o
    while (ss >> numero) {
        // Realiza a opera��o correspondente
        if (operador == '+') {
            resultado += numero;
        } else if (operador == '-') {
            resultado -= numero;
        } else if (operador == '*') {
            resultado *= numero;
        } else if (operador == '/') {
            // Evita divisão por zero
            if (numero != 0) {
                resultado /= numero;
            } else {
                cout << "[Erro] Divis�o por zero!\n";
                return;  // Saída com erro
            }
        }
        // L� o pr�ximo operador (se houver)
        ss >> operador;
    }
    // Imprime o resultado
    cout << "=== Resultado da Opera��o ===" << endl << ": " << resultado << endl;
}

#endif