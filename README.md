# Projeto Construção de Compiladores

## Etapa Léxica

Foi implementado o código do analisador sintático, o mesmo está contido no arquivo 'Sintatico.cpp'.
Conforme solicitado, a abordagem utilizada foi a decida recursiva com construção da árvore sintática correspondente.

### Arquivo de configuração
Foi criado um arquivo de configuração para auxiliar a execução e teste do programa. O mesmo contém as seguintes possíveis configurações.

```json

char input_file[50] = "tests/programa.txt"; #arquivo de entrada do programa
int treeFlag = 0; # Mostra a arvore sintática produzida (0-nao mostrar/1-por nível/2-folhas)

```

Há 4 arquivos de teste prontos:
    - programa.txt
    - programaIF.txt
    - programaREPEAT.txt
    - programaWHILE.txt

### Compilação e Execução do programa

Para compilar o código e gerar o arquivo executável, rode o seguinte comando:
```sh
g++ -o Sint Sintatico.cpp
```
Será gerado o seguinte arquivo : Sint.exe

Para executalo, execute o seguinte comando:
```sh
./Sint
```

Se a linguagem estiver corretamente escrita, você receberá a seguinte mensagem:
```sh
Resultado: 
Cadeia aceita
```

Caso haja erro na linguagem, você receberá uma mensagem informando qual o erro e a linha e coluna correspondente, exemplo?
```sh
Erro!! Esperava ';' na linha: 7 e coluna: 13
``` 

Permanecemos a disposição para sanar qualquer eventual dúvida.

Atenciosamente,
Rodrigo Zamboni e Pedro Diogo