#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <new>

struct estrutura{
    int valorNumerico;
    struct estrutura *proximo;
};

int main(){
    setlocale(LC_ALL, "");

    //CRIA O INICIO DA MINHA LISTA
    estrutura *ponteiroEncadeado;

    //CRIA UM NOVO VALOR
    estrutura *novoPrimeiroValor = new estrutura;
    novoPrimeiroValor->valorNumerico = 13;
    novoPrimeiroValor->proximo = NULL;

    //FAZ O PONTEIRO DE ENCADEADO APONTAR PARA O PRIMEIRO VALOR
    ponteiroEncadeado = novoPrimeiroValor;

    //CRIA UM SEGUNDO VALOR
    estrutura *novoSegundoValor = new estrutura;
    novoSegundoValor->valorNumerico = 20;
    novoSegundoValor->proximo = NULL;

    //JUNTA IS VALORES ENCADEADI.
    ponteiroEncadeado->proximo = novoSegundoValor;

    //EMPRIME A LINHA ENCADEADA
    while(ponteiroEncadeado != NULL){
            //EMPRIME O VALOR ATUAL
        printf("Valor: %d\n", ponteiroEncadeado->valorNumerico);
        //CURSO RECEBE A POSIÇÃI DO PROXIMO VALOR
        ponteiroEncadeado = ponteiroEncadeado->proximo;
    }

    return 0;
}
