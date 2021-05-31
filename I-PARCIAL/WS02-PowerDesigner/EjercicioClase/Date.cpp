/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: GENERAR CODIGO CON LA HERRAMIENTA POWER DESIGNER
*FECHA DE CREACION : 31 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 31 DE MAYO 2021*/

/***********************************************************************
 * Module:  Date.cpp
 * Author:  User
 * Modified: lunes, 31 de mayo de 2021 10:35:55
 * Purpose: Implementation of the class Date
 ***********************************************************************/

#include "Date.h"

////////////////////////////////////////////////////////////////////////
// Name:       Date::getDay()
// Purpose:    Implementation of Date::getDay()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Date::getDay(void)
{
   return day;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::setDay(int newDay)
// Purpose:    Implementation of Date::setDay()
// Parameters:
// - newDay
// Return:     void
////////////////////////////////////////////////////////////////////////

void Date::setDay(int newDay)
{
   day = newDay;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::getMonth()
// Purpose:    Implementation of Date::getMonth()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Date::getMonth(void)
{
   return month;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::setMonth(int newMonth)
// Purpose:    Implementation of Date::setMonth()
// Parameters:
// - newMonth
// Return:     void
////////////////////////////////////////////////////////////////////////

void Date::setMonth(int newMonth)
{
   month = newMonth;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::getYear()
// Purpose:    Implementation of Date::getYear()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Date::getYear(void)
{
   return year;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::setYear(int newYear)
// Purpose:    Implementation of Date::setYear()
// Parameters:
// - newYear
// Return:     void
////////////////////////////////////////////////////////////////////////

void Date::setYear(int newYear)
{
   year = newYear;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::Date(int _day, int _month, int _year)
// Purpose:    Implementation of Date::Date()
// Parameters:
// - _day
// - _month
// - _year
// Return:     
////////////////////////////////////////////////////////////////////////

Date::Date(int _day, int _month, int _year)
{
	this->day = _day;
	this->month = _month;
	this->year = _year;
}

////////////////////////////////////////////////////////////////////////
// Name:       Date::~Date()
// Purpose:    Implementation of Date::~Date()
// Return:     
////////////////////////////////////////////////////////////////////////

Date::~Date()
{
   // TODO : implement
}