#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <iostream>
#include <new>

using namespace std;

void limpaTela(){
    system("CLS");
}

void menuInicial(){
    //Opp��o escolhida pelo usu�rio
    int opcao = 0;

    //Enquanto o jogador n�o digita um numero valido
    while (opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem Vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair\n";
        cout << "Escolha uma op��o � tecle ENTER: ";
        cin >> opcao;

        //Faz uma a��o de acordo com a op��o digitada
        switch (opcao){
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado";
                break;
            case 2:
                //Infor��es sobre o jogo
                cout << "Informa��es do jogo";
                break;
            case 3:
                cout << "At� mais!";
                break;
        }
    }

}

int main(){
    setlocale(LC_ALL, "");

    menuInicial();

    return 0;
}
