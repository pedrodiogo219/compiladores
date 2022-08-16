#include<iostream>

bool ehLetra(char c){
    // [a-zA-Z]
    return ((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z'));
}

bool ehDigito(char c){
    //[0,9]
    return (c >= '0' && c <= '9');
}