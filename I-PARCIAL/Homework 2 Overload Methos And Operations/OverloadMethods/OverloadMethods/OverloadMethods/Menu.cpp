#include "Menu.h"

Menu::Menu(unsigned int number, const std::string text, Menu_Processing_Function_Ptr p_processing_function)
	: number(number), text(text), p_processing_function(p_processing_function)
{
}

void Menu::menu_engine(std::vector<Menu>& menu_item) noexcept
{

	for (unsigned int i = 0; i < menu_item.size(); ++i)
	{
		std::cout << menu_item[i].number
			<< ". "
			<< menu_item[i].text
			<< "\n";
	}

	std::cout << "Enter selection: ";
	unsigned int selection;
	std::cin >> selection;

	for (unsigned int i = 0; i < menu_item.size(); ++i)
	{
		if (selection == menu_item[i].number)
		{
			(menu_item[i].p_processing_function)();
			break;
		}
	}

	if (selection > menu_item.size())
	{
		std::cout << "Opcion Invalida";
	}
}


static void menu_vector()
{
	std::cin.ignore(1000000, '\n');
	std::regex pattern("\\s*\\(\\s*([+-] ? ([0 - 9]*[.])?[0 - 9] + )\\s *\\,\\s*([+-] ? ([0 - 9]*[.]) ? [0 - 9] +)\\s*\\, \\s *([+-] ? ([0 - 9]*[.]) ? [0 - 9]+)\\s*\\)\\s*");
	std::string input;

	std::cout << "Ingrese el primer vector en el formato (#,#,#): ";
	getline(std::cin, input);

	// remove all spaces
	input.erase(std::remove_if(
		input.begin(),
		input.end(),
		::isspace),
		input.end());

	std::smatch sm;

	if (!std::regex_match(input, sm, pattern))
	{
		std::cout << "formato incorrecto (#,#,#)" << std::endl;
		exit(0);
	}

	auto x = std::atoi(sm[1].str().c_str());
	auto y = std::atoi(sm[2].str().c_str());
	auto z = std::atoi(sm[3].str().c_str());
}