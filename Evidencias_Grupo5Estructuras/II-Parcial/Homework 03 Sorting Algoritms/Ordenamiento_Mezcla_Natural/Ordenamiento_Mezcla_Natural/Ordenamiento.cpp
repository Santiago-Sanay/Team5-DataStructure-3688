/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: CALENDAR DATA PAYMENT
*FECHA DE CREACION : 9 DE JULIO DE 2021
*FECHA DE MODIFICACION: 9 DE JULIO DEL 2021
*/
#include "Ordenamiento.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
void Ordenamiento::natural_sort(const string f)
{
	int lineas = 0;
	lineas = contar_lineas(f);
	bool band = false;
	int archivo_vacio1 = -1;
	string f1 = "archivo1.txt";
	string f2 = "archivo2.txt";
	string f3 = "archivo3.txt";
	particion_inicial(f,f2,f3);
	band = true;
	do {
		if (band) {
			particionFusion(f2, f3, f, f1);
			band = false;
		}
		else {
			particionFusion(f, f1, f2, f3);
			band = true;
		}
		ifstream archivo1(f1.c_str(), ios::in);
		
		if (archivo_vacio(archivo1)) {
			archivo_vacio1 = 1;
		}
		archivo1.close();

		if (archivo_vacio1 == -1) {
			ifstream archivo3(f3.c_str(), ios::in);
			if (archivo_vacio(archivo3)) {
				archivo_vacio1 = 1;
			}
			archivo1.close();
		}
	} while (archivo_vacio1 == -1);
	ifstream archivo(f.c_str(), ios::in);
	archivo.close();
	if (contar_lineas(f) != lineas) {
		remove("archivo.txt");
		rename("archivo2.txt", "archivo.txt");
		remove("archivo1.txt");
		remove("archivo3.txt");
	}
	else {
		remove("archivo1.txt");
		remove("archivo3.txt");
		remove("archivo2.txt");
	}
}

void Ordenamiento::natural_sort1(function<bool(ifstream&)> archivo_vacio2, const string f)
{
	int lineas = 0;
	lineas = contar_lineas(f);
	bool band = false;
	int archivo_vacio1 = -1;
	string f1 = "archivo1.txt";
	string f2 = "archivo2.txt";
	string f3 = "archivo3.txt";
	particion_inicial(f, f2, f3);
	band = true;
	do {
		if (band) {
			particionFusion(f2, f3, f, f1);
			band = false;
		}
		else {
			particionFusion(f, f1, f2, f3);
			band = true;
		}
		ifstream archivo1(f1.c_str(), ios::in);

		if (archivo_vacio2(archivo1)) {
			archivo_vacio1 = 1;
		}
		archivo1.close();

		if (archivo_vacio1 == -1) {
			ifstream archivo3(f3.c_str(), ios::in);
			if (archivo_vacio2(archivo3)) {
				archivo_vacio1 = 1;
			}
			archivo1.close();
		}
	} while (archivo_vacio1 == -1);
	ifstream archivo(f.c_str(), ios::in);
	archivo.close();
	if (contar_lineas(f) != lineas) {
		remove("archivo.txt");
		rename("archivo2.txt", "archivo.txt");
		remove("archivo1.txt");
		remove("archivo3.txt");
	}
	else {
		remove("archivo1.txt");
		remove("archivo3.txt");
		remove("archivo2.txt");
	}

}



void Ordenamiento::particion_inicial(string f, string f2, string f3)
{
	
	ifstream archivo(f.c_str(), ios::in);
	ofstream archivo2(f2.c_str());
	ofstream archivo3(f3.c_str());
	int r=0, aux=0;
	string linea;
	mystring str;
	getline(archivo, linea);
	r = str.stoi(linea);
	archivo2 << r;
	bool band = true;
	aux = r; 
	int i = 0;
	int cont2 = 0, cont3 = 0;
	while (!archivo.eof()) {
		i++;
		
		getline(archivo, linea);
		r = str.stoi(linea);
		if (r >= aux) {
			aux = r;
			if (band == true) {
				archivo2 <<endl;
				archivo2 << r ;
				cont2++;
				
			}
			else {
				if (cont3 == 0) {
					archivo3 << r;
				}
				else {
					archivo3 << endl;
					archivo3 << r;
				}
				cont3++;
			}
		}
		else {
			aux = r;
			if (band == true) {
				if (cont3 == 0) {
					archivo3 << r;
				}
				else {
					archivo3 << endl;
					archivo3 << r;
				}
				cont3++;
				band = false;
			}
			else {
				archivo2 << endl;
				archivo2 << r;
				band = true;
			}
		}
	}
	
	archivo.close();
	archivo2.close();
	archivo3.close();

}



List<int> Ordenamiento::generar_aleatorio(int num,int range)
{
	srand(time(NULL));
	List<int> numbers;
	int number = 0;

	for (int i = 0; i < num; i++) {
		number = 1 + rand() % (range);
		numbers.insertar_por_la_cola(number);
	}
	return numbers;
}

void Ordenamiento::grabar_aleatorio(List<int> numbers, string file)
{
	ofstream archivo(file.c_str());
	Nodo<int>* temp = numbers.get_primero();
	int dato = 0;
	while (temp) {
		dato = temp->get_dato();
		if (temp->get_siguiente()) {
			archivo << dato << "\n";
			
		}
		else {
			archivo << dato;
		}
		
		
		temp = temp->get_siguiente();
	}
	archivo.close();
}

void Ordenamiento::crear_archivo_aleatorio(string file, int num,int range)
{ 
	List<int> numbers;
	numbers = generar_aleatorio(num,range);
	grabar_aleatorio(numbers, file);

}

bool Ordenamiento::archivo_vacio(ifstream &file)
{
	bool state = false;
	state= file.peek() == std::ifstream::traits_type::eof();
	return state;
}

void Ordenamiento::particionFusion(string fa, string fb, string fc, string fd)
{
	int aux=0, r1=0, r2=0;
	
	bool band, dele1, dele2;
	ifstream archivoA(fa.c_str(), ios::in);
	ifstream archivoB(fb.c_str(), ios::in);
	ofstream archivoC(fc.c_str());
	ofstream archivoD(fd.c_str());

	band = true;
	r1 = leer_linea(archivoA);
	r2 = leer_linea(archivoB);
	if (r1 <= r2)
		aux = r1;
	else
		aux = r2;
	
	dele1 = dele2 = false;
	int contC = 0, contD = 0,cont3=0;
	while ((!archivoA.eof() || dele1 != true) && (!archivoB.eof() || dele2 != true)) {
		if (dele1) {
			r1 = leer_linea(archivoA);
			dele1 = false;
		}
		if (dele2) {
			r2 = leer_linea(archivoB);
			dele2 = false;
		}
		
		
		if (r1 < r2) {
			if (r1 >= aux) {
				
				ayuda1(aux, r1, archivoC, archivoD, band, contC, contD);
				dele1 = true;
			}
			else if (r2 >= aux) {
				
				ayuda1(aux, r2, archivoC, archivoD, band, contC, contD);
				
				dele2 = true;
			}
			else {
				ayuda2(aux, r1, archivoC, archivoD, band, contC, contD);
				
				dele1 = true;
			}
		}
		else {
			if (r2 >= aux) {
				ayuda1(aux, r2, archivoC, archivoD, band, contC, contD);
				dele2 = true;
			}
			else if (r1 >= aux) {
				ayuda1(aux, r1, archivoC, archivoD, band, contC, contD);
				dele1 = true;
			}
			else {
				ayuda2(aux, r2, archivoC, archivoD, band, contC, contD);
				
				dele2 = true;
			}
		}
	} 
	if (dele1 && archivoA.eof()) {
		ayuda3(aux, r2, archivoB, archivoC, archivoD, band, contC, contD);
	}
		
		if (dele2 && archivoB.eof()) {
		ayuda3(aux, r1, archivoA, archivoC, archivoD, band, contC, contD);
	}
		

	
	archivoA.close();
	archivoB.close();
	archivoC.close();
	archivoD.close();
	
}


void Ordenamiento::ayuda1(int& aux, int r, ofstream& fc, ofstream& fd, bool band,int &contc, int& contd)
{
	aux = r;
	if (band == true) {
		escribir_en_archivo(fc, contc, r);
	}
	else {
		escribir_en_archivo(fd, contd, r);
	}
}

void Ordenamiento::ayuda2(int& aux, int r, ofstream& fc, ofstream& fd, bool& band, int& contc, int& contd)
{
	
	aux = r;
	if (band == true) {
		escribir_en_archivo(fd, contd, r);
		band = false;
	}
	else {
		escribir_en_archivo(fc, contc, r);
		band = true;
	}
}

void Ordenamiento::escribir_en_archivo(ofstream& file, int& cont,int r)
{
	if (cont == 0) {
		file<< r;
	}
	else {
		file << endl;
		file << r;
	}
	cont++;
}

int Ordenamiento::leer_linea(ifstream &archivo)
{
	mystring str;
	string linea;
	if (!archivo_vacio(archivo)) {
		
		getline(archivo, linea);
		int r;
		r =str.stoi(linea);
		return r;
	}
	return 0;
	
}

void Ordenamiento::ayuda3(int& aux, int r, ifstream& f, ofstream& fc, ofstream& fd, bool &band, int& contC, int& contD){
	if (r >= aux)
		ayuda1(aux, r, fc, fd, band,contC,contD);
	else
		ayuda2(aux, r, fc, fd, band, contC, contD);
	while (!f.eof()) {
		r = leer_linea(f); 
		if (r >= aux)
			ayuda1(aux, r, fc, fd, band, contC, contD);
		else
			ayuda2(aux, r, fc, fd, band, contC, contD);
	}
	
}

void Ordenamiento::imprimir_archivo(string f)
{
	string linea;
	ifstream archivo(f.c_str(), ios::in);
	if (archivo_vacio(archivo)) {
		cout <<"vacio"<< endl;
	}
	else {
		while (!archivo.eof()) {
			getline(archivo, linea);
			cout << "- " << linea << "-\t";
			
		}
		cout << endl;

	}
	
	archivo.close();
}

int Ordenamiento::contar_lineas(string f)
{
	string linea;
	int cont = 0;
	ifstream archivo(f.c_str(), ios::in);
	while (!archivo.eof()) {
		getline(archivo, linea);
		cont++;
	}
	archivo.close();
	return cont;
}
