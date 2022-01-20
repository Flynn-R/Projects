#pragma once

#include "consts.h"

// Главное меню
void mainMenu();

// Справка
void inline help();

// Настройка игры
void settings(bool computer);

// Выбор метки
void playersInit(Game* ticTacToe);

// Выбор режима игры
void gameMode(Game* ticTacToe);

// Запуск игры
void gameplay(Game* ticTacToe, bool computer);