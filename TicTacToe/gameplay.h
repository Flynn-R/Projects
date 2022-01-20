#pragma once

#include "consts.h"

// Вывод игрового поля на экран
void __fastcall drawField(Field* field, unsigned short turn);

// Ход компьютера
GameState vi(Game* ticTacToe);

// Ход пользователя
GameState player(Game* ticTacToe);

// Проверка выигрыша
GameState check(Field* field, GameModes mode, Marks player);

// Алгоритм виртуального интеллекта
GameState preventWin(Game* ticTacToe);