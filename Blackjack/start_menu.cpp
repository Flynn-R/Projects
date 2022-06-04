#include "start_menu.h"
#define UP 72
#define DOWN 80
#define ENTER 13

Menu::Menu(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (n == 9)
            options.insert(make_pair(i, MainMenuOptions[i - 1]));
        else
            options.insert(make_pair(i, PostGameOptions[i - 1]));
    }
}

Menu::~Menu()
{
    options.clear();
}

int Menu::selection()
{
    auto current = options.begin();
    char key;
    do
    {
        for (auto it = current; it != options.end(); ++it)
            cout << (it == current ? "* " : "") << it->second << endl;
        key = static_cast<char>(_getch());

        switch (key)
        {
            case UP:
                if (current != options.begin())
                    --current;
                break;
            case DOWN:
                if (current != prev(options.end()))
                    ++current;
                break;
            default:;
        }
    } while (key != ENTER);

    return current->first;
}