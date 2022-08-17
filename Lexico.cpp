#include<bits/stdc++.h>
using namespace std;

#include "Token.h"

#include "aux.h"

#include "Simbolos.h"

#define BUFFER_MAX_TAM 16

#define debug 0

typedef struct Lex {
    FILE *arquivo;
    TabelaSimbolos * T;
    int linha;
    int coluna;
    int pos;
    string estadoAtual;
    char buffer[BUFFER_MAX_TAM];
    int buffer_tam;

    unordered_map<string, bool> ehFinal;
    
    Lex(FILE * a, TabelaSimbolos * T){
        this->arquivo = a;
        this->T = T;

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
        if (debug){
            cout << "Look ahead: o ultimo char vai ser lido novamente" << endl;
        }
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
        ehFinal["ERRO"] = true;
    }

    Token proxToken(){
        this->estadoAtual = "INICIAL";
        char c;

        string idAtual = "";

        while(true){
            if (!this->ehFinal[this->estadoAtual]){
                c = this->proxChar();
                idAtual += c;
                if (debug){
                    cout << "char lido: " << c << " [lin: " << this->linha << ", col: " << this->coluna << "]\n"; 
                }
            }

            if (c == '$'){
                if (this->estadoAtual == "INICIAL"){
                    // final esperado
                    return Token(cifrao);
                }else{
                    cout << "EOF inesperado" << endl;
                    return Token(ERRO);
                }
            }

            //####################### REGRAS AUTOMATO ##############################
            if (estadoAtual == "INICIAL"){
                if (c == 'b'){
                    estadoAtual = "B";
                }
                else if (c == 'c'){
                    estadoAtual = "C";
                }
                else if (c == 'd'){
                    estadoAtual = "D";
                }
                else if (c == 'e'){
                    estadoAtual = "E";
                }
                else if (c == 'f'){
                    estadoAtual = "F";
                }
                else if (c == 'i'){
                    estadoAtual = "G";
                }
                else if (c == 'p'){
                    estadoAtual = "H";
                }
                else if (c == 'r'){
                    estadoAtual = "I";
                }
                else if (c == 't'){
                    estadoAtual = "J";
                }
                else if (c == 'w'){
                    estadoAtual = "K";
                }
                else if (ehLetra(c)){
                    estadoAtual = "A";
                }
                else if (ehDigito(c)){
                    estadoAtual = "L";
                }
                else if (c == '+'){
                    estadoAtual = "M";
                }
                else if (c == '-'){
                    estadoAtual = "N";
                }
                else if (c == '*'){
                    estadoAtual = "O";
                }
                else if (c == '/'){
                    estadoAtual = "P";
                }
                else if (c == '^'){
                    estadoAtual = "Q";
                }
                else if (c == '<'){
                    estadoAtual = "R";
                }
                else if (c == '>'){
                    estadoAtual = "S";
                }
                else if (c == '='){
                    estadoAtual = "T";
                }
                else if (c == '~'){
                    estadoAtual = "U";
                }
                else if (c == ':'){
                    estadoAtual = "V";
                }
                else if (c == ';'){
                    estadoAtual = "W";
                }
                else if (c == ','){
                    estadoAtual = "X";
                }
                else if (c == '('){
                    estadoAtual = "Y";
                }
                else if (c == ')'){
                    estadoAtual = "Z";
                }
                else if (c == '\''){
                    estadoAtual = "AA";
                }
                else if (c == '['){
                    estadoAtual = "CJ";
                }
                else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "B"){
                if (c == 'e'){
                    estadoAtual = "AD";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "C"){
                if (c == 'h'){
                    estadoAtual = "AE";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "D"){
                if (c == 'o'){
                    estadoAtual = "AF";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "E"){
                if (c == 'n'){
                    estadoAtual = "AG";
                }else if (c == 'l'){
                    estadoAtual = "AH";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "F"){
                if (c == 'l'){
                    estadoAtual = "AI";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "G"){
                if (c == 'n'){
                    estadoAtual = "AJ";
                }else if (c == 'f'){
                    estadoAtual = "AK";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "H"){
                if (c == 'r'){
                    estadoAtual = "AL";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "I"){
                if (c == 'e'){
                    estadoAtual = "AM";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "J"){
                if (c == 'h'){
                    estadoAtual = "AN";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "K"){
                if (c == 'h'){
                    estadoAtual = "AO";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "A"){
                if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "L"){
                if (ehDigito(c)){
                    estadoAtual = "L";
                }else if(c == '.'){
                    estadoAtual = "AQ";
                }else{
                    estadoAtual = "AR";
                }
            }else if (estadoAtual == "M"){
                return Token(adi);
            }else if (estadoAtual == "N"){
                return Token(sub);
            }else if (estadoAtual == "O"){
                return Token(mul);
            }else if (estadoAtual == "P"){
                return Token(divi);
            }else if (estadoAtual == "Q"){
                return Token(pot);
            }else if (estadoAtual == "R"){
                if (c == '='){
                    estadoAtual = "AS";
                }else {
                    estadoAtual = "AT";
                }
            }else if (estadoAtual == "S"){
                if (c == '='){
                    estadoAtual = "AU";
                }else {
                    estadoAtual = "AV";
                }
            }else if (estadoAtual == "T"){
                return Token(relop, 2);
            }else if (estadoAtual == "U"){
                if(c == '='){
                    estadoAtual = "AW";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "V"){
                if(c == '='){
                    estadoAtual = "AX";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "W"){
                return Token(pontoVirgula);
            }else if (estadoAtual == "X"){
                return Token(virgula);
            }else if (estadoAtual == "Y"){
                return Token(abreParenteses);
            }else if (estadoAtual == "Z"){
                return Token(fechaParenteses);
            }else if (estadoAtual == "AA"){
                if (ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AY";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "AB"){
                if (ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AC"){
                lookAhead();
                idAtual.pop_back();
                Simbolo novoSimbolo = Simbolo(idAtual);
                int pos = this->T->insereSimbolo(novoSimbolo);
                return Token(id, pos);
            }else if (estadoAtual == "AD"){
                if (c == 'g'){
                    estadoAtual = "AZ";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AE"){
                if (c == 'a'){
                    estadoAtual = "BA";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AF"){
                return Token(doCmd);
            }else if (estadoAtual == "AG"){
                if (c == 'd'){
                    estadoAtual = "BB";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AH"){
                if (c == 's'){
                    estadoAtual = "BC";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AI"){
                if (c == 'o'){
                    estadoAtual = "BD";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AJ"){
                if (c == 't'){
                    estadoAtual = "BE";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AK"){
                return Token(ifCmd);
            }else if (estadoAtual == "AL"){
                if (c == 'o'){
                    estadoAtual = "BF";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AM"){
                if (c == 'p'){
                    estadoAtual = "BG";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AN"){
                        if (c == 'e'){
                    estadoAtual = "BH";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AO"){
                if (c == 'i'){
                    estadoAtual = "BI";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "AQ"){
                if (ehDigito(c)){
                    estadoAtual = "BJ";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "AR"){
                lookAhead();
                idAtual.pop_back();
                Simbolo novoSimbolo = Simbolo(SimbInt, "constInt", stringToInt(idAtual));
                int pos = this->T->insereSimbolo(novoSimbolo);
                return Token(constInt, pos);
            }else if (estadoAtual == "AS"){
                return Token(relop, 1);
            }else if (estadoAtual == "AT"){
                lookAhead();
                return Token(relop, 0);
            }else if (estadoAtual == "AU"){
                return Token(relop, 5);
            }else if (estadoAtual == "AV"){
                lookAhead();
                return Token(relop, 4);
            }else if (estadoAtual == "AW"){
                return Token(relop, 3);
            }else if (estadoAtual == "AX"){
                return Token(atr);
            }else if (estadoAtual == "AY"){
                if (c == '\''){
                    estadoAtual = "BK";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "AZ"){
                if (c == 'i'){
                    estadoAtual = "BL";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BA"){
                if (c == 'r'){
                    estadoAtual = "BM";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BB"){
                return Token(endCmd);
            }else if (estadoAtual == "BC"){
                if (c == 'e'){
                    estadoAtual = "BN";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BD"){
                if (c == 'a'){
                    estadoAtual = "BO";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BE"){
                return Token(tipoInt);
            }else if (estadoAtual == "BF"){
                if (c == 'g'){
                    estadoAtual = "BP";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BG"){
                if (c == 'e'){
                    estadoAtual = "BQ";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BH"){
                if (c == 'n'){
                    estadoAtual = "BR";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BI"){
                if (c == 'l'){
                    estadoAtual = "BS";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BJ"){
                if (ehDigito(c)){
                    estadoAtual = "BJ";
                }else if (c == 'E'){
                    estadoAtual = "BU";
                }else{
                    estadoAtual = "BV";
                }
            }else if (estadoAtual == "BK"){
                Simbolo novoSimbolo = Simbolo(SimbChar, "constChar", stringToChar(idAtual));
                int pos = this->T->insereSimbolo(novoSimbolo);
                return Token(constChar, pos);
            }else if (estadoAtual == "BL"){
                if (c == 'n'){
                    estadoAtual = "BW";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BM"){
                return Token(tipoChar);
            }else if (estadoAtual == "BN"){
                return Token(elseCmd);
            }else if (estadoAtual == "BO"){
                if (c == 't'){
                    estadoAtual = "BX";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BP"){
                if (c == 'r'){
                    estadoAtual = "BY";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BQ"){
                if (c == 'a'){
                    estadoAtual = "BZ";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BR"){
                return Token(thenCmd);
            }else if (estadoAtual == "BS"){
                if (c == 'e'){
                    estadoAtual = "CA";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BU"){
                if (c == '-'){
                    estadoAtual = "CB";
                }else if (ehDigito(c)){
                    estadoAtual = "CC";
                }
            }else if (estadoAtual == "BV"){
                lookAhead();
                idAtual.pop_back();
                Simbolo novoSimbolo = Simbolo(SimbFloat, "constFloat", stringToFloat(idAtual));
                int pos = this->T->insereSimbolo(novoSimbolo);
                return Token(constFloat, pos);
            }else if (estadoAtual == "BW"){
                return Token(beginCmd);
            }else if (estadoAtual == "BX"){
                return Token(tipoFloat);
            }else if (estadoAtual == "BY"){
                if (c == 'a'){
                    estadoAtual = "CD";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "BZ"){
                if (c == 't'){
                    estadoAtual = "CE";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "CA"){
                return Token(whileCmd);
            }else if (estadoAtual == "CB"){
                if (ehDigito(c)){
                    estadoAtual = "CC";
                }else{
                    estadoAtual = "ERRO";
                }
            }else if (estadoAtual == "CC"){
                if (ehDigito(c)){
                    estadoAtual = "CC";
                }else{
                    estadoAtual = "CG";
                }
            }else if (estadoAtual == "CD"){
                if (c == 'm'){
                    estadoAtual = "CH";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "CE"){
                return Token(repeatCmd);
            }else if (estadoAtual == "CG"){
                lookAhead();
                idAtual.pop_back();
                Simbolo novoSimbolo = Simbolo(SimbFloat, "constFloat", stringToFloat(idAtual));
                int pos = this->T->insereSimbolo(novoSimbolo);
                return Token(constFloat, pos);
            }else if (estadoAtual == "CH"){
                if (c == 'a'){
                    estadoAtual = "CI";
                }else if(ehLetra(c) || ehDigito(c)){
                    estadoAtual = "AB";
                }else{
                    estadoAtual = "AC";
                }
            }else if (estadoAtual == "CI"){
                return Token(programa);
            }else if (estadoAtual == "CJ"){
                if ( c == ']'){
                    estadoAtual = "INICIAL";
                    idAtual = "";
                }else{
                    estadoAtual = "CJ";
                }
            }else if (estadoAtual == "ERRO"){
                cout << "ERRO caractere inesperado: \'" << c << "\' pos: [lin: " << this->linha << ", col: " << this->coluna << "]\n";
                return Token(ERRO);
            }
            // ############################### FIM REGRAS AUTOMATO ###########################
        }

        return Token(ERRO);
    }

} Lexer;



int main(){
    
    TabelaSimbolos T = TabelaSimbolos();
    FILE *arquivo = fopen("programa.txt", "r");
    Lexer lex = Lexer(arquivo, &T);


    while (true){
        Token t = lex.proxToken();
        if (t.nomeToken == ERRO || t.nomeToken == cifrao){
            cout << t.toString() << endl;
            break;
        }
        
        cout << t.toString();
        if (debug && t.nomeToken == id){
            cout << "    id: " << T.v[t.arg].id;
        }
        cout << endl;
    }

    

    // Simbolo s1 = Simbolo(SimbInt, "X", 11);
    // Simbolo s2 = Simbolo(SimbInt, "Y", 12);
    // Simbolo s3 = Simbolo(SimbInt, "Z", 13);
    // Simbolo s4 = Simbolo(SimbInt, "X", 99);


    // T.insereSimbolo(s1);
    // T.insereSimbolo(s2);
    // T.insereSimbolo(s3);
    // T.insereSimbolo(s4);

    T.mostraTabela();


    return 0;
}




