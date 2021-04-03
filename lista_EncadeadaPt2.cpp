#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <new>
#include <iostream>
#include <string>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

void limpaTela(){
    system("CLS");
}

int retornaTamanho(pessoa *ponteiroEncadeada){

    //SE A LISTA ESTÁ VAZIA0
    if(ponteiroEncadeada->nome == ""){
        return 0;
    }

    int tamanho = 0;
    pessoa *p = ponteiroEncadeada;

    while(p != NULL){
        p = p->proximo;

        tamanho++;
    }
    return tamanho;
}

void imprimeEncadeada(pessoa *ponteiroEncadeada){

    //PONTEIRO CURSO AUXILIAR
    pessoa *p = ponteiroEncadeada;

    while(p != NULL){
        //IMPRIME A LISTA
        cout << p->nome << ", " << p->rg << "\n";
        p = p->proximo;
    }

}

void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    //CRIA UMA NOVA ESTRUTURA
    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->rg = rg;

    //VERIFICA SE A LISTA ESTA VAZIA
    if(ponteiroEncadeada->nome == ""){
        novaPessoa->proximo = NULL;
    }else{
        novaPessoa->proximo = ponteiroEncadeada;
    }

    //REDIRECIONA O NOVO VALOR
    ponteiroEncadeada = novaPessoa;

}

void adcFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    //CRIA UMA NOVA ESTRUTURA
    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->rg = rg;
    novaPessoa->proximo = NULL;

    //PONTEIRO CURSO AUXILIAR
    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        //quando chega no final da lista faz ele apontar para o novo valor
        if(p->proximo == NULL){

            //OPONTA PARA A NOVA PESSOA
            p->proximo = novaPessoa;
            return;
        }

        //ATUALIZA O CURSO
        p = p->proximo;
    }
}

void adcPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    //CRIA UMA NOVA ESTRUTURA
    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->rg = rg;
    novaPessoa->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while(cont <= posicao){

        if(cont == posicao - 1){

                //AUXILAR DO VALOR
                pessoa *aux = new pessoa;

                //ARMAZENA O PROXIMO VALOR
                aux->proximo = p->proximo;

                //OPONTA PARA A NOVA PESSOA
                p->proximo = novaPessoa;

                //FAZ COM QUE O NOVO VALOR APONTE PARA O PROXIMO
                novaPessoa->proximo = aux->proximo;

                //LIBERA O AUX
                free(aux);
            }

        p = p->proximo;

        cont++;

    }

}

void removeInicioEncadeada(pessoa *&ponteiroEncadeada){

    //SER SÓ ESSISTIR UMA PESSOA NA LISTA
    if(ponteiroEncadeada->proximo == NULL){
        pessoa *novaPessoa = new pessoa;
        novaPessoa->nome = "";
        novaPessoa->rg = 0;
        novaPessoa->proximo = NULL;

        ponteiroEncadeada = novaPessoa;
    }else{
        //FAZ O PONTEIRO PRINCIPAL APONTAR PARA O PROXIMO
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
}

void removeFimEncadeada(pessoa *&ponteiroEncadeada){
    //AUXILIARES
    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    //PONTEIRO CURSO AUXILIAR
    p = ponteiroEncadeada;

    while(p->proximo != NULL){
        aux = p;
        p = p->proximo;
    }
    aux->proximo = NULL;
}

void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *p = ponteiroEncadeada;

    //CONTADOR DE POSIÇÃO
    int cont = 0;

    while(cont <= posicao){


        //QUANDO CHEGA UM ANTES DA POSIÇÃO DESEJADA
        if(cont == posicao - 1){

            //AUXILIAR
            pessoa *aux = new pessoa;

            //AUXILIAR RECEBE O QUE VAI SER ELIMINADO
            aux = p->proximo;

            //FAZ COM QUE O PROXIMO PULE UM ELEMENTO
            p->proximo = aux->proximo;

            free(aux);
        }

        //PEGA O CURSO PARA O PROXIMO
        p = p->proximo;

        //REGISTRAR UMA MOVIMENTAÇÃO
        cont++;
    }

}

string retornaNomeEncadeado(pessoa *&ponteiroEncadeada, int rg){

    //NOME A RETORNA
    string nome = "Não encontrado";

    //PONTEIRO CURSO AUXILIAR
    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        //RECE O NOME DO RG
        if(p->rg == rg){

            //RECEBE O NOME DO
            nome = p->nome;

            return nome;

        }
        p = p->proximo;
    }

    return nome;
}
int main(){
    setlocale(LC_ALL, "");

    //variavel
    int funcaoDesejada = 1;

    //CRIA O INÍCIO DA LISTA ENCADEADO
    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    //CRIA O PRIMEIRO VALOR
    /*pessoa *novaPrimeiraPessoa = new pessoa;
    novaPrimeiraPessoa->nome = "João";
    novaPrimeiraPessoa->rg = 123;
    novaPrimeiraPessoa->proximo = NULL;

    //TRANSFORMA O PRIMEIRO PONTEIRO DA LISTA NUM NOVO VALOR
    ponteiroEncadeada = novaPrimeiraPessoa;

    //CRIANDO O SEGUNDO VALOR
    pessoa *novaSegundoPessoa = new pessoa;
    novaSegundoPessoa->nome = "Victor";
    novaSegundoPessoa->rg = 321;
    novaSegundoPessoa->proximo = NULL;

    //ENCADEAMENTO DE VALORES
    novaPrimeiraPessoa->proximo = novaSegundoPessoa;*/

    //mortrando o menu
    while(funcaoDesejada < 9 && funcaoDesejada > 0){

        cout << "Operações \n";
        cout << "1 - Inserção de um node no início da lista \n";
        cout << "2 - Inserção de um node no fim da lista \n";
        cout << "3 - Inserção de um node na posição N \n";
        cout << "4 - Retirar um node do início da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posição N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";
        cout << "Tamanho atual:" << retornaTamanho(ponteiroEncadeada) << "\n";

        //IMPRIME LISTA VAZIA
        if(retornaTamanho(ponteiroEncadeada) == 0){
            cout << "Lista vazia\n";
        }else{
            imprimeEncadeada(ponteiroEncadeada);
        }

        //faz a leitura
        cin >> funcaoDesejada;

        limpaTela();

        //VARIÁVEL
        string nome;
        int rg, posicao;

        //faz a opreção desejada
        switch(funcaoDesejada){
            case 1:
                cout << "1 - Inserção de um node no início da lista";

                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                break;
            case 2:
                cout << "2 - Inserção de um node no fim da lista\n";

                cout << "Digite Nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(retornaTamanho(ponteiroEncadeada) == 0){
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }
                break;
            case 3:
                cout << "3 - Inserção de um node na posição N\n";

                cout << "Digite a Posição: ";
                cin >> posicao;
                cout << "Digite o Nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(posicao == 0){
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                    adcPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);
                }

                break;
            case 4:
                cout << "4 - Retirar um node do início da lista";

                removeInicioEncadeada(ponteiroEncadeada);
                break;
            case 5:
                cout << "5 - Retirar um node no fim da lista";

                if(retornaTamanho(ponteiroEncadeada) == 1){
                    removeInicioEncadeada(ponteiroEncadeada);
                }else{
                    removeFimEncadeada(ponteiroEncadeada);
                }
                break;
            case 6:
                cout << "6 - Retirar um node na posição N\n";

                cout << "Digite posição: ";
                cin >> posicao;

                if(posicao == 0){

                    removeInicioEncadeada(ponteiroEncadeada);

                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){

                    removeFimEncadeada(ponteiroEncadeada);

                }else{

                    removePosicaoEncadeada(ponteiroEncadeada, posicao);
                }
                break;
            case 7:
                cout << "7 - Procurar um node com o campo RG\n";

                //RG DIGITADO PARA A PROCURA NA LISTA
                cout << "Digite o RG: ";
                cin >> rg;

                cout << "O nome do rg: " << rg << " é: " << retornaNomeEncadeado(ponteiroEncadeada, rg) << "\n";
                break;
            case 8:
                break;
            case 9:
                break;
        }
    }

    return 0;
}
