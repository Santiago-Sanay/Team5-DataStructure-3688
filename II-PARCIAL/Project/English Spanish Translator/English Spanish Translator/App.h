#pragma once
#include <vector>
#include <iostream>
#include "MenuOption.h"
#include "Menu1.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
using namespace std;
class Application
{
private:
	static void init();
	static void validate_account();
	static void manager_menu();
	static void user_menu();
	static void write(string);
	static void modify_password();
	static void menu_of_modify();
	static void prueba();
	static void traductor_menu();
	static void print_menu();
	static void modify_user();
	static string read();
	static void exit_program();
	static void add_word();
public:

	static int run();
};
