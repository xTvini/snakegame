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
    printf("->caso digite um numero diferente dos acima a dificuldade será definida como média<-");
    scanf("%d", &difficuldade);
    return difficuldade;
}
int instrucoes(){
    screenSetColor(WHITE, WHITE);
    int voltar = 0;
    printf("Instruções de como jogar\n");
    printf("1-Use as teclas w,a,s,d para mover a cobra\n");
    printf("2-Coma a comida para crescer\n");
    printf("3-Não bata nas paredes\n");
    printf("4-Nosso jogo não é inédito porém existe uma funcionalidade diferente\n");
    printf("a cobra sempre que come uma fruta inverte de lado movendo-se ao oposto do que estava quando comeu a fruta\n");
    printf("5-Para sair do jogo aperte esc\n");
    printf("6-Boa sorte\n");
    printf("->Para voltar aperte 1<-\n");
    scanf("%d", &voltar);
    return voltar;
}