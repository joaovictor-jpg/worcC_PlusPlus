#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <iostream>
#include <new>
#include <time.h>


using namespace std;

void limpaTela(){
    system("CLS");
}

void menuInicial();

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){

    int linha,coluna;                   //Auxiliares de navega��o

    //Popula o tabuleiro com �gua
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
                tabuleiro[linha][coluna] = 'A';
                mascara[linha][coluna] = '*';
        }
    }
}

void exibeMapa(){
    //Mapa indicador de colunas
    int cont;
    for(cont = 0; cont < 10; cont++){
        if(cont == 0){
            cout << "   ";
        }
        cout << cont << " ";
    }
    cout << "\n";

    for(cont = 0; cont < 10; cont++){
        if(cont == 0){
            cout << "   ";
        }
        cout << "|" << " ";
    }
    cout << "\n";
}

void exibirTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool exibeGabarito){

    char blue[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
    char red[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
    char normal[] = {0x1b, '[', '1', ';', '3', '9', 'm', 0};


    int linha,coluna;                   //Auxiliares de navega��o

    //Exibir o tabuleiro
    for(linha = 0; linha < 10; linha++){
        cout << linha << "-";
        for(coluna = 0; coluna < 10; coluna++){
            switch(mascara[linha][coluna]){
                case 'A':
                    cout << blue << " " << mascara[linha][coluna] << normal;
                    break;
                case 'p':
                    cout << red << " " << mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " << mascara[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }

    if(exibeGabarito == true){
        //Exibir o tabuleiro
        for(linha = 0; linha < 10; linha++){
            for(coluna = 0; coluna < 10; coluna++){
                cout << " " << tabuleiro[linha][coluna];
            }
            cout << "\n";
        }
    }
}

void posicionaBarco(char tabuleiro[10][10]){
    //Coloca 10 barcos no tabuleiro
    int quantidade = 10, cont, quantidadePosicionada = 0;
    int linhaAleatoria, colunaAleatoria;

    //Verifica se j� posicionou os barcos
    while(quantidadePosicionada < quantidade){

            linhaAleatoria = rand() % 10; //Gera n�mero aleatorio de 0 a 9
            colunaAleatoria = rand() % 10; //Gera n�mero aleatorio de 0 a 9

            if(tabuleiro[linhaAleatoria][colunaAleatoria] == 'A'){

                //Posiciona 10 barcos aleatorios no tabuleiro
                tabuleiro[linhaAleatoria][colunaAleatoria] = 'p';

                //Almenta contador de barcos posicionado
                quantidadePosicionada++;
            }
    }
}

void VerificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){

    //Verifica quan � apontua��o do jogador
        switch(tabuleiro[linhaJogada][colunaJogada]){
            case 'p':
                *pontos = *pontos + 10;
                *mensagem = "Voc� acertou um bote!(Inimigo abatido)";
                break;
            case 'A':
                *pontos = *pontos - 5;
                *mensagem = "Voc� acertou a �gua";
                break;
        }
}

void jogo(string nomeDoJogador){

    ///vari�vel gereal
    char tabuleiro[10][10], mascara[10][10];             //tabuleiro do jogo.
    int linhaJogada, colunaJogada;                       //Posi��o escolhida pelo jogador.
    int estadiDejogo = 1;                                //1 = jogo acontecendo 0 = fim de jogo.
    int pontos = 0;                                      //Responsavel pela pontua��o do jogador.
    int tentativas = 0, maximoDeTentativas = 5;          //Tentativas do jogador.
    int opcao = 0;                                       //Op��es de escolha do jogador
    string mensagem = "Estamos prontos para atirar!!";   //Mensagem de fedbeek para o jogador.


    //inicia o tabuleiro com �gua
    iniciaTabuleiro(tabuleiro, mascara);

    //Posiciona barcos aleatorios
    posicionaBarco(tabuleiro);

    while(tentativas < maximoDeTentativas){
        limpaTela();

        //Exibir o cordenada do mapa
        exibeMapa();

        //Exibir tabuleiro
        exibirTabuleiro(tabuleiro, mascara, false);

        cout << "\nPontua��o: " << pontos;
        cout << "\nSua tentativas: " << maximoDeTentativas - tentativas;
        cout << "\nSitua��o do tiro? " << mensagem;

        //Verifica��o de dados
        linhaJogada = -1;
        colunaJogada = -1;

        while((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)){

            cout << "\n" << nomeDoJogador << ", Digite uma linha: ";
            cin >> linhaJogada;
            cout << nomeDoJogador << ", Digite uma coluna: ";
            cin >> colunaJogada;
        }

            //Verifica o tiro
            VerificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

            //revela oque est� no tabuleiro
            mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

            tentativas++;
        }

    limpaTela();

    cout << "Fim de Jogo, o que deseja fazer?";
    cout << "\nOp��o 1 - Jogar novamente:";
    cout << "\nOp��o 2 - Ir para o menu:";
    cout << "\nOp��o 3 - Sair do jogo:\n";
    cin >> opcao;

    switch(opcao){
        case 1:
            jogo(nomeDoJogador);
            break;
        case 2:
            menuInicial();
            break;
    }
}

void menuInicial(){
    //Opp��o escolhida pelo usu�rio
    int opcao = 0;
    string nomeDoJogador;                                //Nome do Usu�rio.

    //Enquanto o jogador n�o digita um numero valido
    while (opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem Vindo ao Jogo de batalha naval";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair\n";
        cout << "Escolha uma op��o � tecle ENTER: ";
        cin >> opcao;

        //Faz uma a��o de acordo com a op��o digitada
        switch (opcao){
            case 1:
                cout << "Digite um login: ";
                cin >> nomeDoJogador;
                //Inicia o jogo
                jogo(nomeDoJogador);
                break;
            case 2:
                //Infor��es sobre o jogo
                limpaTela();
                cout << "Criado por Jo�o Victor dia 1 de abril de 2021";
                cout << "\nOp��o 1 - voltar ao Menu!!!";
                cout << "\nOp��o 2 - sair do jogo";
                cout << "\nEscolha uma op��o: ";
                cin >> opcao;
                switch(opcao){
                    case 1:
                        menuInicial();
                        break;
                }
                break;
            case 3:
                cout << "At� mais!";
                break;
        }
    }

}

int main(){
    setlocale(LC_ALL, "");

    //Para gerar um n�mro realmente aleatorio
    srand((unsigned)time(NULL));

    menuInicial();

    return 0;
}

