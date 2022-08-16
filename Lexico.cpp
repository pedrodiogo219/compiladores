#include<bits/stdc++.h>
using namespace std;

#include "Token.h"
#include "regrasAutomato.h"

#define BUFFER_MAX_TAM 16

typedef struct Lex {
    FILE *arquivo;
    int linha;
    int coluna;
    int pos;
    string estadoAtual;
    char buffer[BUFFER_MAX_TAM];
    int buffer_tam;

    unordered_map<string, bool> ehFinal;
    
    Lex(FILE * a){
        this->arquivo = a;
        this->linha = 1;
        this->coluna = 0;
        this->pos = 0;
        this->estadoAtual = "INICIAL";
        
        this->buffer_tam = fread(this->buffer, sizeof(char), BUFFER_MAX_TAM, this->arquivo);

        this->defineFinais();
    }


    char proxChar(){
        if (this->pos == BUFFER_MAX_TAM){
            this->buffer_tam = fread(this->buffer, sizeof(char), BUFFER_MAX_TAM, this->arquivo);
            this->pos = 0;
        }

        if (this->buffer_tam != BUFFER_MAX_TAM && this->pos == this->buffer_tam){
            // nada mais pra ler 
            return '$';
        }

        char c = this->buffer[this->pos++];
        this->coluna++;

        if (c == '\n'){
            this->linha++;
            this->coluna = 0;
            return this->proxChar();
        }
        if (c == ' '){
            return this->proxChar();
        }

        return c;
    }

    void lookAhead(){
        this->pos--;
    }

    void defineFinais(){
        ehFinal["M"] = true;
        ehFinal["N"] = true;
        ehFinal["O"] = true;
        ehFinal["P"] = true;
        ehFinal["Q"] = true;
        ehFinal["T"] = true;
        ehFinal["W"] = true;
        ehFinal["X"] = true;
        ehFinal["Y"] = true;
        ehFinal["Z"] = true;
        ehFinal["AC"] = true;
        ehFinal["AF"] = true;
        ehFinal["AK"] = true;
        ehFinal["AR"] = true;
        ehFinal["AS"] = true;
        ehFinal["AT"] = true;
        ehFinal["AU"] = true;
        ehFinal["AV"] = true;
        ehFinal["AW"] = true;
        ehFinal["AX"] = true;
        ehFinal["BB"] = true;
        ehFinal["BE"] = true;
        ehFinal["BK"] = true;
        ehFinal["BM"] = true;
        ehFinal["BN"] = true;
        ehFinal["BR"] = true;
        ehFinal["BV"] = true;
        ehFinal["BW"] = true;
        ehFinal["BX"] = true;
        ehFinal["CA"] = true;
        ehFinal["CE"] = true;
        ehFinal["CG"] = true;
        ehFinal["CI"] = true;
    }

    Token proxToken(){
        this->estadoAtual = "INICIAL";
        while(!this->ehFinal[this->estadoAtual]){
            char c = this->proxChar();
            
            cout << "char lido: " << c << " [lin: " << this->linha << ", col: " << this->coluna << "]\n"; 

            if (c == '$'){
                if (this->estadoAtual == "INICIAL"){
                    // final esperado
                    return Token(cifrao);
                }else{
                    cout << "EOF inesperado" << endl;
                    return Token(ERRO);
                }
            }

            this->estadoAtual = aplicaRegra(this->estadoAtual, c);
            // cout << "chego no estado: " << this->estadoAtual << endl;
            // cout << "eh final? " << this->ehFinal[this->estadoAtual] << endl;
            
            if (this->estadoAtual == "ERRO"){
                cout << "[Erro]: caractere nao esperado \'" << c << "\' [lin: " << this->linha << ", col: " << this->coluna << "]\n";
                exit(1);
            }
        }

        if (ehFinal[this->estadoAtual]){
            if (this->estadoAtual == "M"){
                return Token(adi);
            }else if (this->estadoAtual == "N"){
                return Token(sub);
            }else if (this->estadoAtual == "O"){
                return Token(mul);
            }else if (this->estadoAtual == "P"){
                return Token(divi);
            }else if (this->estadoAtual == "Q"){
                return Token(pot);
            }else if (this->estadoAtual == "T"){
                return Token(relop, 2);
            }else if (this->estadoAtual == "W"){
                return Token(pontoVirgula);
            }else if (this->estadoAtual == "X"){
                return Token(virgula);
            }else if (this->estadoAtual == "Y"){
                return Token(abreParenteses);
            }else if (this->estadoAtual == "Z"){
                return Token(fechaParenteses);
            }else if (this->estadoAtual == "AC"){
                // TODO: USAR O ID NA TAB DE SIMBOLOS
                lookAhead();
                return Token(id, 99999);
            }else if (this->estadoAtual == "AF"){
                return Token(doCmd);
            }else if (this->estadoAtual == "AK"){
                return Token(ifCmd);
            }else if (this->estadoAtual == "AR"){
                lookAhead();
                return Token(constInt, 99999);
            }else if (this->estadoAtual == "AS"){
                return Token(relop, 1);
            }else if (this->estadoAtual == "AT"){
                lookAhead();
                return Token(relop, 0);
            }else if (this->estadoAtual == "AU"){
                return Token(relop, 5);
            }else if (this->estadoAtual == "AV"){
                lookAhead();
                return Token(relop, 4);
            }else if (this->estadoAtual == "AW"){
                return Token(relop, 3);
            }else if (this->estadoAtual == "AX"){
                return Token(atr);
            }else if (this->estadoAtual == "BB"){
                return Token(endCmd);
            }else if (this->estadoAtual == "BE"){
                return Token(tipoInt);
            }else if (this->estadoAtual == "BK"){
                return Token(constChar, 99999);
            }else if (this->estadoAtual == "BM"){
                return Token(tipoChar);
            }else if (this->estadoAtual == "BN"){
                return Token(elseCmd);
            }else if (this->estadoAtual == "BR"){
                return Token(thenCmd);
            }else if (this->estadoAtual == "BV"){
                lookAhead();
                return Token(constFloat, 99999);
            }else if (this->estadoAtual == "BW"){
                return Token(beginCmd);
            }else if (this->estadoAtual == "BX"){
                return Token(tipoFloat);
            }else if (this->estadoAtual == "CA"){
                return Token(whileCmd);
            }else if (this->estadoAtual == "CE"){
                return Token(repeatCmd);
            }else if (this->estadoAtual == "CG"){
                lookAhead();
                return Token(constFloat, 99999);
            }else if (this->estadoAtual == "CI"){
                return Token(programa);
            }else{
                cout << "erro, alcancou estado final mas nao identificou qual" << endl;
            }
        }
        else{
            cout << "erro, nao chegou em estado final" << endl;
        }

        return Token(ERRO);
    }

} Lexer;


void printLex(Lexer l, char c){
    cout << "char lido: " << c << " [lin: " << l.linha << ", col: " << l.coluna << "]\n"; 
}

int main(){
    
    FILE *arquivo = fopen("programa.txt", "r");
    Lexer lex = Lexer(arquivo);


    while (true){
        Token t = lex.proxToken();
        if (t.nomeToken == ERRO || t.nomeToken == cifrao){
            cout << t.toString() << endl;    
            break;
        }
        cout << t.toString() << endl;
    }

    return 0;
}




