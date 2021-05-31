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
void Operaciones::llenar_vector_fechas(string fecha, int cuotas, Calendario& calendario)
{
	string* vect = calendario.get_fecha();

	int day = stoi(fecha.substr(0, 2));
	int month = stoi(fecha.substr(3, 2));
	int year = stoi(fecha.substr(6, 9));
	string day1;
	string month1;
	string year1;
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	for (int i = 0; i < cuotas; i++) {
		if (month < 10) {
			month1 = "0" + to_string(month);
		}
		else {
			month1 = to_string(month);
		}
		year1 = "" + to_string(year);
		vect[i] = day1 + "-" + month1 + "-" + year1;
		month = month + 1;
		if (month == 13) {
			year = year + 1;
			month = 1;
		}
	}
	for (int i = 0; i < cuotas; i++) {
		vect[i] = ajustar_fecha_valida(vect[i]);
	}
	ajustar_fds(cuotas, vect);
}



string Operaciones::ajustar_fecha_valida(string fecha)
{
	int day = stoi(fecha.substr(0, 2));
	int month = stoi(fecha.substr(3, 2));
	int year = stoi(fecha.substr(6, 9));
	string day1;
	string month1;
	string year1;
	if (month > 12) {
		month = 12;

	}

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 31;

	}
	else {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			day = 30;
		}
		else {
			if (year % 4 == 0 && day > 29 && month == 2) {
				day = 29;
			}
			else {
				if (year % 4 != 0 && day > 28 && month == 2) {
					day = 28;
				}
			}
		}

	}
	if (month < 10) {
		month1 = "0" + to_string(month);
	}
	else {
		month1 = to_string(month);
	}
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
	string date = day1 + "-" + month1 + "-" + to_string(year);
	return date;
}

void Operaciones::print_calendar(int cuotas, string vect[100])
{
	for (int i = 0; i < cuotas; i++) {
		cout << i + 1 << " " << vect[i] << endl;
	}
}

bool Operaciones::verificar_fds(string date)
{
	bool fds = false;
	if (calcular_dia(date) == 6 || calcular_dia(date) == 0) {
		fds = true;
	}
	return fds;
}
bool Operaciones::verificar_fds(string date)
{
	bool fds = false;
	if (calcular_dia(date) == 6 || calcular_dia(date) == 0) {
		fds = true;
	}
	return fds;
}

<<<<<<< HEAD
void Operaciones::ajustar_fds(int cuotas, string vect[100])
{
	bool state = false;
	for (int i = 0; i < cuotas; i++) {

		while (verificar_fds(vect[i])) {
			vect[i] = sumar_dia(vect[i]);

		}

	}

}

bool Operaciones::verificar_feriado(string fecha)
{
	int day = stoi(fecha.substr(0, 2));
	int month = stoi(fecha.substr(3, 2));
	string day1;
	string month1;
	string feriado[14];
	feriado[0] = "01-01";
	feriado[1] = "15-02";
	feriado[2] = "16-02";
	feriado[3] = "02-04";
	feriado[4] = "01-05";
	feriado[5] = "28-05";
	feriado[6] = "25-07";
	feriado[7] = "10-08";
	feriado[8] = "09-10";
	feriado[9] = "02-11";
	feriado[10] = "03-11";
	feriado[11] = "06-12";
	feriado[12] = "24-12";
	feriado[13] = "25-12";
	bool state = false;

=======
string Operaciones::sumar_dia(string fecha)
{
	int day = stoi(fecha.substr(0, 2));
	int month = stoi(fecha.substr(3, 2));
	int year = stoi(fecha.substr(6, 9));
	string day1;
	string month1;
	string year1;
	day = day + 1;


	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		day = 1;
		month = month + 1;


	}
	else {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			day = 1;
			month = month + 1;
		}
		else {
			if (year % 4 == 0 && day > 29 && month == 2) {
				day = 1;
				month = month + 1;
			}
			else {
				if (year % 4 != 0 && day > 28 && month == 2) {
					day = 1;
					month = month + 1;
				}
			}
		}

	}
	if (month > 12) {
		month = 1;
		year = year + 1;

	}
>>>>>>> 4cf23ebeb07ac40c403211f1c2a32558719e226e
	if (month < 10) {
		month1 = "0" + to_string(month);
	}
	else {
		month1 = to_string(month);
	}
	if (day < 10) {
		day1 = "0" + to_string(day);
	}
	else {
		day1 = to_string(day);
	}
<<<<<<< HEAD
	string date_verify = day1 + "-" + month1;
	cout << date_verify << "si entra aca" << endl;
	for (int i = 0; i < 20; i++) {
		if (date_verify == feriado[i]) {
			state = true;

		}
	}
	return false;
}

=======
	string date = day1 + "-" + month1 + "-" + to_string(year);
	return date;
}
>>>>>>> 4cf23ebeb07ac40c403211f1c2a32558719e226e
 
