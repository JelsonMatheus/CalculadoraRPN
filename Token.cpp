#include "Token.h"

using namespace std;

Token::Token(string simbolo) {
    token = simbolo;
}

string Token::obterToken() {
    return token;
}

bool Token::ehOperador() {
    switch(token[0]) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
        default:
            return false;
    }
}

bool Token::ehNumero() {
    try {
        stod(token);
        return true;
    } 
    catch(...) {
        return false;
    }
}

bool Token::ehIgual(Token outro) {
    if(token.compare(outro.obterToken()) == 0) {
        return true;
    }
    return false;
}