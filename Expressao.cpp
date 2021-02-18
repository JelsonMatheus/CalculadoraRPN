#include <iostream>
#include <stack>
#include <stdexcept>
#include "Expressao.h"

using namespace std;

Expressao::Expressao(string expressao) {
    criarExpressao(expressao);
}

vector<Token> Expressao::converterParaRPN() {
    
    vector<Token> rpn;
    stack<Token> pilha;
    Token simb;
    
    for(int i = 0; i < tokens.size(); i++) {
        
        simb = tokens.at(i);
        
        if(simb.ehNumero()) {
            rpn.push_back(simb);
        }
        
        else if(simb.ehOperador()){
            
            while(!pilha.empty() && 
                precedencia(pilha.top()) >= precedencia(simb))
            {
                rpn.push_back(pilha.top());
                pilha.pop();
            }
            
            pilha.push(simb);
        }
        
        else if(simb.ehIgual(Token("("))) {
            pilha.push(simb);
        }
        
        else if(simb.ehIgual(Token(")"))) {
            
            while(!pilha.top().ehIgual(Token("("))) {
                rpn.push_back(pilha.top());
                pilha.pop();
            }
            
            pilha.pop();
        }
    }
    
    while(!pilha.empty()) {
        rpn.push_back(pilha.top());
        pilha.pop();
    }
    
    return rpn;
}

void Expressao::criarExpressao(string expressao) {
    string aux;
    char ch;
    
    for(int i = 0; i < expressao.size(); i++) {
        ch = expressao[i];
        
        if(isdigit(ch) || ch == '.') {
            aux.append(1, ch);
        }
        
        else {
            
            if(!aux.empty()) {
                tokens.push_back(Token(aux));
                aux.clear();
            }
            
            if(ch != ' ') {
                tokens.push_back(Token(string(1, ch)));
            }
        }
    }
    
    if(!aux.empty()) {
        tokens.push_back(Token(aux));
    }
    
    for(int i = 0; i < tokens.size(); i++) {
        if(!validarToken(tokens.at(i))) {
            throw 
                "Valor inválido: " + tokens.at(i).obterToken();
        }
    }
}

int Expressao::precedencia(Token token) {
    char simbolo = token.obterToken()[0];
    
    switch(simbolo) {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default:
            return 0;
    }
}

bool Expressao::validarToken( Token token) {

    char simbolos[2] = {'(', ')'};
    
    if(token.ehOperador() || token.ehNumero())
        return true;
    
    for(int i = 0; i < 2; i++) {
        if(token.obterToken()[0] == simbolos[i])
            return true;
    }
    
    return false;
};