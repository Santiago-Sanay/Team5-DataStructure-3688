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
 * Module:  Person.cpp
 * Author:  User
 * Modified: lunes, 31 de mayo de 2021 10:34:38
 * Purpose: Implementation of the class Person
 ***********************************************************************/

#include "Date.h"
#include "Person.h"

////////////////////////////////////////////////////////////////////////
// Name:       Person::getName()
// Purpose:    Implementation of Person::getName()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Person::getName(void)
{
   return name;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::setName(std::string newName)
// Purpose:    Implementation of Person::setName()
// Parameters:
// - newName
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setName(std::string newName)
{
   name = newName;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::getLast_name()
// Purpose:    Implementation of Person::getLast_name()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Person::getLast_name(void)
{
   return last_name;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::setLast_name(std::string newLast_name)
// Purpose:    Implementation of Person::setLast_name()
// Parameters:
// - newLast_name
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setLast_name(std::string newLast_name)
{
   last_name = newLast_name;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::getId()
// Purpose:    Implementation of Person::getId()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Person::getId(void)
{
   return id;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::setId(std::string newId)
// Purpose:    Implementation of Person::setId()
// Parameters:
// - newId
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setId(std::string newId)
{
   id = newId;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::Person(std::string _name, std::string _last_name, std::string _id, Date _date)
// Purpose:    Implementation of Person::Person()
// Parameters:
// - _name
// - _last_name
// - _id
// - _date
// Return:     
////////////////////////////////////////////////////////////////////////

Person::Person(std::string _name, std::string _last_name, std::string _id, Date* _date)
{
   this-> name = _name;
   this-> last_name = _last_name;
   this-> id = _id;
   this-> date = _date;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::~Person()
// Purpose:    Implementation of Person::~Person()
// Return:     
////////////////////////////////////////////////////////////////////////

Person::~Person()
{
   // TODO : implement
}