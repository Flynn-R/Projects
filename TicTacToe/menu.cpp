#include "consts.h"

unsigned short menu(size_t count, ...)
{
    va_list str;

    unsigned short select = 1;
    bool check = false;
    do
    {
        system("cls");
        va_start(str, count);
        selection(count, select, &str);

        char key = static_cast<char>(_getch());
        switch (key)
        {
            case UP:
                if (select != 1)
                {
                    select--;
                }
                break;
            case DOWN:
                if (select != count)
                {
                    select++;
                }
                break;
            case ENTER:
                check = true;
            default:;
        }
    } while (!check);

    return select;
}

void __fastcall selection(size_t count, const unsigned short select, va_list* str)
{
    switch (count)
    {
        case 2:
            switch (select)
            {
                case 1:
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 2:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                default:;
            }
            break;
        case 3:
            switch (select)
            {
                case 1:
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 2:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 3:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                default:;
            }
            break;
        case 4:
            switch (select)
            {
                case 1:
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 2:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 3:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                case 4:
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << va_arg(*str, const char*);
                    cout << "* " << va_arg(*str, const char*);
                    va_end(*str);
                    break;
                default:;
            }
            break;
        default:;
    }
}
