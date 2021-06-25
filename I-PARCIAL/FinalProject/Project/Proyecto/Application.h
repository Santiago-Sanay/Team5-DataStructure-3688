#pragma once
#include <vector>
#include <iostream>
#include "MenuOption.h"
#include "Menu.h"
#include "Utils.h"
#include "File.h"
#include "Due.h" // 
#include "Doubt.h" // 
#include "CalendarOperation.h"
#include "TextTable.h"
#include <iomanip>

class Application
{
private:
	static void init();
	static void create_account();
	static LinkedList<Person>& container();
	static LinkedList<Doubt>& container_credits();
	static void print_exists(std::string id);
	static void create_credit();
	static void create_pdf();
	static void print_amortization_table();
	static LinkedList<Due>amortization(std::string &);
public:
	static int run();
	
};

