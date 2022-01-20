#include "initgame.h"

void mainMenu()
{
    const unsigned short menuItemsNum = 4;
    const char greet[] = "Greetings!\nSelect options from below using arrow keys "
                         "and confirm your selection by pressing 'Enter'\n\n";
    const char humanVsComputer[] = "1. Human vs Computer\n";
    const char humanVsHuman[] = "2. Human vs Human\n";
    const char Help[] = "3. Help\n";
    const char Exit[] = "4. Exit\n";

    const unsigned short menuEndItemNum = 2;
    const char greeting[] = "Again?\n\n";
    const char yes[] = "1. Yes\n";
    const char no[] = "2. No\n";

    bool computer = true, stop = false;
    do
    {
        switch (menu(menuItemsNum, greet, humanVsComputer, humanVsHuman, Help, Exit))
        {
            case 1:
                settings(computer);
                switch (menu(menuEndItemNum, greeting, yes, no))
                {
                    case 1:
                        continue;
                    case 2:
                        stop = true;
                        break;
                    default:;
                }
                break;
            case 2:
                computer = false;
                settings(computer);
                switch (menu(menuEndItemNum, greeting, yes, no))
                {
                    case 1:
                        continue;
                    case 2:
                        stop = true;
                        break;
                    default:;
                }
                break;
            case 3:
                help();
                break;
            case 4:
                system("cls");
                exit(0);
            default:;
        }
    } while (!stop);
}

void inline help()
{
    system("cls");
    cout << "====================== Rules of the game ======================\n\n";

    cout << "The game is played on a grid that's 3x3, 4x4, or 5x5 squares.\n";
    cout << "One player plays as 'X', another plays as 'O'. Players take turns\n"
            "putting their marks in empty squares.\n";
    cout << "The first player to get 3, 4, or 5 of his marks in a row( up,\n"
            "down, across, or diagonally) is the winner.\n";
    cout << "When all squares are full, the game is over. If no player has 3,\n"
            "4, or 5 marks in a row, the game ends in a tie.\n\n\n";


    cout << "========================== Game modes ==========================\n\n";

    cout << "3x3: Classic Tic Tac Toe. Get 3 marks in a row and win.\n\n";
    cout << "4x4: a) 3 in a row to win\n"
            "b) 4 in a row to win\n\n";
    cout << "5x5: a) 3 in a row to win\n"
            "b) 4 in a row to win\n"
            "c) 5 in a row to win\n\n\n";


    cout << "=========================== Controls ===========================\n\n";

    cout << "Use arrow keys to select menu option or game cell. Chosen option\n"
            "or cell will be marked with '*'.\n\n\n";


    system("pause");
}

void settings(const bool computer)
{
    auto ticTacToe = new (nothrow) Game;

    if (ticTacToe != nullptr)
    {
        playersInit(ticTacToe);
        gameMode(ticTacToe);
        gameplay(ticTacToe, computer);

        for (unsigned short i = 0; i < ticTacToe->field.size; ++i)
        {
            delete[] ticTacToe->field.cells[i];
        }
        delete ticTacToe->field.cells;
        ticTacToe->field.cells = nullptr;
    }
    else
    {
        cerr << "Error occurred while attempting allocate memory\n\n";
        system("pause");
    }
    delete ticTacToe;
}

void playersInit(Game* ticTacToe)
{
    const unsigned short menuItemsNum = 3;
    const char greet[] = "Select your mark:\n";
    const char x[] = "1. X\n";
    const char o[] = "2. O\n";
    const char random[] = "3. Random\n";

    switch (menu(menuItemsNum, greet, x, o, random))
    {
        case 1:
            ticTacToe->player1 = CROSS;
            ticTacToe->player2 = CIRCLE;
            break;
        case 2:
            ticTacToe->player1 = CIRCLE;
            ticTacToe->player2 = CROSS;
            break;
        case 3:
            if (getRandomNum(1, 2) == 1)
            {
                ticTacToe->player1 = CROSS;
                ticTacToe->player2 = CIRCLE;
            }
            else
            {
                ticTacToe->player1 = CIRCLE;
                ticTacToe->player2 = CROSS;
            }
            break;
        default:;
    }
}

void gameMode(Game* ticTacToe)
{
    const unsigned short menuItemsNum1 = 3;
    unsigned short menuItemNum2;
    const char greet[] = "Select field size:\n";
    const char x3[] = "1. 3x3\n";
    const char x4[] = "2. 4x4\n";
    const char x5[] = "3. 5x5\n";

    const char greeting[] = "Select game mode:\n";
    const char classic[] = "1. Classic (3 in a row to win)\n";
    const char fourInRow[] = "2. 4 in a row to win\n";
    const char fiveInRow[] = "3. 5 in a row to win\n";

    switch (menu(menuItemsNum1, greet, x3, x4, x5))
    {
        case 1:
            ticTacToe->mode = CLASSIC;
            ticTacToe->field.size = 3;
            break;
        case 2:
            menuItemNum2 = 2;
            ticTacToe->field.size = 4;
            switch (menu(menuItemNum2, greeting, classic, fourInRow))
            {
                case 1:
                    ticTacToe->mode = CLASSIC;
                    break;
                case 2:
                    ticTacToe->mode = FOUR_IN_ROW;
                    break;
                default:;
            }
            break;
        case 3:
            menuItemNum2 = 3;
            ticTacToe->field.size = 5;
            switch (menu(menuItemNum2, greeting, classic, fourInRow, fiveInRow))
            {
                case 1:
                    ticTacToe->mode = CLASSIC;
                    break;
                case 2:
                    ticTacToe->mode = FOUR_IN_ROW;
                    break;
                case 3:
                    ticTacToe->mode = FIVE_IN_ROW;
                    break;
                default:;
            }
            break;
        default:;
    }

    if (*ticTacToe->field.cells != nullptr)
    {
        ticTacToe->field.cells = new (nothrow) Marks* [ticTacToe->field.size];
        for (size_t i = 0; i < ticTacToe->field.size; ++i)
        {
            ticTacToe->field.cells[i] = new (nothrow) Marks[ticTacToe->field.size];
            if (ticTacToe->field.cells[i] != nullptr)
            {
                for (unsigned short j = 0; j < ticTacToe->field.size; ++j)
                {
                    ticTacToe->field.cells[i][j] = EMPTY;
                }
            }
            else
            {
                cerr << "Error occurred while attempting allocate memory\n\n";
                system("pause");
            }
        }
    }
    else
    {
        cerr << "Error occurred while attempting allocate memory\n\n";
        system("pause");
    }
}

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}
