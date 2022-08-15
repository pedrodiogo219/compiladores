
#ifndef TOKEN
#define TOKEN

typedef enum {
    programa,
    id,
    constInt,
    constFloat,
    constChar,
    beginCmd,
    endCmd,
    tipoChar,
    tipoInt,
    tipoFloat,
    relop,
    atr,
    adi,
    sub,
    mul,
    divi,
    pot,
    pontoVirgula,
    virgula,
    abreParenteses,
    fechaParenteses,
    ifCmd,
    thenCmd,
    elseCmd,
    whileCmd,
    doCmd,
    repeatCmd,
    ERRO,
    cifrao
} TokenName;

string TokenNames[] = {
    "programa",
    "id",
    "constInt",
    "constFloat",
    "constChar",
    "beginCmd",
    "endCmd",
    "tipoChar",
    "tipoInt",
    "tipoFloat",
    "relop",
    "atr",
    "adi",
    "sub",
    "mul",
    "divi",
    "pot",
    "pontoVirgula",
    "virgula",
    "abreParenteses",
    "fechaParenteses",
    "ifCmd",
    "thenCmd",
    "elseCmd",
    "whileCmd",
    "doCmd",
    "repeatCmd",
    "ERRO",
    "cifrao"
};


typedef struct tk{
    TokenName nomeToken;
    int arg;

    tk(TokenName tn){
        this->nomeToken = tn;
        this->arg = -1;
    }

    tk(TokenName tn, int a){
        this->nomeToken = tn;
        this->arg = a;
    }

    string toString(){
        if (this->arg == -1){
            return "<" + TokenNames[this->nomeToken] + ">";
        }else{
            return "<" + TokenNames[this->nomeToken] + ", " + to_string(this->arg) + ">";
        }
    }
} Token;

#endif //TOKEN
