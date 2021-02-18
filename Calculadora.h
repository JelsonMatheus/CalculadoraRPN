#include "Expressao.h"

class Calculadora {
    
    public:
        double calcular( string );
        
    private:
        double resolver( vector<Token> );
        double num( Token );
        double operacao(double, double, Token);
        double somar(double, double);
        double subtrair(double, double);
        double multiplicar(double, double);
        double dividir(double, double);
    
};