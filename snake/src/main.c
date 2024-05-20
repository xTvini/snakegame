#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "paineis.h"

#define Max 1920


int pontuação;
int snakeX[Max];
int snakeY[Max];
int snakeLength = 5;
int snakeDirection = 0; // 0: cima, 1: direita, 2: baixo, 3: esquerda
int foodX, foodY; 
int gameRunning = 1; // Variável global para controlar o estado do jogo
float difficulty = 0;
char nome[100];

void initializeGame() {
    screenInit(0);
    keyboardInit();
    timerInit(100 / difficulty); // Ajusta a velocidade do jogo com base na dificuldade

    // Inicializa a cobrinha no meio da tela
    snakeX[0] = MAXX / 2;
    snakeY[0] = MAXY / 2;

    // Posiciona a comida aleatoriamente na tela
    foodX = rand() % (MAXX - 3) + 1;
    foodY = rand() % (MAXY - 3) + 1;
    if (foodX == MAXX || foodY == MAXY || foodX == MINX || foodY == MINY) {
        foodX = rand() % (MAXX - 3) + 1;
        foodY = rand() % (MAXY - 3) + 1;
    }

    // Define a direção inicial da cobrinha
    snakeDirection = 0;
}
void drawSnake() {
    screenSetColor(BLACK, GREEN);
    for (int i = 0; i < snakeLength; i++) {
        screenGotoxy(snakeX[i], snakeY[i]);
        switch (snakeDirection) {
            case 0: printf("▲"); break;
            case 1: printf("►"); break;
            case 2: printf("▼"); break;
            case 3: printf("◄"); break;
        }
    }
}

void drawFood() {
    screenSetColor(RED, BLACK);
    screenGotoxy(foodX, foodY);
    printf("δ");
}

void moveSnake() {
    int nextX = snakeX[0], nextY = snakeY[0];
    switch (snakeDirection) {
        case 0: nextY--; break;
        case 1: nextX++; break;
        case 2: nextY++; break;
        case 3: nextX--; break;
    }

    if (nextX <= MINX || nextX >= MAXX || nextY <= MINY-1 || nextY >= MAXY-1) {
        gameRunning = 0;
        PERDEU();
        escrever(nome, &pontuação);
        screenClear();
    }
    if (snakeLength == MAXX * MAXY) {
        screenClear();
        GANHOU();
        gameRunning = 0;
        escrever(nome, &pontuação);
        screenClear();
    }

    if (nextX == foodX && nextY == foodY) {
        pontuação++;
        foodX = rand() % (MAXX - 3) + 1;
        foodY = rand() % (MAXY - 3) + 1;
        if (foodX == MAXX || foodX == MINX || foodY == MAXY || foodY == MINY) {
            foodX = rand() % (MAXX - 3) + 1;
            foodY = rand() % (MAXY - 3) + 1;
        }
        if (snakeDirection == 0 || snakeDirection == 2) {
            snakeDirection = (snakeDirection + 2) % 4;
        } else if (snakeDirection == 1 || snakeDirection == 3) {
            snakeDirection = (snakeDirection - 2) % 4;
            if (snakeDirection < 0) {
                snakeDirection += 4;
            }
        }
        snakeLength++;
    } else {
        for (int i = snakeLength - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }
    }

    snakeX[0] = nextX;
    snakeY[0] = nextY;
}

void handleInput(int key) {
    switch (key) {
        case 'w': if (snakeDirection != 2) snakeDirection = 0; break;
        case 'd': if (snakeDirection != 3) snakeDirection = 1; break;
        case 's': if (snakeDirection != 0) snakeDirection = 2; break;
        case 'a': if (snakeDirection != 1) snakeDirection = 3; break;
        case 27: gameRunning = 0; break;
    }
}

int main() {
    screenInit(0);
    keyboardInit();
    timerInit(100 * difficulty);

    while (1) {
        int escolha = painel_de_escolha_inicio();

        if (escolha == 1) {
            screenClear();
            int difficuldade = escolha_dificuldade();
            if(difficuldade==1){
                difficulty=0.5;
            }
            else if(difficuldade==2){
                difficulty=1;
            }
            else if(difficuldade==3){
                difficulty=2;
            }
            else{
                difficulty=1;
            }
            screenClear();
            printf("Digite seu nome\n");
            scanf("%s", nome);
            screenClear();
            initializeGame();
            gameRunning = 1;

            while (gameRunning) {
                if (keyhit()) {
                    int key = readch();
                    handleInput(key);
                }

                moveSnake();
                screenClear();
                drawMap(&pontuação);
                drawSnake();
                drawFood();
                screenUpdate();
                screenClear();
                usleep(100000 / difficulty);
            }
        } else if (escolha == 2) {
            screenClear();
            ver();
            printf("\nPressione qualquer tecla para voltar ao menu principal...");
            getchar();
            getchar();
            screenClear();
        } else if (escolha == 3) {
            screenClear();
            instrucoes();
            printf("\nPressione qualquer tecla para voltar ao menu principal...");
            getchar();
            getchar();
            screenClear();
        } else {
            break;
        }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
