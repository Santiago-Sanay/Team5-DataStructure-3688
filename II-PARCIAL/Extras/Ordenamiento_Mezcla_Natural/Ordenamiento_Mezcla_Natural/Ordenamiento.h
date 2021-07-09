#pragma once}
#include <string>
#include "List.h"
#include <time.h>
#include <ctime>
#include <random>
using namespace std;
class Ordenamiento
{
public:
	void natural_sort(const string);
	void particion_inicial(const string, const string, const string);
	void particion_fusion(string, string, string, string);
	
	List<int> generar_aleatorio(int);

	void grabar_aleatorio(List<int>, string);
	void crear_archivo_aleatorio(string, int);
	bool archivo_vacio(ifstream&);
	


	void particionFusion(string archfa, string archfb, string archfc, string archfd);
	void ayuda1(int& aux, int r, ofstream& fc, ofstream& fd, bool band, int& contc, int& contd);
	void ayuda2(int& aux, int r, ofstream& fc, ofstream& fd, bool &band, int& contc, int& contd);
	void escribir_en_archivo(ofstream&, int&,int );
	int leer_linea(ifstream&);
	void ayuda3(int& aux, int r, ifstream& f, ofstream& fc, ofstream& fd, bool &band,int &contC,int &contD);
	void imprimir_archivo(string f);
	int contar_lineas(string f);
};

