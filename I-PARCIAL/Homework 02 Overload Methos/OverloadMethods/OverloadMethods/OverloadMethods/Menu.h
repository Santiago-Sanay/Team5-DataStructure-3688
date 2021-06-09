#include <iostream>
#include <vector>
#include "Vector.h"
#include "Math.h"
#include <regex>
#include <iomanip>
#include <cctype>
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
	 *
	 * @param int
	 */
	Menu(unsigned int, const std::string, Menu_Processing_Function_Ptr);

	/**
	 * @brief
	 *
	 */
	void menu_engine(std::vector<Menu>&) noexcept;
	static void menu_vector();
	static int data_type(std::string&);

	template<typename T, typename U>
	static void print_results(Vector<T>&, Vector<U>&);
};

template<typename T, typename U>
inline void Menu::print_results(Vector<T>& u, Vector<U>& v)
{
	std::cout << std::endl;
	Vector<T> result_add = Math::add(u, v);
	std::cout << "La suma de Vectores es: " << "("
		<< result_add.get_x() << "i, "
		<< result_add.get_y() << "j, "
		<< result_add.get_z() << "k)"
		<< std::endl;

	Vector<T> result_subtract = Math::subtract(u, v);
	std::cout << "La resta de vectores es: " << "("
		<< result_subtract.get_x() << "i, "
		<< result_subtract.get_y() << "j, "
		<< result_subtract.get_z() << "k)"
		<< std::endl;

	T scalar_product = Math::scalar_product(u, v);
	std::cout << "El producto punto entre los vectores es: " << scalar_product << std::endl;

	Vector<T> result_vector_product = Math::vector_product(u, v);
	std::cout << "El producto cruz de los vectores es: " << "("
		<< result_vector_product.get_x() << "i, "
		<< result_vector_product.get_y() << "j, "
		<< result_vector_product.get_z() << "k)"
		<< std::endl;

	Vector<T> scalar_by_a_vector = Math::scalar_by_a_vector(u, v);
	std::cout << "El producto escalar por un es: " << "("
		<< scalar_by_a_vector.get_x() << "i, "
		<< scalar_by_a_vector.get_y() << "j, "
		<< scalar_by_a_vector.get_z() << "k)"
		<< std::endl;
}
