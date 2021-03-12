#include <vector>
#include "Token.h"

using namespace std;

class Expressao {
    
    public:
        Expressao( string = "" );
        vector<Token> converterParaRPN();
    
    private:
        vector<Token> tokens;
        
        void criarExpressao( string );
        int precedencia( Token );
        bool validarToken( Token );
};
