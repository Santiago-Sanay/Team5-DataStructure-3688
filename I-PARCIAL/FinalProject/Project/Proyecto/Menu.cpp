#include "Menu.h"
Menu::Menu(std::vector<MenuOption> options) : menu_option_(options)
{
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
}
void Menu::navigation()
{

    if (menu_option_.empty()) {
        return;
    }
    int i{ 1 };
    display(1);
    while (1)
    {
        int option = _getch();


        switch (option)
        {
        case KEY_UP:
        {
            if (i != 1)
            {
                i--;
                display(i);
            }
            break;
        }
        case KEY_DOWN:
        {
            if (i != menu_option_.size())
            {
                i++;
                display(i);
            }
            break;
        }
        case KEY_ENTER:
        {
            system("cls");
            menu_option_.at(i - 1).get_fuction()();
            system("pause");
            break;
        }
        case KEY_ESCAPE:
        {
            exit(0);
            break;
        }

        default:
            break;
        }
    }
}

void Menu::display(int option)
{
    system("cls");
    unsigned int i = 0;

    while (i < menu_option_.size())
    {

        if (option == i + 1)
        {
            SetConsoleTextAttribute(console_, BACKGROUND_GREEN);
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
            SetConsoleTextAttribute(console_, COLOR_BACKGROUND);
        }
        else
        {
            std::cout << "[" << menu_option_[i].get_number_option_() << "] " << menu_option_[i].get_title_() << std::endl;
        }
        i++;
    }
}