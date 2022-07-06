#include "govno_menu.h"
#include <conio.h>
#define UP 72
#define DOWN 80
#define ENTER 13

MainMenu::MainMenu()
{
    for (unsigned short i = 1; i < mainMenuList.size(); ++i)
        options.insert(make_pair(i, mainMenuList[i]));
}

GenderMenu::GenderMenu()
{
    for (unsigned short i = 1; i < genderList.size(); ++i)
        options.insert(make_pair(i, genderList[i]));
}

MainMenu::~MainMenu() { options.clear(); }

unsigned short MainMenu::selection()
{
    auto pointer = options.begin();
    char inputKey;
    do
    {
        system("cls");

        for (auto it = options.begin(); it != options.end(); ++it)
            cout << (it == pointer ? "* " : "") << it->second << endl;
        inputKey = static_cast<char>(_getch());

        switch (inputKey)
        {
        case UP:
            if (pointer != options.begin())
                --pointer;
            break;
        case DOWN:
            if (pointer != options.end())
                ++pointer;
            break;
        default:;
        }
    } while (inputKey != ENTER);

    return pointer->first;
}