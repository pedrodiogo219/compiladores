#ifndef SIMBOLOS
#define SIMBOLOS

typedef enum
{
    SimbInt,
    SimbChar,
    SimbFloat,
    SimbUndef
} tipoSimbolo;

string nomesTipoSimbolo[] = {
    "SimbInt",
    "SimbChar",
    "SimbFloat",
    "SimbUndef"};

typedef struct Simb
{

    tipoSimbolo tipo;
    string id;

    void *valor = nullptr;

    Simb() {}

    Simb(tipoSimbolo t, string i, int v)
    {
        this->tipo = t;
        this->id = i;
        valor = (int *)malloc(sizeof(int));
        if (valor)
        {
            *((int *)valor) = v;
        }
    }

    Simb(string i)
    {
        this->tipo = SimbUndef;
        this->id = i;
    }

    Simb(tipoSimbolo t, string i)
    {
        this->tipo = t;
        this->id = i;
    }

    Simb(tipoSimbolo t, string i, char v)
    {
        this->tipo = t;
        this->id = i;

        valor = (char *)malloc(sizeof(char));
        if (valor)
        {
            *((char *)valor) = v;
        }
    }

    Simb(tipoSimbolo t, string i, double v)
    {
        this->tipo = t;
        this->id = i;

        valor = (double *)malloc(sizeof(double));
        if (valor)
        {
            *((double *)valor) = v;
        }
    }

    string toString()
    {
        if (!this->valor)
        {
            return "simbolo[id=" + this->id + ", tipo=" + nomesTipoSimbolo[this->tipo] + "]";
        }
        stringstream ss;
        if (this->tipo == SimbInt)
        {
            int auxI = *((int *)this->valor);
            ss << auxI;
        }
        else if (this->tipo == SimbChar)
        {
            char auxC = *((char *)this->valor);
            ss << auxC;
        }
        else if (this->tipo == SimbFloat)
        {
            double auxD = *((double *)this->valor);
            ss << auxD;
        }

        string val;
        ss >> val;

        return "simbolo[id=" + this->id + ", tipo=" + nomesTipoSimbolo[this->tipo] + ", valor=" + val + "]";
    }

} Simbolo;

typedef struct tab
{

    unordered_map<string, int> posicaoSimbolo;
    vector<Simbolo> v;
    int cont = 1;

    tab()
    {
        // preenche a primeira posicao com um simbolo vazio
        v.push_back(Simbolo());
    }

    int insereSimbolo(Simbolo s)
    {
        int posicao = posicaoSimbolo[s.id];

        if (posicao != 0)
        {
            v[posicaoSimbolo[s.id]] = s;
        }
        else
        {
            posicao = cont++;
            posicaoSimbolo[s.id] = posicao;
            v.push_back(s);
        }

        return posicao;
    }

    void mostraTabela()
    {
        cout << "###### tabela de simbolos ############" << endl;
        for (int i = 1; i < cont; i++)
        {
            cout << "pos: " << i << "\t " << v[i].toString() << endl;
        }
    }
} TabelaSimbolos;

#endif // SIMBOLOS
