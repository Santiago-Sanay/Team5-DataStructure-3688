#include "Operaciones.h"
#include <string>
using namespace std;
void Operaciones::encerar(Calendario calendario)
{
	string vect[100];
	for (int i = 0; i < 100; i++) 
	{
		vect[i] = "0";
	}
	calendario.set_fecha(vect);
}
int Operaciones::calcular_dia(string fecha)
{
	int day = stoi(fecha.substr(0, 2));
	int month = stoi(fecha.substr(3, 2));
	int year = stoi(fecha.substr(6, 9));

	int month1 = 0;
	if (month == 1 || month == 10) 
	{
		month1 = 0;
	}
	else {
		if (month == 2 || month == 13 || month == 11) {
			month1 = 3;
		}
		else {
			if (month == 4 || month == 7 ) {
				month1 = 6;
			}
			else {
				if (month == 5 ) {
					month1 = 1;
				}
				else {
					if (month == 6) {
						month1 = 4;
					}
					else {
						if (month == 8) {
							month1 = 2;
						}
						else {
							month1 = 5;
						}
					}
				}

			}
		}
	}
	int century = 0;
	if (year <= 1999) {
		century = 0;
	}
	else {
		if (year <= 2099 && year > 1999) {
			century = 6;
		}
	}
	int year1 = year % 100;
	int zeller_sum = day + month1 + year1 + (year1 / 4) + century;
	
	int day_week = zeller_sum % 7;
	return day_week;
}

 
