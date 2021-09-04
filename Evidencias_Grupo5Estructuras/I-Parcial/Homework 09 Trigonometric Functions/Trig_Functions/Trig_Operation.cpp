﻿/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: FUNCIONES TRIGONOMETRICAS
*FECHA DE CREACION : 5 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include "Trig_Operation.h"
#include "Math.h"
#include <iostream>
using namespace std;
double Trig_Operation::sin(Angle angle )
{
    double x = angle.get_grade_angle();
    double result,precission;
    result = 0;
    precission = 0;
    int sign=0,final_sign;
    final_sign = 0;
    const double pi = 3.141592654;
    while (x > pi) {
        x = x - pi;
        final_sign = final_sign + 1;
    }
    for (int i = 1; i <= 11; i = i + 2) {
        precission = pow(-1, sign)*(potencia(x,i) / factorial(i));

        result = result + precission;
        sign = sign + 1;
        
    }
    if (final_sign % 2 != 0) {
        result = result * -1;
    }
    return result;
}


double Trig_Operation::cos(Angle a)
{
    double angle = a.get_grade_angle();
    double result = 0; 
    int presicion = 8; 
    const double pi = 3.141592654;
    while (angle > pi) {
        angle = angle - pi;
 
    }
    for (int i = 0; i < presicion; i++)
    {
        result += ((pow(-1, i)) / factorial(2 * i)) * potencia(angle, 2 * i);
    }
    return result;
}

double Trig_Operation::tan(Angle angle)
{
    double tan;
    tan = Trig_Operation::sin(angle) / Trig_Operation::cos(angle);
    return tan;
}


double Trig_Operation::cot(Angle angle)
{
    double cot;
    cot = 1 / Trig_Operation::tan(angle);
    return cot;
}

double Trig_Operation::sec(Angle angle)
{
    double sec;
    sec = 1 / Trig_Operation::sin(angle);
    return sec;
}

long Trig_Operation::factorial(int n)
{
    //Funciona hasta 16! 
    if (n < 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

double Trig_Operation::potencia(double num, int pot)
{
    double result=1;
    if (pot == 0) {
        return 1;
    }
    if (pot == 1) {
        return num;
    }
    for (int i = 0; i < pot; i++) {
        result = result * num;
    }
    return result;
}
