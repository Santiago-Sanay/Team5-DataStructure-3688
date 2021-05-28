#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include "Vector.h"
typedef void (*Menu_Processing_Function_Ptr)();
class Menu
{
private:
	unsigned int number;
	const std::string text;
	Menu_Processing_Function_Ptr p_processing_function;

public:
	/**
	 * @brief Construct a new Menu object
	 *
	 * @param int
	 */
	Menu(unsigned int, const std::string, Menu_Processing_Function_Ptr);

	/**
	 * @brief
	 *
	 */
	static void menu_engine(std::vector<Menu>&) noexcept;

	static void menu_vector();
};

template <typename>
static void menu_vector()
{
	std::cin.ignore(1000000, '\n');
	std::regex pattern("^\\(([0-9]+),([0-9]+),([0-9]+)\\)$");
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
	
	Vector<decltype(x)> 
}