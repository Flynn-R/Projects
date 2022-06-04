#include "cards.h"
#include "gameplay.h"
#include "start_menu.h"

using namespace std;

int main()
{
    Menu MainMenu(9);
    Menu PostGameMenu(3);
    int numberOfPlayers = 1;

    do
    {
        int selected = MainMenu.selection(numberOfPlayers);
        if (selected != 1)
            numberOfPlayers = selected - 1;
        if (selected == 1)
        {
            vector<string> names;
            for (int i = 0; i < numberOfPlayers; ++i)
            {
                system("cls");
                string name;
                cout << "Enter player " << i + 1 << "'s name : ";
                getline(cin, name);
                names.push_back(name);
            }

            selected = 0;
            while (selected == 0)
            {
                Game game(names);
                game.Play();

                system("cls");
                selected = PostGameMenu.selection(numberOfPlayers);
                if (selected == 1)
                    selected = 0;
                else if (selected == 3)
                    exit(0);
            }
        }
        else if (selected == 9)
            exit(0);
    } while (true);
}