#include <string>

using namespace std;

class Token {
    
    public:
        Token( string = "" );
        string obterToken();
        bool ehOperador();
        bool ehNumero();
        bool ehIgual( Token );
    private:
        string token;
};
