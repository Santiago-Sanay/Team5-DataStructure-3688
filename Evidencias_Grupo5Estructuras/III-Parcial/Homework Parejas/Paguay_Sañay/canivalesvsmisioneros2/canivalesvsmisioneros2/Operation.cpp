/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
#include "Operation.h"

bool Operation::ganar(Juego juego,int n)
{
	
	if (juego.get_c_der() == n && juego.get_m_der() == n && juego.get_lado() == false) {
		
		return true;
	}
	
	return false;
}

void Operation::jugar(Juego juego,int n, int& op)
{
	imprimir_juego(juego);
	op++;
	
	if (ganar(juego,n)) {
		
		
		return;
	}
	else {
		if (juego.get_m_der() == n && juego.get_c_der() == 1) {
			int cont = 0;
			while (!ganar(juego, n)) {
				if (cont == 0) {
					cout << 3 << endl;
					realizar_mov(3, juego);
					cont = 1;
				}
				else {
					cout << 4 << endl;
					realizar_mov(4, juego);
					cont = 0;
				}
				if (!ganar(juego, n)) {
					op++;
					imprimir_juego(juego);
				}
				else {

				}
				
			}
			jugar(juego, n, op);
		}
		else {
		regreso:
			int u = 1 + (rand() % 5);

			if (evaluar_mov(u, juego, n)) {
				cout << u << endl;
				realizar_mov(u, juego);
				jugar(juego, n, op);
			}
			else {
				goto regreso;
			}
		}
		

	}
}

void Operation::imprimir_juego(Juego juego)
{
	if (juego.get_lado()) {
		cout << "\tMisioneros: " << juego.get_m_izq() << " Canivales: " << juego.get_c_izq() << "<->\t\tMisioneros: " << juego.get_m_der() << " Canivales: " << juego.get_c_der() << endl;
	}
	else {
		cout << "\tMisioneros: " << juego.get_m_izq() << " Canivales: " << juego.get_c_izq() << "\t\t<->Misioneros: " << juego.get_m_der() << " Canivales: " << juego.get_c_der() << endl;
	}
	
	
}

bool Operation::evaluar_mov(int num, Juego juego,int n)
{
	int md = juego.get_m_der();
	int cd = juego.get_c_der();
	int mi = juego.get_m_izq();
	int ci = juego.get_c_izq();
	if (num == 1 &&juego.get_lado()==true) {
		mi--;
		ci--;
		md++;
		cd++;
		if (evaluate(mi, ci, md, cd,n)) {
			return true;
		}
		else {
			return false;
		}

	}
	if (num == 1 && juego.get_lado() == false) {
		mi++;
		ci++;
		md--;
		cd--;
		return evaluate(mi, ci, md, cd, n);


	}
	if (num == 2 && juego.get_lado() == true) {
		mi--;
		
		md++;
		
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 2 && juego.get_lado() == false) {
		mi++;
		
		md--;
		return evaluate(mi, ci, md, cd, n);


	}
	if (num == 3 && juego.get_lado() == true) {
		
		ci--;
		
		cd++;
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 3 && juego.get_lado() == false) {
		
		ci++;
		
		cd--;
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 4 && juego.get_lado() == true) {

		ci=ci-2;

		cd=cd+2;
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 4 && juego.get_lado() == false) {

		ci = ci + 2;

		cd = cd - 2;
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 5 && juego.get_lado() == true) {

		mi = mi- 2;

		md = md + 2;
		return evaluate(mi, ci, md, cd, n);

	}
	if (num == 5 && juego.get_lado() == false) {

		mi = mi + 2;

		md = md - 2;
		return evaluate(mi, ci, md, cd, n);

	}
}

bool Operation::evaluate(int mi, int ci, int md, int cd,int n)
{
	if (ci > mi && mi > 0) {
		return false;
	}
	if (cd > md && md > 0) {
		return false;
	}
	if (ci > n || mi > n || md > n || cd > n) {
		return false;
	}
	return true;
}

void Operation::realizar_mov(int op, Juego& juego)
{
	int md = juego.get_m_der();
	int cd = juego.get_c_der();
	int mi = juego.get_m_izq();
	int ci = juego.get_c_izq();
	
	if (op == 1 && juego.get_lado() == true) {
		mi--;
		ci--;
		md++;
		cd++;
		

	}
	if (op == 1 && juego.get_lado() == false) {
		mi++;
		ci++;
		md--;
		cd--;
		


	}
	if (op == 2 && juego.get_lado() == true) {
		mi--;

		md++;


	}
	if (op == 2 && juego.get_lado() == false) {
		mi++;

		md--;
		

	}
	if (op == 3 && juego.get_lado() == true) {

		ci--;

		cd++;
		

	}
	if (op == 3 && juego.get_lado() == false) {

		ci++;

		cd--;
		

	}
	if (op== 4 && juego.get_lado() == true) {

		ci = ci - 2;

		cd = cd + 2;
		
	}
	if (op == 4 && juego.get_lado() == false) {

		ci = ci + 2;

		cd = cd - 2;
		

	}
	if (op == 5 && juego.get_lado() == true) {

		mi = mi - 2;

		md = md + 2;
		

	}
	if (op == 5 && juego.get_lado() == false) {

		mi = mi + 2;

		md = md - 2;
		

	}
	juego.set_lado(!juego.get_lado());
	juego.set_m_izq(mi);
	juego.set_c_izq(ci);
	juego.set_m_der(md);
	juego.set_c_der(cd);
	
}
