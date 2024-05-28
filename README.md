# SnakeGame - Projeto de PIF do 2º Período

- [Descrição](#descrição)
- [Instalação](#instalação)
- [Controles](#controles)
- [Funcionalidades Extras](#funcionalidades-extras)
- [Créditos](#créditos)

## Descrição
Um clássico jogo da cobrinha desenvolvido em C com funcionalidades extras. O objetivo é guiar a cobra pelo tabuleiro para comer frutas que aparecem aleatoriamente. Cada fruta consumida faz a cobra crescer, aumentando a dificuldade do jogo. O jogo termina se a cobra colidir com as paredes. Você pode competir com seus amigos para ver quem consegue a maior pontuação! Cada vez que você joga, sua pontuação é registrada em um ranking. Teste seus reflexos, desafie seus amigos e veja quanto tempo você consegue sobreviver enquanto a cobra continua a crescer! 

## Instalação
### Pré-requisitos
- [Compilador C](https://gcc.gnu.org/)
- [Biblioteca ncurses](https://invisible-island.net/ncurses/) (necessária para manipulação de tela no terminal)

### Compilação
1. Clone este repositório:
    ```sh
    git clone https://github.com/xTvini/snakegame.git
    ```
2. Navegue até o diretório do projeto:
    ```sh
    cd snakegame
    cd snake
    ```
3. Compile o código:
    ```sh
    gcc -I./include src/*.c -o main
    ```
    
### Execução
Para jogar, execute o arquivo compilado:
```sh
./main
```

## Controles
- **Tecla W**: Mover para cima
- **Tecla S**: Mover para baixo
- **Tecla A**: Mover para a esquerda
- **Tecla D**: Mover para a direita
- **Tecla ESC**: Sair do jogo

## Funcionalidades Extras
- **Níveis de dificuldade**: Escolha entre fácil, médio e difícil, ajustando a velocidade da cobra.
- **Inversão da cobra**: Sempre que a cobra pega uma fruta, ela inverte, trocando a cabeça pelo rabo e o rabo pela cabeça, e a direção do movimento também se inverte. Por exemplo, se a cobra pegar uma fruta enquanto está se movendo para cima, ela começará a se mover para baixo após a inversão.

## Créditos
- **Kauane Melo** - [KauaneMelo](https://github.com/KauaneMelo)
- **Maria Fernanda Ordonho** - [nandaord](https://github.com/nandaord)
- **Vinícius Diniz** - [xTvini](https://github.com/xTvini)
