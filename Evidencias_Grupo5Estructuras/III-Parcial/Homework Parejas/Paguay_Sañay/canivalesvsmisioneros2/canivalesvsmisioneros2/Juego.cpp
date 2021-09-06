/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#include "Juego.h"

Juego::Juego(int n)
{
	this->m_izq = n;
	this->c_izq = n;
	this->m_der = 0;
	this->c_der = 0;
	this->lado = true;
}

int Juego::get_m_izq()
{
	return this->m_izq;
}

int Juego::get_c_izq()
{
	return this->c_izq;
}

void Juego::set_m_izq(int new_m_izq)
{
	this->m_izq = new_m_izq;
}

void Juego::set_c_izq(int new_c_izq)
{
	this->c_izq = new_c_izq;
}

int Juego::get_m_der()
{
	return this->m_der;
}

int Juego::get_c_der()
{
	return this->c_der;
}

void Juego::set_m_der(int new_m_der)
{
	this->m_der = new_m_der;
}

void Juego::set_c_der(int new_c_der)
{
	this->c_der = new_c_der;
}

bool Juego::get_lado()
{
	return this->lado;
}

void Juego::set_lado(bool new_lado)
{
	this->lado = new_lado;
}
