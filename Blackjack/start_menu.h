#pragma once
#include <iostream>
#include <conio.h>
#include <map>
#include <vector>

using namespace std;

class Menu
{
private:
    const vector<string> MainMenuOptions
    {
        "Begin", "1 player", "2 players", "3 players", "4 players",
        "5 players", "6 players", "7 players", "Exit"
    };
    const vector<string> PostGameOptions
    {
        "Replay", "Change number of players", "Exit"
    };
    map<int, string> options;
public:
    explicit Menu(int);
    int selection(const int&);
    ~Menu();
};