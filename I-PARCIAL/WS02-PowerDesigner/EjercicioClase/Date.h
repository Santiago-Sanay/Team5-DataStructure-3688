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
 * Module:  Date.h
 * Author:  User
 * Modified: lunes, 31 de mayo de 2021 10:35:55
 * Purpose: Declaration of the class Date
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Date_h)
#define __Class_Diagram_1_Date_h

class Date
{
public:
   int getDay(void);
   void setDay(int newDay);
   int getMonth(void);
   void setMonth(int newMonth);
   int getYear(void);
   void setYear(int newYear);
   Date(int _day, int _month, int _year);
   ~Date();

protected:
private:
   int day;
   int month;
   int year;


};

#endif