#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 20
#define COL 20

#define PLAYER1 1
#define PLAYER2 2

#define NEXT 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW        3

void Menu();

void Game();
