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
    //Oppção escolhida pelo usuário
    int opcao = 0;

    //Enquanto o jogador não digita um numero valido
    while (opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem Vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair\n";
        cout << "Escolha uma opção é tecle ENTER: ";
        cin >> opcao;

        //Faz uma ação de acordo com a opção digitada
        switch (opcao){
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado";
                break;
            case 2:
                //Inforções sobre o jogo
                cout << "Informações do jogo";
                break;
            case 3:
                cout << "Até mais!";
                break;
        }
    }

}

int main(){
    setlocale(LC_ALL, "");

    menuInicial();

    return 0;
}
