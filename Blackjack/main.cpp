#include "cards.h"
#include "gameplay.h"
#include "start_menu.h"

using namespace std;

int main()
{
    cout << "Blackjack" << endl;
    Menu MainMenu(9);
    Menu PostGameMenu(3);

    do
    {
        int selected = MainMenu.selection();
        int numberOfPlayers = 1;
        if (selected != 1)
            numberOfPlayers = selected - 1;
        cout << numberOfPlayers << " players" << endl;
        if (selected == 1)
        {
            vector<string> names;
            for (int i = 0; i < numberOfPlayers; ++i)
            {
                string name;
                getline(cin, name);
                names.push_back(name);
            }

            selected = 0;
            while (selected == 0)
            {
                Game game(names);
                game.Play();

                system("cls");
                selected = PostGameMenu.selection();
                if (selected == 1)
                    selected = 0;
                else if (selected == 3)
                    exit(0);
            }
        }
        else if (selected == 9)
            exit(0);
    } while(true);
}