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
 * Module:  Person.h
 * Author:  User
 * Modified: lunes, 31 de mayo de 2021 10:34:38
 * Purpose: Declaration of the class Person
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Person_h)
#define __Class_Diagram_1_Person_h
#include <stdlib.h>
#include <iostream>
class Date;
using namespace std;
#include "Date.h"

class Person
{
public:
   string getName(void);
   void setName(string newName);
   string getLast_name(void);
   void setLast_name(string newLast_name);
   string getId(void);
   void setId(string newId);
   Person(string _name, string _last_name, string _id, Date* _date);
   ~Person();

protected:
private:
   string name;
   string last_name;
   string id;
   
   Date* date;


};

#endif