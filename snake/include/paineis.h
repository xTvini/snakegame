/**
 * paineis.h
 * Created on May, 10th 2024
 * Author: Vinicius Diniz 
*/
#ifndef PAINEIS_H
#define PAINEIS_H

#include <stdio.h> 
#include <unistd.h>


int painel_de_escolha_inicio();

int escolha_dificuldade();

void ver();

int instrucoes();

void PERDEU();

void GANHOU();

int drawMap();
#endif