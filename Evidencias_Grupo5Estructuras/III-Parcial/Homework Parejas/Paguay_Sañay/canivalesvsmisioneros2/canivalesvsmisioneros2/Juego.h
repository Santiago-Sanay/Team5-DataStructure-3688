/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/

#pragma once
class Juego
{
private:
	int m_izq;
	int m_der;
	int c_izq;
	int c_der;
	bool lado;
public:
	Juego(int n);
	/**
	 * @brief izquierdo
	 *
	 * @return int*
	 */
	int get_m_izq();
	/**
	 * @brief izquierdo
	 *
	 * @return int*
	 */
	int get_c_izq();
	/**
	 * @brief izquierdo
	 *
	 * @return int*
	 */
	void set_m_izq(int new_m_izq);
	/**
	 * @brief izquierdo
	 *
	 * @return int*
	 */
	void set_c_izq(int new_c_izq);
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	int get_m_der();
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	int get_c_der();
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	void set_m_der(int new_m_der);
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	void set_c_der(int new_c_der);
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	bool get_lado();
	/**
	 * @brief derecho
	 *
	 * @return int*
	 */
	void set_lado(bool new_lado);

};

