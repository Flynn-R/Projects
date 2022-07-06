#include "govno_entities.h"
#include "govno_menu.h"

int main()
{
    Population<Human> humanPopulation;
    Population<Cat> catPopulation;

    MainMenu mainMenu;
    unsigned short pointer;
    do
    {
        pointer = mainMenu.selection();
        
        if (pointer != EXIT)
        {
            cout << "Enter name: ";
            string name;
            getline(cin, name);
            system("cls");
            cout << "Enter age: ";
            unsigned short age;
            cin >> age;
            GenderMenu genderMenu;
            unsigned short miniPointer;
            miniPointer = genderMenu.selection();
            if (miniPointer == ADD_HUMAN_OR_MALE)
            {
                if (pointer == ADD_HUMAN_OR_MALE)
                    humanPopulation.addEntity(new Man(Male, name, age));
            }
        }
        if (pointer == ADD_HUMAN)
        {
            
            
        }
    } while (pointer != EXIT);
    
    
    return 0;
}