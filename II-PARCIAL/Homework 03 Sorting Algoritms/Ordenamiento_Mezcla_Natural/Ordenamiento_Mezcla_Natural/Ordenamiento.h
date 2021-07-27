/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR DATA PAYMENT
*FECHA DE CREACION : 9 DE JULIO DE 2021
*FECHA DE MODIFICACION: 9 DE JULIO DEL 2021
*/
#pragma once
#include <string>
#include "List.h"
#include <time.h>
#include <ctime>
#include <random>
#include <functional>
#include "mystring.h"
using namespace std;
class Ordenamiento
{
public:
	/**
	 * @brief Ordena un archivo
	 *
	 * @void
	 */
	void natural_sort(const string);
	void natural_sort1(function<bool(ifstream&)>archivo_vacio2, const string);
	/**
	 * @brief Particiona el archivo original en archivo2.txt y archivo3.txt
	 *
	 * @ void
	 */
	void particion_inicial(const string, const string, const string);
	/**
	 * @brief genera una lista de aleatorios enteros
	 *
	 * @devuelve una lista con numeros aleatorios enteros
	 */
	List<int> generar_aleatorio(int,int);
	/**
	 * @brief Guarda la lista aleatoria en un archivo
	 *
	 * @ void
	 */
	void grabar_aleatorio(List<int>, string);
	/**
	 * @brief crea un archivo con un numero determinado de aleatorios
	 *
	 * @
	 */
	void crear_archivo_aleatorio(string, int,int);
	/**
	 * @brief verifica si un archivo esta vacio
	 *
	 * @ true or false
	 */
	bool archivo_vacio(ifstream&);
	/**
	 * @brief Particiona el archivoA y archivo B y los fusiona el el archivoD y Archivo C
	 *
	 * @void
	 */
	void particionFusion(string archfa, string archfb, string archfc, string archfd);
	/**
	 * @brief verifica si e¿archivo c esta disponible para grabar datos
	 *
	 * @void
	 */
	void ayuda1(int& aux, int r, ofstream& fc, ofstream& fd, bool band, int& contc, int& contd);
	/**
	 * @brief verifica si el archivo 2 esta listo para grabar y cambia el estado de band
	 *
	 * @void
	 */
	void ayuda2(int& aux, int r, ofstream& fc, ofstream& fd, bool &band, int& contc, int& contd);
	/**
	 * @brief escribe una linea en archivo
	 *
	 * @void
	 */
	void escribir_en_archivo(ofstream&, int&,int );
	/**
	 * @brief lee una linea de archivo
	 *
	 * @entero
	 */
	int leer_linea(ifstream&);
	/**
	 * @brief Member Constructor of Calendar
	 *
	 * @
	 */
	void ayuda3(int& aux, int r, ifstream& f, ofstream& fc, ofstream& fd, bool &band,int &contC,int &contD);
	/**
	 * @brief imprime el contenido del archivo
	 *
	 * @
	 */
	void imprimir_archivo(string f);
	/**
	 * @brief cuenta las lineas de archivo
	 *
	 * @
	 */
	int contar_lineas(string f);
};

