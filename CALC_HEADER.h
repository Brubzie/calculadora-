#ifndef CALC_HEADER
#define CALC_HEADER

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Protótipos de Funções
void clean();
void pause();
void menu(int &menu);
void calculadora(double &resposta, double &numero, char &operador);

// Funções
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
         << "Opção: ";
    cin >> menu;
}

void calculadora(double &resultado, double &numero, char &operador) {
    // Solicitação da expressão matemática
    cout << "=== Calculadora ===" << endl
         << ": ";
    string expressao;
    getline(cin, expressao);

    // Avaliação da expressão usando stringstream
    stringstream ss(expressao);
    
    resultado = 0.0;
    operador = '+';

    // Loop para avaliar a expressão
    while (ss >> numero) {
        // Realiza a operação correspondente
        if (operador == '+') {
            resultado += numero;
        } else if (operador == '-') {
            resultado -= numero;
        } else if (operador == '*') {
            resultado *= numero;
        } else if (operador == '/') {
            // Evita divisÃ£o por zero
            if (numero != 0) {
                resultado /= numero;
            } else {
                cout << "[Erro] Divisão por zero!\n";
                return;  // SaÃ­da com erro
            }
        }
        // Lê o próximo operador (se houver)
        ss >> operador;
    }
    // Imprime o resultado
    cout << "=== Resultado da Operação ===" << endl << ": " << resultado << endl;
}

#endif