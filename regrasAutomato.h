#include<iostream>
#include "Token.h"

bool ehLetra(char c){
    // [a-zA-Z]
    return ((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z'));
}

bool ehDigito(char c){
    //[0,9]
    return (c >= '0' && c <= '9');
}


string aplicaRegra(string estadoAtual, char c){
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "N"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "O"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "P"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "Q"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "X"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "Y"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "Z"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AS"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AT"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AU"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AV"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AW"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "AX"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "BL"){
        if (c == 'n'){
            estadoAtual = "BW";
        }else if(ehLetra(c) || ehDigito(c)){
            estadoAtual = "AB";
        }else{
            estadoAtual = "AC";
        }
    }else if (estadoAtual == "BM"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "BN"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "BW"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "BX"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
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
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "CG"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "CH"){
        if (c == 'a'){
            estadoAtual = "CI";
        }else if(ehLetra(c) || ehDigito(c)){
            estadoAtual = "AB";
        }else{
            estadoAtual = "AC";
        }
    }else if (estadoAtual == "CI"){
        // estado final, nao pode chegar aqui
        estadoAtual = "ERRO";
    }else if (estadoAtual == "CJ"){
        if ( c == ']'){
            estadoAtual = "INICIAL";
        }else{
            estadoAtual = "CJ";
        }
    }

    return estadoAtual;
}