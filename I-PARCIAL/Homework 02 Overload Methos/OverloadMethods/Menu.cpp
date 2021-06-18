/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE METODOS
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/

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
void Menu::menu_vector()
{
	std::regex pattern("(\\s*\\(\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\)\\s*)");
	std::string coords{};
	std::smatch matches;

	Vector<float> vectors_float[2]{};
	Vector<int> vectors_int[2]{};
	size_t j{ 0 };
	size_t k{ 0 };
	for (size_t i = 1; i < 3; ++i)
	{
		std::cout << "Ingrese el " << i << " vector en el formato(#, #, #) : ";
		getline(std::cin, coords);
		bool match = std::regex_match(coords, matches, pattern);
		int data_type = Menu::data_type(coords);
		if (match)
		{
			if (data_type == 0)
			{
				float x = std::stof(matches[2]);
				float y = std::stof(matches[4]);
				float z = std::stof(matches[6]);
				vectors_float[k].set_x(x);
				vectors_float[k].set_y(y);
				vectors_float[k].set_z(z);
				++k;
			}
			else
			{
				int x = std::stoi(matches[2]);
				int y = std::stoi(matches[4]);
				int z = std::stoi(matches[6]);
				vectors_int[j].set_x(x);
				vectors_int[j].set_y(y);
				vectors_int[j].set_z(z);
				++j;
			}
		}
		else
		{
			std::cout << "El formato ingresado es incorrecto! (#,#,#)";
			i = 0;
			std::cin.ignore(9999, '\n');
			system("exit");
		}

	}
	if (k == 2)
		Menu::print_results(vectors_float[0], vectors_float[1]);
	else if (j == 2)
		Menu::print_results(vectors_int[0], vectors_int[1]);
	else
		Menu::print_results(vectors_float[0], vectors_int[0]);

}

int Menu::data_type(std::string& str)
{
	for (auto i : str)
	{
		if (i == '.')
			return 0;
	}
	return 1;
}








