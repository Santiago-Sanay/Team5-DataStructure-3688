#include "Ordenamiento.h"
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <cstdio>
#include "mystring.h"
void Ordenamiento::natural_sort(const string f)
{

	bool band = false;
	string f1 = "archivo1.txt";
	string f2 = "archivo4.txt";
	string f3 = "archivo6.txt";
	particion_inicial(f,f2,f3);
	particion_fusion(f2,f3,f,f1);
	/*particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	/*particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);
	particion_fusion(f, f1, f2, f3);
	particion_fusion(f2, f3, f, f1);*/
	
	ifstream archivo1(f1.c_str(), ios::in);
	ifstream archivo3(f3.c_str(), ios::in);
	while (!archivo_vacio(archivo1) || !archivo_vacio(archivo3)) {
		archivo1.close();
		archivo3.close();
		cout << "si entra" << endl;
		if (band == true) {
			particion_fusion(f2, f3, f, f1);
			band = false;
		}
		else {
			particion_fusion(f, f1, f2, f3);
			band = true;
		}
		ifstream archivo1(f1.c_str(), ios::in);
		ifstream archivo3(f3.c_str(), ios::in);
	}
	archivo1.close();
	archivo3.close();

}

void Ordenamiento::particion_inicial(string f, string f2, string f3)
{
	mystring str;
	ifstream archivo(f.c_str(), ios::in);//abrir achivo de lectura f
	ofstream archivo2(f2.c_str());//abrir archivo de escritura f2
	ofstream archivo3(f3.c_str());//abrir archivo de escritura f3
	int r=0, aux=0;
	string linea;
	getline(archivo, linea);//leer r de f
	r = str.stoi(linea);
	archivo2 << r;//escribir r en f2
	bool band = true;// hacer band verdadero
	aux = r; //aux=r
	int i = 0;
	int cont2 = 0, cont3 = 0;
	while (!archivo.eof()) {//inicio while
		i++;
		cout << i <<" "<<r<<endl;
		getline(archivo, linea);//leer r fe f
		r = str.stoi(linea);
		if (r >= aux) {// si r>=aux
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
	/*std::ofstream ofs;
	ofs.open(f, std::ofstream::out | std::ofstream::trunc);
	ofs.close();*/

}

void Ordenamiento::particion_fusion(string fA, string fB, string fC, string fD)
{
	int r1 = 0, r2 = 0, aux = 0;
	mystring str;
	ifstream archivoA(fA.c_str(), ios::in);//abrir achivo de lectura f
	ifstream archivoB(fB.c_str(), ios::in);//abrir achivo de lectura f
	ofstream archivoC(fC.c_str());//abrir archivo de escritura f2
	ofstream archivoD(fD.c_str());//abrir archivo de escritura f3
	bool ban1 = true, ban2 = true, ban3 = true;
	aux = -32768;
	string linea;
	int contC = 0, contD = 0;
	while ((!archivoA.eof() || ban1 == false) && (!archivoB.eof() || ban2 == false)) {
		if (ban1 == true) {
			r1 = leer_linea(archivoA);
			ban1 = false;
		}
		if (ban2 == true) {
			r2 = leer_linea(archivoB);
			ban2 = false;
		}
		if (r2 < r1) {
			if (r1 >= aux) {
				if (ban3 == true) {
					escribir_en_archivo(archivoC, contC, r1);				
				}
				else {
					escribir_en_archivo(archivoD, contD, r1);
				}
				ban1 = true;
				aux = r1;
			}
			else {
				if (ban3 == true) {
					escribir_en_archivo(archivoC, contC, r2);
					ban3 = false;
				}
				else {
					escribir_en_archivo(archivoD, contD, r2);
					ban3 = true;
				}
				ban2 = true;
				aux = -32768;
			}
		}
		else {
			if (r2 >= aux) {
				if (ban3 == true) {
					escribir_en_archivo(archivoC, contC, r2);
				}
				else {
					escribir_en_archivo(archivoD, contD, r2);
				}
				ban2 = true;
				aux = r2;
			}
			else {
				if (ban3 == true) {
					escribir_en_archivo(archivoC, contC, r1);
					ban3 = false;
				}
				else {
					escribir_en_archivo(archivoD, contD, r1);
					contD++;					
					ban3 = true;
				}
				ban1 = true;
				aux = -32768;
			}

		}
	}
	if (ban1 == false) {
		if (ban3 == true) {
			escribir_en_archivo(archivoC, contC, r1);
			while (!archivoA.eof()) {
				getline(archivoA, linea);
				r1 = str.stoi(linea);
				escribir_en_archivo(archivoC, contC, r1);
			}
		}
		else {
			escribir_en_archivo(archivoD, contD, r1);
			while (!archivoA.eof()) {
				getline(archivoA, linea);
				r1 = str.stoi(linea);
				escribir_en_archivo(archivoD, contD, r1);
			}
		}
	}
	if (ban2 == false) {
		if (ban3 == true) {
			escribir_en_archivo(archivoC, contC, r2);
			while (!archivoB.eof()) {
				getline(archivoB, linea);
				r2 = str.stoi(linea);
				escribir_en_archivo(archivoC, contC, r2);	
			}
		}
		else {
			escribir_en_archivo(archivoD, contD, r2);
			
			while (!archivoB.eof()) {
				getline(archivoB, linea);
				escribir_en_archivo(archivoD, contD, r2);
				
			}

		}
	}
	cout << contC << "   " << contD << endl;
	archivoA.close();
	archivoB.close();
	archivoC.close();
	archivoD.close();
	/*std::ofstream ofs;
	ofs.open(fA, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	ofs.open(fB, std::ofstream::out | std::ofstream::trunc);
	ofs.close();*/

}

List<int> Ordenamiento::generar_aleatorio(int num)
{
	srand(time(NULL));
	List<int> numbers;
	int number = 0;

	for (int i = 0; i < num; i++) {
		number = 1 + rand() % (num);
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

void Ordenamiento::crear_archivo_aleatorio(string file, int num)
{ 
	List<int> numbers;
	numbers = generar_aleatorio(num);
	grabar_aleatorio(numbers, file);

}

bool Ordenamiento::archivo_vacio(ifstream &file)
{
	bool state = false;
	state= file.peek() == std::ifstream::traits_type::eof();
	return state;
}

void Ordenamiento::particionFusion(string archfa, string archfb, string archfc, string archfd)
{
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
		r = str.stoi(linea);
		return r;
	}
	return 0;
	
}
