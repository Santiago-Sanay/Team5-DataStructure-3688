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
#pragma once
class Angle
{
private:
	double grade_angle;
public:
	Angle(double);
	void set_grade_angle(double);
	double get_grade_angle();
	~Angle();
};

