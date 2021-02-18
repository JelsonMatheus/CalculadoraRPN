#include <iostream>
#include "Calculadora.h"

using namespace std;

int main() {
    
    string entrada;
    Calculadora calculadora;
    
    system("clear || cls");
    cout << "\nInsira uma Expressão matemática válida.\n";
    cout << "\t1. Use apenas '(' ')'.\n";
    cout << "\t2. Operações suportadas: +, - , * e /.\n";
    
    cout << "\nEntrada: ";
    getline(cin, entrada);
    
    try {
        double resultado = calculadora.calcular(entrada);
        
        cout << "\nResultado:\n";
        cout << "\t" << entrada << " = " << resultado << endl;
    }
    catch(string ex) {
        cout << "\t@Erro -> " << ex << "." << endl;
    }
}