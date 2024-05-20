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
    printf("aperte qualquer botão pra sair\n");
    printf("->CLIQUE EM UM DESSES NUMEROS E DÊ ENTER<-");
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
    printf("Instruções de como jogar\n");
    printf("1-Use as teclas w,a,s,d para mover a cobra\n");
    printf("2-Coma a comida para crescer\n");
    printf("3-Não bata nas paredes\n");
    printf("4-Nosso jogo não é inédito porém existe uma funcionalidade diferente\n");
    printf("a cobra sempre que come uma fruta inverte de lado movendo-se ao oposto do que estava quando comeu a fruta\n");
    printf("5-Para sair do jogo aperte esc\n");
    printf("6-Boa sorte\n");
}

void escrever(char *nome,int *pontuação){
    FILE *recordes;
    recordes=fopen("recordes.txt","a");
        if(recordes==NULL){
            printf("erro ao abrir o arquivo");
        }
        fprintf(recordes,"%s %d\n",nome,*pontuação);
        fclose(recordes);
        return;
}
void ver() {
    FILE *recordes;
    recordes = fopen("recordes.txt", "r");
    if (recordes == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    char c;
    while ((c = fgetc(recordes)) != EOF) {
        printf("%c", c);
    }
    fclose(recordes);
}

int drawMap(int *pontuacao) {
    screenSetColor(BLUE, BLUE);
    for (int i = MINX; i <= MAXX; i++) {
        screenGotoxy(i, MINY);
        printf(" ");
        screenGotoxy(i, MAXY);
        printf(" ");
    }
    for (int i = MINY; i <= MAXY; i++) {
        screenGotoxy(MINX, i);
        printf(" ");
        screenGotoxy(MAXX, i);
        printf(" ");
    }
    int middleX = (MINX + MAXX) / 2;
    int posY = MAXY + 1; 
    screenGotoxy(middleX - 6, posY);
    printf("Pontuação: %d", *pontuacao);
}

void PERDEU(){
    screenSetColor(BLUE, BLUE);
    for (int i = MINX; i <= MAXX; i++) {
        screenGotoxy(i, MINY);
        printf(" ");
        screenGotoxy(i, MAXY);
        printf(" ");
    }
    for (int i = MINY; i <= MAXY; i++) {
        screenGotoxy(MINX, i);
        printf(" ");
        screenGotoxy(MAXX, i);
        printf(" ");
    }
    screenSetColor(WHITE, BLACK);
    int middleX = (MINX + MAXX) / 2;
    int middleY = (MINY + MAXY) / 2;
     screenGotoxy(middleX - 10, middleY - 1); // Ajusta -10 para centralizar o texto "======================"
    printf("======================");
    screenGotoxy(middleX - 4, middleY); // Ajusta -4 para centralizar o texto "GAME OVER"
    printf("GAME OVER");
    screenGotoxy(middleX - 10, middleY + 1); // Ajusta -10 para centralizar o texto "======================"
    printf("======================");
    getchar();
    getchar();
}

void GANHOU(){
    screenSetColor(BLUE, BLUE);
    for (int i = MINX; i <= MAXX; i++) {
        screenGotoxy(i, MINY);
        printf(" ");
        screenGotoxy(i, MAXY);
        printf(" ");
    }
    for (int i = MINY; i <= MAXY; i++) {
        screenGotoxy(MINX, i);
        printf(" ");
        screenGotoxy(MAXX, i);
        printf(" ");
    }
    screenSetColor(WHITE, BLACK);
    int middleX = (MINX + MAXX) / 2;
    int middleY = (MINY + MAXY) / 2;
     screenGotoxy(middleX - 10, middleY - 1); // Ajusta -10 para centralizar o texto "======================"
    printf("======================");
    screenGotoxy(middleX - 4, middleY); // Ajusta -4 para centralizar o texto "GAME OVER"
    printf("GAME OVER");
    screenGotoxy(middleX - 10, middleY + 1); // Ajusta -10 para centralizar o texto "======================"
    printf("======================");
    getchar();
    getchar();
}
