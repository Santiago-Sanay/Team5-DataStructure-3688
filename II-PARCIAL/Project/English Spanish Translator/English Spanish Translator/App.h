#pragma once
#include <vector>
#include <iostream>
#include "MenuOption.h"
#include "Menu1.h"
#include "avl_tree.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
using namespace std;
class Application
{
private:
	AvlTree tree;
	 void init();
	 void validate_account();
	 void manager_menu();
	 void user_menu();
	 void write(string);
	 void modify_password();
	 void menu_of_modify();
	 void prueba();
	 void traductor_menu();
	 void print_menu();
	 void modify_user();
	 string read();
	 void exit_program();
	 void add_word();
public:

	 int run();
};
