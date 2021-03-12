#include <iostream>
#include <stack>
#include <stdexcept>
#include "Calculadora.h"


double Calculadora::calcular(string entrada) {
    double resultado;
       
    Expressao expressao(entrada);
    vector<Token> tokens = expressao.converterParaRPN();
    
    try {
        resultado = resolver(tokens);
    }
    catch(invalid_argument& ex) {
        throw "Expressao inválida -> " + entrada;
    }

    return resultado;
}

double Calculadora::resolver(vector<Token> tokens) {
    
    stack<Token> pilha;
    Token token;
    
    for(int i = 0; i < tokens.size(); i++) {
    
        token = tokens.at(i);
        
        if(token.ehOperador()) {
            double num2 = num(pilha.top());
            pilha.pop();
            
            double num1 = num(pilha.top());
            pilha.pop();
            
            double result = operacao(num1, num2, token);
            
            pilha.push(Token(to_string(result)));
        }
        
        else {
            pilha.push(token);
        }
    }
    
    return num(pilha.top());
}

double Calculadora::num(Token token) {
    
    return stod(token.obterToken());
}

double Calculadora::operacao(double num1, double num2, Token token) {
    
    string sinal = token.obterToken();
    
    if(sinal.compare("+") == 0) {
        return somar(num1, num2);
    }
    
    else if(sinal.compare("-") == 0) {
        return subtrair(num1, num2);
    }
    
    else if(sinal.compare("*") == 0) {
        return multiplicar(num1, num2);
    }
    
    else {
        return dividir(num1, num2);
    }
}

double Calculadora::somar(double num1, double num2) {
    return num1 + num2;
}

double Calculadora::subtrair(double num1, double num2) {
    return num1 - num2;
}

double Calculadora::multiplicar(double num1, double num2) {
    return num1 * num2;
}

double Calculadora::dividir(double num1, double num2) {
    return num1 / num2;
};
