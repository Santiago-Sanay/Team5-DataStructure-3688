/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE OPERADORES
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/
#pragma once

class Vector
{
private:
	double _coord_x;
	double _coord_y;
	double _coord_z;

public:
	Vector() = default;
	Vector(double, double, double);
	void set_x(double&);
	void set_y(double&);
	void set_z(double&);
	double get_x() const noexcept;
	double get_y() const noexcept;
	double get_z() const noexcept;
};


