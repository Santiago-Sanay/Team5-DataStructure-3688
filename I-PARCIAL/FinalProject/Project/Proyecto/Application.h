#pragma once
#include <vector>
#include <iostream>
#include "MenuOption.h"
#include "Menu.h"
#include "Utils.h"
#include "File.h"
class Application
{
private:
	static void init();
	static void create_account();
public:
	static int run();
	
};

