#include "Menu.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

Menu::Menu(std::vector<std::string>& menuList)
{
    unsigned int i = 0;
    for (auto& it : menuList)
        options.insert(make_pair(i++, it));
    pointer = options.begin();
}

Menu::~Menu() { options.clear(); }

int Menu::selection(const std::string& message)
{
    char inputKey;
    do
    {
        system("cls");
        std::cout << message << std::endl << std::endl;
        for (auto it = options.begin(); it != options.end(); ++it)
            std::cout << (it == pointer ? "* " : "") << it->second << std::endl;

        inputKey = static_cast<char>(_getch());

        switch (inputKey)
        {
        case KEY_UP:
            if (pointer != options.begin()) --pointer;
            break;
        case KEY_DOWN:
            if (pointer != prev(options.end())) ++pointer;
            break;
        default:;
        }
    } while (inputKey != KEY_ENTER);
    
    return pointer->first;
}