#include "paineis.h"
#include "screen.h"
#include <stdio.h> // inclua os cabeçalhos necessários aqui

int painel_de_escolha_inicio() {
    int escolha = 0;
    screenSetColor(WHITE, WHITE);
    printf("Escolha o modo de jogo:\n");
    printf("1 - Iniciar jogo\n");
    printf("2 - Ver os top 10 recordes\n");
    printf("3 - Instruções de como jogar\n");
    printf("4 - Sair\n");
    scanf("%d", &escolha);
    return escolha;
}
int escolha_dificuldade(){
    int difficuldade=0;
    screenSetColor(WHITE, WHITE);
    printf("escolha a dificuldade\n");
    printf("1-facil\n");
    printf("2-medio\n");
    printf("3-dificil\n");
    scanf("%d", &difficuldade);
    return difficuldade;
}