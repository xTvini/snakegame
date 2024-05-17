#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "paineis.h"
#define Max 100000
int pontuação;
int snakeX[Max];
int snakeY[Max];
int snakeLength = 5;
int snakeDirection = 0; // 0: cima, 1: direita, 2: baixo, 3: esquerda
int foodX, foodY; // Variáveis globais para a posição da comida
int gameRunning = 1; // Variável global para controlar o estado do jogo
float difficulty = 0;

void initializeGame() {
    screenInit(0);
    keyboardInit();
    timerInit(100/difficulty); // Ajusta a velocidade do jogo com base na dificuldade

    // Inicializa a cobrinha no meio da tela
    snakeX[0] = MAXX / 2;
    snakeY[0] = MAXY / 2;

    // Posiciona a comida aleatoriamente na tela
    foodX = rand() % (MAXX - 3) + 1;
    foodY = rand() % (MAXY - 3) + 1;
    if(foodX==MAXX||foodY==MAXY||foodX==MINX||foodY==MINY){
        foodX = rand() % (MAXX - 3) + 1;
        foodY = rand() % (MAXY - 3) + 1;
    }
    // Define a direção inicial da cobrinha
    snakeDirection = 0;
}

void drawMap() {
    // Desenha as bordas do mapa
    //parede de cima e de baixo
    screenSetColor(BLUE,BLUE);
    for (int i = MINX; i <= MAXX; i++) {
        screenGotoxy(i, MINY);
        printf(" ");
        screenGotoxy(i, MAXY);
        printf(" ");
    }
    // parede dos lados
    for (int i = MINY; i <= MAXY; i++) {
        screenGotoxy(MINX, i);
        printf(" ");
        screenGotoxy(MAXX, i);
        printf(" ");
    }
    printf("\n\t\t\t\tPontuação: %d", pontuação);
}

void drawSnake() {
    screenSetColor(GREEN, GREEN);
    for (int i = 0; i < snakeLength; i++) {
        screenGotoxy(snakeX[i], snakeY[i]);
        if(snakeDirection == 0){
            printf("▲");
        }
        else if(snakeDirection == 1){
            printf("►");
        }
        else if(snakeDirection == 2){
            printf("▼");
        }
        else if(snakeDirection == 3){
            printf("◄");
        }
    }
}

void drawFood() {
    screenSetColor(RED, BLACK);
    screenGotoxy(foodX, foodY);
    printf("δ");
}

void moveSnake() {
    // Move a cabeça da cobrinha para a próxima posição
    int nextX = snakeX[0], nextY = snakeY[0];
    switch (snakeDirection) {
        case 0: nextY--; break;
        case 1: nextX++; break;
        case 2: nextY++; break;
        case 3: nextX--; break;
    }
    //essa função garante que quando a cobra morrer o jogo volte ao painel de escolha
    // e so permite que o jogo encerre se o jogador comandar
    void manter_loop(){
    screenClear();
    initializeGame();
    }
    // Verifica se a cobrinha colidiu com a parede ou com ela mesma
    if (nextX <= MINX || nextX >= MAXX || nextY <= MINY || nextY >= MAXY) {
        gameRunning = 0; // O jogo termina se a cobrinha colidir com a parede
        manter_loop();
        return;
    }

    // Verifica se a cobrinha comeu a comida
    if (nextX == foodX && nextY == foodY) {
        //caso ela tenha comido a fruta ele vai gerar uma nova fruta randomicamente no mapa
        //e vai garantir que a fruta é gerada fora da parede
        pontuação++;
        foodX = rand() % (MAXX -3)+1;
        foodY = rand() % (MAXY -3)+1;
        if(foodX == MAXX || foodX == MINX||foodY == MAXY||foodY == MINY){
            foodX = rand() % (MAXX -3)+1 ;
            foodY = rand() % (MAXY -3)+1;    
        }
        // Inverte a direção da cobrinha
        //implementação nova!!
        if (snakeDirection == 0 || snakeDirection == 2) {
        snakeDirection = (snakeDirection + 2) % 4;

    } else if (snakeDirection == 1 || snakeDirection == 3) {
        snakeDirection = (snakeDirection - 2) % 4;//aqui ele vai substituir a direção pela nova direção
        //a o calculo é por exemplo 1 - 2 = -1 % 4 que vai dar igual a 3 
                                            // |-> o %4 so vai occorrer caso a direção seja diferente
                                            //     somando assim o -1 ao 4 fazendo virar a posição 3
        if (snakeDirection < 0){
        /*este if ele corrige o erro da movimentação 
            se negativa (o qual não acontece po causa o %4)*/
        snakeDirection += 4;
    } 
    }
    snakeLength++;
    } else {
        // Move o corpo da cobrinha para frente
        for (int i = snakeLength - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }
    }

    // Atualiza a posição da cabeça da cobrinha
    snakeX[0] = nextX;
    snakeY[0] = nextY;
}

void handleInput(int key) {
    switch (key) {
        case 'w': if (snakeDirection != 2) snakeDirection = 0; break;//cima
        case 'd': if (snakeDirection != 3) snakeDirection = 1; break;//direita
        case 's': if (snakeDirection != 0) snakeDirection = 2; break;//baixo
        case 'a': if (snakeDirection != 1) snakeDirection = 3; break;//esquerda
        case 27: gameRunning = 0; break; // Tecla Esc para sair do jogo
    }
}

int main() {
    screenInit(0);
    keyboardInit();
    timerInit(100 * difficulty); // Velocidade do jogo
    int escolha = painel_de_escolha_inicio();
    while (1) { // Loop para manter o jogo em execução até que o jogador escolha sair
        if (escolha == 1) {
            screenInit(0);
            /***************************************************************************/
            int difficuldade = escolha_dificuldade();
            if (difficuldade == 1) {
                difficulty = 0.5;
            }
             else if (difficuldade == 2) {
                difficulty = 1;
            }
             else if (difficuldade == 3) {
                difficulty = 2;
            }else{
                difficulty = 1;
            }
            /***************************************************************************/
            initializeGame(); // Inicializa o jogo
            gameRunning = 1; // Define o estado do jogo como em execução

            while (gameRunning) { // Loop para manter o jogo em execução até que a cobrinha morra
                if (keyhit()) {
                    int key = readch();
                    handleInput(key);
                }

                moveSnake();
                screenClear();
                drawMap(); // Desenha o mapa
                drawSnake();
                drawFood();
                screenUpdate();
                usleep(100000 / difficulty); // Aguarda 100ms antes de atualizar o próximo quadro
            }
            // Não é necessário destruir os componentes aqui
        }
        /***************************************************************************/
         else if (escolha == 2) {
            // Implementar a função de ver os top 10 recordes
        } 
        /***************************************************************************/
        else if (escolha == 3) {
            screenInit(0);
            int voltar=instrucoes();
            do{
                if (voltar==1){
                screenInit(0);
                escolha = painel_de_escolha_inicio();
                break;
            }else{
                printf("escolha inválida aperte 1 pra voltar");
                break;
            }
            }while(voltar!=1);
        }
        /***************************************************************************/
        else if (escolha == 4) {
            break;
        }
        screenClear();
        screenInit(0);
        escolha = painel_de_escolha_inicio();
        break;
    }
    // Se o jogador escolheu sair, encerra o programa
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
} 