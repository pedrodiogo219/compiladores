bool ehLetra(char c){
    // [a-zA-Z]
    return ((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z'));
}

bool ehDigito(char c){
    //[0,9]
    return (c >= '0' && c <= '9');
}

int stringToInt(string s){
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

char stringToChar(string s){
    return s[1];
}

double stringToFloat(string s){
    stringstream ss;
    ss << s;
    double res;
    ss >> res;
    return res;
}