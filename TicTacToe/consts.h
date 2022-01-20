#pragma once

#include <iostream>
#include <conio.h>
#include <chrono>
#include <random>
#include <cstdarg>

using namespace std;

// Символы клавиш стрелок
#define LEFT 75
#define UP 72
#define RIGHT 77
#define DOWN 80

// Символ клавиши Enter
#define ENTER 13

enum Marks : char
{
    CROSS = 'X', CIRCLE = 'O', EMPTY = '_', SELECTED = '*'
};

enum GameModes
{
    CLASSIC = 3, FOUR_IN_ROW = 4, FIVE_IN_ROW = 5
};

enum GameState
{
    IN_PROGRESS, WIN, DRAW
};

struct Field
{
    Marks** cells;
    unsigned short size : 3;
};

struct Game
{
    unsigned short turn;
    Marks player1, player2;
    Field field;
    GameModes mode;
    GameState gameState;
};

// Селекция в меню
unsigned short menu(size_t count, ...);
void __fastcall selection(size_t count, unsigned short select, va_list* str);

// Генератор случайных чисел
int32_t __fastcall getRandomNum(int32_t min, int32_t max);