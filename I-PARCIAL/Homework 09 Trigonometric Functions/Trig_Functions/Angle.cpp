/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
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

#include "Angle.h"

Angle::Angle(double new_grade_angle)
{
    this->grade_angle = new_grade_angle;
}

void Angle::set_grade_angle(double new_grade_angle)
{
    this->grade_angle = new_grade_angle;
}

double Angle::get_grade_angle()
{
    return grade_angle;
}

Angle::~Angle()
{
    
}
