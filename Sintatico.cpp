#include <bits/stdc++.h>
using namespace std;

#include "Lexico.cpp"
#include "Arvore.cpp"
#include "config.cpp"

typedef struct Sintatico
{
    TabelaSimbolos T = TabelaSimbolos();
    FILE *arquivo = fopen(input_file, "r");
    Lexer lex = Lexer(arquivo, &T);
    Token tk = Token(cifrao);

    No *root;

    Sintatico()
    {
        this->tk = Token(cifrao);
    }

    void mostraErro(string nomeToken, int linha, int coluna)
    {
        cout << "Erro!! Esperava '" << nomeToken << "' na linha: " << linha << " e coluna: " << coluna << endl;
        exit(1);
    }

    void mostraErroGenerico(int linha, int coluna)
    {
        cout << "Erro!! Token invalido na linha: " << linha << " e coluna: " << coluna << endl;
        exit(1);
    }

    bool first(string prod)
    {
        int t = this->tk.nomeToken;

        if (prod == "ATT")
        {

            if (t == id)
            {
                return true;
            }
            else
                return false;
        }
        else if (prod == "CMD")
        {

            if (t == id || t == ifCmd || t == whileCmd || t == repeatCmd)
            {
                return true;
            }
            else
                return false;
        }
        else if (prod == "DECL")
        {
            if (t == tipoChar || t == tipoInt || t == tipoFloat)
            {
                return true;
            }
            else
                return false;
        }
        else if (prod == "IF")
        {
            if (t == ifCmd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (prod == "WHILE")
        {
            if (this->tk.nomeToken == whileCmd)
            {
                return true;
            }
            else
                return false;
        }
        else if (prod == "REPEAT")
        {
            if (this->tk.nomeToken == repeatCmd)
            {
                return true;
            }
            else
                return false;
        }
        else if (prod == "COMMENT")
        {
        }
        return false;
    }

    void analisa()
    {
        this->tk = this->lex.proxToken();
        this->root = novoNo("S");
        procedimento_S(this->root);
        this->tk = this->lex.proxToken();

        switch (treeFlag)
        {
        case 1:
            cout << "Arvore de Derivacao (por nivel):" << endl;
            mostraArvorePorNivel(this->root);
            cout << endl;
            break;
        case 2:
            cout << "Arvore de Derivacao ( folhas ):" << endl;
            mostraFolhasArvore(this->root);
            cout << endl;
            break;
        default:
            break;
        }

        cout << "Resultado: " << endl;
        if (this->tk.nomeToken == cifrao)
        {
            cout << "Cadeia aceita" << endl;
        }
        else
        {
            cout << "Cadeia rejeitada" << endl;
        }
    }

    void procedimento_S(No *n)
    {
        if (this->tk.nomeToken == programa)
        {
            n->filhos.push_back(novoNo("programa"));
            this->tk = this->lex.proxToken();
            if (this->tk.nomeToken == id)
            {
                n->filhos.push_back(novoNo("id"));
                this->tk = this->lex.proxToken();

                if (this->tk.nomeToken == pontoVirgula)
                {
                    this->tk = this->lex.proxToken();
                    No *n1 = novoNo("BLOCO");
                    n->filhos.push_back(n1);
                    this->procedimento_BLOCO(n1);
                }
                else
                {
                    mostraErro(";", this->lex.linha, this->lex.coluna);
                }
            }
            else
            {
                mostraErro("id", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("programa", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_BLOCO(No *n)
    {
        if (this->tk.nomeToken == beginCmd)
        {
            n->filhos.push_back(novoNo("begin"));
            this->tk = this->lex.proxToken();

            n->filhos.push_back(novoNo("SDECL"));
            procedimento_SDECL(n->filhos[1]);

            n->filhos.push_back(novoNo("SEQ"));
            procedimento_SEQ(n->filhos[2]);

            if (this->tk.nomeToken == endCmd)
            {
                n->filhos.push_back(novoNo("end"));
                this->tk = this->tk = this->lex.proxToken();
            }
            else
            {
                mostraErro("end", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("begin", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_SDECL(No *n)
    {

        while (first("DECL"))
        {
            n->filhos.push_back(novoNo("DECL"));
            procedimento_DECL(n->filhos[0]);

            n->filhos.push_back(novoNo("SDECL"));
            procedimento_SDECL(n->filhos[1]);
        }
    }

    void procedimento_DECL(No *n)
    {

        if (this->tk.nomeToken == tipoChar || this->tk.nomeToken == tipoInt || this->tk.nomeToken == tipoFloat)
        {
            n->filhos.push_back(novoNo("tipo"));
            this->tk = this->lex.proxToken();

            n->filhos.push_back(novoNo("LIDS"));
            procedimento_LIDS(n->filhos[1], this->tk.nomeToken);

            if (this->tk.nomeToken == pontoVirgula)
            {
                n->filhos.push_back(novoNo(";"));
                this->tk = this->lex.proxToken();
            }
            else
            {
                mostraErro(";", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErroGenerico(this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_LIDS(No *n, TokenName tn)
    {

        if (this->tk.nomeToken == id)
        {

            // cout << this->tk.toString() << " - " << this->tk.arg << " - " << this->lex.T->v[this->tk.arg].toString() << " - " << tok.nomeToken << " - " << tipoInt << endl;

            if (tn == tipoChar)
            {
                this->lex.T->v[this->tk.arg].tipo = SimbChar;
                this->T.v[this->tk.arg].tipo = SimbChar;
            }
            else if (tn == tipoFloat)
            {
                this->lex.T->v[this->tk.arg].tipo = SimbFloat;
                this->T.v[this->tk.arg].tipo = SimbFloat;
            }
            else if (tn == tipoInt)
            {
                this->lex.T->v[this->tk.arg].tipo = SimbInt;
                this->T.v[this->tk.arg].tipo = SimbInt;
            }

            n->filhos.push_back(novoNo("id"));
            this->tk = this->lex.proxToken();

            n->filhos.push_back(novoNo("RLIDS"));
            procedimento_RLIDS(n->filhos[1], tn);
        }
        else
        {
            mostraErro("id", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_RLIDS(No *n, TokenName tn)
    {

        while (this->tk.nomeToken == virgula)
        {
            n->filhos.push_back(novoNo(","));
            this->tk = this->lex.proxToken();
            if (this->tk.nomeToken == id)
            {
                n->filhos.push_back(novoNo("id"));
                this->tk = this->lex.proxToken();

                No *aux = novoNo("RLIDS");
                n->filhos.push_back(aux);
                procedimento_RLIDS(aux, tn);
            }
            else
            {
                mostraErro("id", this->lex.linha, this->lex.coluna);
            }
        }
    }

    void procedimento_CMD(No *n)
    {
        while (first("ATT") || first("IF") || first("WHILE") || first("REPEAT") || first("COMMENT"))
        {
            if (first("ATT"))
            {
                No *aux = novoNo("ATT");
                n->filhos.push_back(aux);
                procedimento_att(aux);
            }
            else if (first("IF"))
            {
                No *aux1 = novoNo("IF");
                n->filhos.push_back(aux1);
                procedimento_if(aux1);
            }
            else if (first("WHILE"))
            {
                No *aux2 = novoNo("WHILE");
                n->filhos.push_back(aux2);
                procedimento_while(aux2);
            }
            else if (first("REPEAT"))
            {
                No *aux3 = novoNo("REPEAT");
                n->filhos.push_back(aux3);
                procedimento_repeat(aux3);
            }
            else
            {
                mostraErroGenerico(this->lex.linha, this->lex.coluna);
            }
        }
    }

    void procedimento_SEQ(No *n)
    {

        while (first("CMD"))
        {
            No *aux = novoNo("CMD");
            n->filhos.push_back(aux);
            procedimento_CMD(aux);

            No *aux1 = novoNo("SEQ");
            n->filhos.push_back(aux1);
            procedimento_SEQ(aux1);
        }
    }
    void procedimento_EXP(No *n)
    {
        No *aux = novoNo("TERM");
        n->filhos.push_back(aux);
        procedimento_TERM(aux);

        No *aux2 = novoNo("EXPR");
        n->filhos.push_back(aux2);
        procedimento_EXPR(aux2);
    }

    void procedimento_EXPR(No *n)
    {
        if (this->tk.nomeToken == adi)
        {
            n->filhos.push_back(novoNo("+"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("TERM");
            n->filhos.push_back(aux);
            procedimento_TERM(aux);

            No *aux2 = novoNo("EXPR");
            n->filhos.push_back(aux2);
            procedimento_EXPR(aux2);
        }
        else if (this->tk.nomeToken == sub)
        {
            n->filhos.push_back(novoNo("-"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("TERM");
            n->filhos.push_back(aux);
            procedimento_TERM(aux);

            No *aux2 = novoNo("EXPR");
            n->filhos.push_back(aux2);
            procedimento_EXPR(aux2);
        }
    }

    void procedimento_TERM(No *n)
    {
        No *aux = novoNo("POT");
        n->filhos.push_back(aux);
        procedimento_POT(aux);

        No *aux2 = novoNo("TERMR");
        n->filhos.push_back(aux2);
        procedimento_TERMR(aux2);
    }

    void procedimento_TERMR(No *n)
    {
        if (this->tk.nomeToken == mul)
        {
            n->filhos.push_back(novoNo("*"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("FACTOR");
            n->filhos.push_back(aux);
            procedimento_FACTOR(aux);

            No *aux2 = novoNo("POTR");
            n->filhos.push_back(aux2);
            procedimento_POTR(aux2);
        }
        else if (this->tk.nomeToken == divi)
        {
            n->filhos.push_back(novoNo("/"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("FACTOR");
            n->filhos.push_back(aux);
            procedimento_FACTOR(aux);

            No *aux2 = novoNo("POTR");
            n->filhos.push_back(aux2);
            procedimento_POTR(aux2);
        }
    }

    void procedimento_POT(No *n)
    {

        No *aux = novoNo("FACTOR");
        n->filhos.push_back(aux);
        procedimento_FACTOR(aux);

        No *aux2 = novoNo("POTR");
        n->filhos.push_back(aux2);
        procedimento_POTR(aux2);
    }

    void procedimento_FACTOR(No *n)
    {

        if (this->tk.nomeToken == abreParenteses)
        {
            n->filhos.push_back(novoNo("("));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("EXP");
            n->filhos.push_back(aux);
            procedimento_EXP(aux);

            if (this->tk.nomeToken == fechaParenteses)
            {
                n->filhos.push_back(novoNo(")"));
                this->tk = this->lex.proxToken();
            }
            else
            {
                mostraErro(")", this->lex.linha, this->lex.coluna);
            }
        }
        else if (this->tk.nomeToken == id)
        {
            n->filhos.push_back(novoNo("id"));
            this->tk = this->lex.proxToken();
        }
        else if (this->tk.nomeToken == constInt || this->tk.nomeToken == constFloat || this->tk.nomeToken == constChar)
        {
            n->filhos.push_back(novoNo("const"));
            this->tk = this->lex.proxToken();
        }
        else
        {
            mostraErroGenerico(this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_POTR(No *n)
    {

        while (this->tk.nomeToken == pot)
        {
            n->filhos.push_back(novoNo("^"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("FACTOR");
            n->filhos.push_back(aux);
            procedimento_FACTOR(aux);

            No *aux2 = novoNo("POTR");
            n->filhos.push_back(aux2);
            procedimento_POTR(aux2);
        }
    }

    void procedimento_att(No *n)
    {
        if (this->tk.nomeToken == id)
        {

            // if (this->T.v[this->tk.arg].tipo == SimbUndef)
            // {
            //     cout << "Variável " << this->T.v[this->tk.arg].id << " não foi declarada." << endl;
            //     exit(1);
            // }

            n->filhos.push_back(novoNo("id"));
            this->tk = this->lex.proxToken();
            if (this->tk.nomeToken == atr)
            {
                n->filhos.push_back(novoNo(":="));
                this->tk = this->lex.proxToken();

                No *aux = novoNo("EXP");
                n->filhos.push_back(aux);
                procedimento_EXP(aux);

                if (this->tk.nomeToken == pontoVirgula)
                {
                    n->filhos.push_back(novoNo(";"));
                    this->tk = this->lex.proxToken();
                }
                else
                {
                    mostraErro(";", this->lex.linha, this->lex.coluna);
                }
            }
            else
            {
                mostraErro(":=", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("id", this->lex.linha, this->lex.coluna);
        }
    }
    void procedimento_if(No *n)
    {
        if (this->tk.nomeToken == ifCmd)
        {

            n->filhos.push_back(novoNo("if"));
            this->tk = this->lex.proxToken();

            if (this->tk.nomeToken == abreParenteses)
            {
                n->filhos.push_back(novoNo("("));
                this->tk = this->lex.proxToken();

                No *aux = novoNo("COND");
                n->filhos.push_back(aux);
                procedimento_COND(aux);

                if (this->tk.nomeToken == fechaParenteses)
                {
                    n->filhos.push_back(novoNo(")"));
                    this->tk = this->lex.proxToken();

                    if (this->tk.nomeToken == thenCmd)
                    {
                        n->filhos.push_back(novoNo("then"));
                        this->tk = this->lex.proxToken();

                        No *aux2 = novoNo("BLOCO");
                        n->filhos.push_back(aux2);
                        procedimento_BLOCO(aux2);

                        if (this->tk.nomeToken == elseCmd)
                        {
                            n->filhos.push_back(novoNo("else"));
                            this->tk = this->lex.proxToken();

                            No *aux3 = novoNo("BLOCO");
                            n->filhos.push_back(aux3);
                            procedimento_BLOCO(aux3);
                        }
                        else
                        {
                            mostraErro("else", this->lex.linha, this->lex.coluna);
                        }
                    }
                    else
                    {
                        mostraErro("then", this->lex.linha, this->lex.coluna);
                    }
                }
                else
                {
                    mostraErro(")", this->lex.linha, this->lex.coluna);
                }
            }
            else
            {
                mostraErro("(", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("if", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_COND(No *n)
    {
        No *aux = novoNo("EXP");
        n->filhos.push_back(aux);
        procedimento_EXP(aux);

        No *aux2 = novoNo("RELOP");
        n->filhos.push_back(aux2);
        procedimento_RELOP(aux2);

        No *aux3 = novoNo("EXP");
        n->filhos.push_back(aux3);
        procedimento_EXP(aux3);
    }

    void procedimento_RELOP(No *n)
    {

        if (this->tk.nomeToken == relop)
        {
            n->filhos.push_back(novoNo("relop"));
            this->tk = this->lex.proxToken();
        }
        else
        {
            mostraErro("operador relacional", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_while(No *n)
    {
        if (this->tk.nomeToken == whileCmd)
        {
            n->filhos.push_back(novoNo("while"));
            this->tk = this->lex.proxToken();

            if (this->tk.nomeToken == abreParenteses)
            {
                n->filhos.push_back(novoNo("("));
                this->tk = this->lex.proxToken();

                No *aux = novoNo("COND");
                n->filhos.push_back(aux);
                procedimento_COND(aux);

                if (this->tk.nomeToken == fechaParenteses)
                {
                    n->filhos.push_back(novoNo(")"));
                    this->tk = this->lex.proxToken();

                    if (this->tk.nomeToken == doCmd)
                    {
                        n->filhos.push_back(novoNo("do"));
                        this->tk = this->lex.proxToken();

                        No *aux2 = novoNo("BLOCO");
                        n->filhos.push_back(aux2);
                        procedimento_BLOCO(aux2);
                    }
                    else
                    {
                        mostraErro("do", this->lex.linha, this->lex.coluna);
                    }
                }
                else
                {
                    mostraErro(")", this->lex.linha, this->lex.coluna);
                }
            }
            else
            {
                mostraErro("(", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("while", this->lex.linha, this->lex.coluna);
        }
    }

    void procedimento_repeat(No *n)
    {

        if (this->tk.nomeToken == repeatCmd)
        {
            n->filhos.push_back(novoNo("repeat"));
            this->tk = this->lex.proxToken();

            No *aux = novoNo("BLOCO");
            n->filhos.push_back(aux);
            procedimento_BLOCO(aux);

            if (this->tk.nomeToken == whileCmd)
            {
                n->filhos.push_back(novoNo("while"));
                this->tk = this->lex.proxToken();

                if (this->tk.nomeToken == abreParenteses)
                {
                    n->filhos.push_back(novoNo("("));
                    this->tk = this->lex.proxToken();

                    No *aux2 = novoNo("COND");
                    n->filhos.push_back(aux2);
                    procedimento_COND(aux2);

                    if (this->tk.nomeToken == fechaParenteses)
                    {
                        n->filhos.push_back(novoNo(")"));
                        this->tk = this->lex.proxToken();
                    }
                    else
                    {
                        mostraErro(")", this->lex.linha, this->lex.coluna);
                    }
                }
                else
                {
                    mostraErro("(", this->lex.linha, this->lex.coluna);
                }
            }
            else
            {
                mostraErro("while", this->lex.linha, this->lex.coluna);
            }
        }
        else
        {
            mostraErro("repeat", this->lex.linha, this->lex.coluna);
        }
    }

} Sintatico;

int main()
{

    Sintatico sint = Sintatico();

    sint.analisa();
}