#include "consts.h"
#include "gameplay.h"

void gameplay(Game* ticTacToe, const bool computer)
{
    ticTacToe->gameState = IN_PROGRESS;

    if (ticTacToe->player1 == CROSS)
    {
        ticTacToe->turn = 0;
    }
    else
    {
        ticTacToe->turn = 1;
    }

    while (ticTacToe->gameState == IN_PROGRESS)
    {
        if (computer)
        {
            ticTacToe->gameState = vi(ticTacToe);
        }
        else
        {
            ticTacToe->gameState = player(ticTacToe);
        }

        if (ticTacToe->gameState == WIN)
        {
            ticTacToe->turn == 0 ? cout << "\n======= PLAYER 2 WON!!! =======\n\n": \
            cout << "\n======= PLAYER 1 WON!!! =======\n\n";
            system("pause");
        }
        else
        {
            if (ticTacToe->gameState == DRAW)
            {
                cout << "\nDRAW\n\n";
                system("pause");
            }
        }
    }
}

void __fastcall drawField(Field* field, const unsigned short turn)
{
    system("cls");

    turn == 0 ? cout << "It's Player 1's turn\n\n" : cout << "It's Player 2's turn\n\n";

    for (unsigned short i = 0; i < field->size; ++i)
    {
        for (unsigned short j = 0; j < field->size; ++j)
        {
            cout << field->cells[i][j];
            j + 1 < field->size ? cout << "|" : cout << "\n";
        }
    }

    cout << "\n";
}

GameState player(Game* ticTacToe)
{
    for (unsigned short i = 0; i < ticTacToe->field.size; ++i)
    {
        for (unsigned short j = 0; j < ticTacToe->field.size; ++j)
        {
            if (ticTacToe->field.cells[i][j] == EMPTY)
            {
                ticTacToe->field.cells[i][j] = SELECTED;
                i = ticTacToe->field.size;
                break;
            }
        }
    }

    char key;
    do
    {
        drawField(&ticTacToe->field, ticTacToe->turn);

        key = static_cast<char>(_getch());
        for (unsigned short i = 0; i < ticTacToe->field.size; ++i)
        {
            for (unsigned short j = 0; j < ticTacToe->field.size; ++j)
            {
                if (ticTacToe->field.cells[i][j] == SELECTED)
                {
                    unsigned short shift = 1;
                    switch (key)
                    {
                        case LEFT:
                            while (j - shift >= 0)
                            {
                                if (ticTacToe->field.cells[i][j - shift] == EMPTY)
                                {
                                    ticTacToe->field.cells[i][j] = EMPTY;
                                    ticTacToe->field.cells[i][j - shift] = SELECTED;
                                    break;
                                }
                                else
                                    shift++;
                            }
                            break;
                        case RIGHT:
                            while (j + shift < ticTacToe->field.size)
                            {
                                if (ticTacToe->field.cells[i][j + shift] == EMPTY)
                                {
                                    ticTacToe->field.cells[i][j] = EMPTY;
                                    ticTacToe->field.cells[i][j + shift] = SELECTED;
                                    j = ticTacToe->field.size;
                                    break;
                                }
                                else
                                    shift++;
                            }
                            break;
                        case UP:
                            while (i - shift >= 0)
                            {
                                if (ticTacToe->field.cells[i - shift][j] == EMPTY)
                                {
                                    ticTacToe->field.cells[i][j] = EMPTY;
                                    ticTacToe->field.cells[i - shift][j] = SELECTED;
                                    break;
                                }
                                else
                                {
                                    for (unsigned short k = 0; k < ticTacToe->field.size; ++k)
                                    {
                                        if (ticTacToe->field.cells[i - shift][k] == EMPTY)
                                        {
                                            ticTacToe->field.cells[i][j] = EMPTY;
                                            ticTacToe->field.cells[i - shift][k] = SELECTED;
                                            shift += i;
                                            break;
                                        }
                                        else
                                        {
                                            if (k + 1 == ticTacToe->field.size)
                                                shift++;
                                        }
                                    }
                                }
                            }
                            break;
                        case DOWN:
                            while (i + shift < ticTacToe->field.size)
                            {
                                if (ticTacToe->field.cells[i + shift][j] == EMPTY)
                                {
                                    ticTacToe->field.cells[i][j] = EMPTY;
                                    ticTacToe->field.cells[i + shift][j] = SELECTED;
                                    j = ticTacToe->field.size;
                                    i = ticTacToe->field.size;
                                    break;
                                }
                                else
                                {
                                    for (unsigned short k = 0; k < ticTacToe->field.size; ++k)
                                    {
                                        if (ticTacToe->field.cells[i + shift][k] == EMPTY)
                                        {
                                            ticTacToe->field.cells[i][j] = EMPTY;
                                            ticTacToe->field.cells[i + shift][k] = SELECTED;
                                            j = ticTacToe->field.size;
                                            i = ticTacToe->field.size;
                                            break;
                                        }
                                        else
                                        {
                                            if (k + 1 == ticTacToe->field.size)
                                                shift++;
                                        }
                                    }
                                }
                            }
                            break;
                        case ENTER:
                            ticTacToe->turn == 0 ? ticTacToe->field.cells[i][j] = ticTacToe->player1 :\
                            ticTacToe->field.cells[i][j] = ticTacToe->player2;

                            drawField(&ticTacToe->field, ticTacToe->turn);
                            ticTacToe->turn == 0 ? ticTacToe->turn = 1 : ticTacToe->turn = 0;

                            if(ticTacToe->turn == 0)
                            {
                                return check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player2);
                            }
                            else
                            {
                                return check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player1);
                            }
                        default:;
                    }
                }
            }
        }
    } while (key != ENTER);
    return IN_PROGRESS;
}

GameState check(Field* field, const GameModes mode, const Marks player)
{
    unsigned short rowCheck = 0;
    unsigned short columnCheck = 0;
    unsigned short acrossCheck = 0;
    unsigned short diagonalCheck = 0;
    unsigned short drawCheck = 0;

    for (unsigned short i = 0; i < field->size; ++i)
    {
        for (unsigned short j = 0; j < field->size; ++j)
        {
            if (field->cells[i][j] != EMPTY)
            {
                if (field->cells[i][j] == player)
                {
                    rowCheck++;
                    if (rowCheck == mode)
                    {
                        return WIN;
                    }

                    if (i == j)
                    {
                        acrossCheck++;
                        if (acrossCheck == mode)
                        {
                            return WIN;
                        }
                    }

                    if (i == field->size - 1 - j)
                    {
                        diagonalCheck++;
                        if (diagonalCheck == mode)
                        {
                            return WIN;
                        }
                    }
                }
                else
                {
                    if (i == j)
                        acrossCheck = 0;
                    if (i == field->size - 1 - j)
                        diagonalCheck = 0;
                }
            }
            else
                drawCheck++;

            if (field->cells[j][i] != EMPTY)
            {
                if (field->cells[j][i] == player)
                {
                    columnCheck++;
                    if (columnCheck == mode)
                    {
                        return WIN;
                    }
                }
                else
                    columnCheck = 0;
            }
        }

        columnCheck = 0;
        rowCheck = 0;
    }

    if (drawCheck == 0)
    {
        return DRAW;
    }
    else
        return IN_PROGRESS;
}

GameState vi(Game* ticTacToe)
{
    if (ticTacToe->turn == 0)
    {
        return player(ticTacToe);
    }
    else
    {
        return preventWin(ticTacToe);
    }
}

GameState preventWin(Game* ticTacToe)
{
    for (unsigned short i = 0; i < ticTacToe->field.size; ++i)
    {
        for (unsigned short j = 0; j < ticTacToe->field.size; ++j)
        {
            if (ticTacToe->field.cells[i][j] == EMPTY)
            {
                ticTacToe->field.cells[i][j] = ticTacToe->player2;
                if (check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player2) == WIN)
                {
                    drawField(&ticTacToe->field, ticTacToe->turn);
                    ticTacToe->turn = 0;
                    return check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player2);
                }
                else
                {
                    ticTacToe->field.cells[i][j] = ticTacToe->player1;
                    if (check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player1) == WIN)
                    {
                        ticTacToe->field.cells[i][j] = ticTacToe->player2;
                        ticTacToe->turn = 0;
                        return check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player2);
                    }
                }
                ticTacToe->field.cells[i][j] = EMPTY;
            }
        }
    }

    bool stop = false;
    do
    {
        unsigned short n = getRandomNum(0, ticTacToe->field.size - 1);
        unsigned short m = getRandomNum(0, ticTacToe->field.size - 1);

        if (ticTacToe->field.cells[n][m] == EMPTY)
        {
            ticTacToe->field.cells[n][m] = ticTacToe->player2;
            stop = true;
        }
    } while (!stop);

    ticTacToe->turn = 0;
    return check(&ticTacToe->field, ticTacToe->mode, ticTacToe->player2);
}