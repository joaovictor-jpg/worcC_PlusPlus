#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <new>
#include <locale.h>

using namespace std;

limpaTela(){
    system("CLS");
}

void menuInicial();

void iniciaTabuleiro(char tabuleiro[3][3]){

    //navega pelo tabuleiro e coloca -
    int linha, coluna;
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }

}

void exibeTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    cout << "\n";
    //Exiber tabuleiro com suas linhas e colunas
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
            cout << " ";
        }
        cout << "\n";
    }
}

//1 = X ganhador ou 2 = O ganhador
int confereTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    //confere linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //conferi colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //Diagonal Principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
            if(tabuleiro[0][0]== 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        //Diagonal invertida
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        return 0;
}

void exibeInstrucoes(){

    cout << "\nMapa com posições:";
    cout << "\n 7 8 9";
    cout << "\n 4 5 6";
    cout << "\n 1 2 3";
}

void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    ///Varoável Gweal
    char tabuleiro[3][3];                                                   //Tabuleiro do meu jogo
    string nomeDoJogadorAtual;                                              //Nome dos jogadores
    int linha, coluna;                                                      //Variável contadora
    int linhaJogada, colunaJogada, posicaoJogada;                           //posição em que o jogador posiciona sua marca
    int estadoDeJogo = 1;                                                   //0 = sem jogo, 1 = em jogo.
    int turnoDoJogador = 1;                                                 //1 = X, 2 = O
    int rodada = 0;                                                         //Quantas vezes os jogadores jogaram no total.
    int opcao;                                                              //Opçães de jogo
    bool posicionouJogada;                                                  //Verifica se o jogador colocou um marcado no tabuleiro


    //coloca os - no tabuleiro para indicar o vazio
    iniciaTabuleiro(tabuleiro);

    while(rodada < 9 && estadoDeJogo == 1){

        limpaTela();

        cout << "Rodadas: " << rodada;
        cout << "\nPontuação: " << nomeDoJogadorUm << " " << pontuacaoJogadorUm << " X " << pontuacaoJogadorDois << " " << nomeDoJogadorDois;

         //Exibir tabuleirona tela
        exibeTabuleiro(tabuleiro);

        //Exibe qual número corresponde a qual posição
        exibeInstrucoes();

         //atualiza o nome do jogador atual
         if (turnoDoJogador == 1){

            nomeDoJogadorAtual = nomeDoJogadorUm;
         }else {
             nomeDoJogadorAtual = nomeDoJogadorDois;
         }

         posicionouJogada = false;

         //Matriz de posição possivel
         int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

         while(posicionouJogada == false){

                //Le a jogada
                cout <<"\n" << nomeDoJogadorAtual << ", digite uma posição conforme o mapa: ";
                cin >> posicaoJogada;

                //Passa a linha e coluna de acordo com a matriz da posição exibida no mapa
                linhaJogada = posicoes[posicaoJogada - 1][0];
                colunaJogada = posicoes[posicaoJogada - 1][1];

                //verifica se a posição é vazia
                if(tabuleiro[linhaJogada][colunaJogada] == '-'){

                //colocou um marcado
                posicionouJogada = true;

                //Verifaca de quem é a vez para pasicionar o marcador.
                if (turnoDoJogador == 1){
                    tabuleiro[linhaJogada][colunaJogada] = 'X';
                    turnoDoJogador = 2;
                }else {
                    tabuleiro [linhaJogada][colunaJogada] = 'O';
                    turnoDoJogador = 1;
                }
            }
        }

        //confere se o jogo acabou
        if(confereTabuleiro(tabuleiro) == 1){
            cout << "Jogador " << nomeDoJogadorAtual << " venceu!!";
            pontuacaoJogadorUm++;
            estadoDeJogo = 0;
        }else if(confereTabuleiro(tabuleiro) == 2){
            cout << "Jogador " << nomeDoJogadorAtual << " venceu!!";
            pontuacaoJogadorDois++;
            estadoDeJogo = 0;
        }

        //Aumenta uma rodada
        rodada++;
    }

    //Exibir tabuleirona tela com a vitoria
    exibeTabuleiro(tabuleiro);
    cout << "Fim de jogo.";
    cout << "\nQual ação deseja faze? ";
    cout << "\n1 - continuar jogando";
    cout << "\n2 - Menu";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opção: ";
    cin >> opcao;
    switch(opcao){
        case 1:
            jogo(nomeDoJogadorUm, nomeDoJogadorDois, pontuacaoJogadorUm, pontuacaoJogadorDois);
            break;
        case 2:
            menuInicial();
            break;
    }

}

void menuInicial(){
    //opção escolhida pelo usuário
    int opcao = 0;

    //Nomes dos jogadores
    string nomeDoJogadorUm, nomeDoJogadorDois;


    //enquanto o jogador não digita uma opção valida ele não avança
    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo!!!";
        cout << "\n1 - Jogar:";
        cout << "\n2 - Sobre o jogo:";
        cout << "\n3 - Sair do jogo:";
        cout << "\nEscolha uma opção e tecle ENTER: ";
        cin >> opcao;

        //Faz uma ação escolhida
        switch(opcao){
            case 1:
                //Iniciar o jogo
                cout << "Jogo Iniciado\n";
                cout << "Digite o nome do jogador 1: ";
                cin >> nomeDoJogadorUm;
                cout << "Digite o nome do jogador 2: ";
                cin >> nomeDoJogadorDois;
                jogo(nomeDoJogadorUm, nomeDoJogadorDois, 0, 0);
                break;
            case 2:
                limpaTela();
                //Curiosidades do jogo
                cout << "O jogo foi desenvolvido por João Victo dia 02/04/2021";

                 cout << "\nQual ação deseja faze? ";
                 cout << "\n1 - Voltar para o menu";
                 cout << "\n2 - Sair do jogo";
                 cout << "\nEscolha uma opção: ";
                 cin >> opcao;
                 switch(opcao){
                     case 1:
                         menuInicial();
                         break;
                    case 2:
                        cout << "\nAté mais";
                        break;
                 }
            case 3:
                //Fim do jogo
                cout << "Até mais!!";
                break;
        }
    }

}

int main(){
    setlocale(LC_ALL, "");

    menuInicial();

    return 0;
}
