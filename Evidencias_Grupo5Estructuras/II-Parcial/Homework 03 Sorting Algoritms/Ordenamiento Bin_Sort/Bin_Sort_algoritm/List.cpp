/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/
#include "List.h"
using namespace std;
void List::add(int a, int b)
{
	Nodo* t = head;
	
	Nodo* temp = new Nodo();
	
	temp->set_bin_no(a);
	
	temp->set_data(b);
	if (t == nullptr)
	{
		
		temp->set_next(nullptr);
		head = temp;
	}
	else
	{
		while (t->get_next() != nullptr)
		{
			t = t->get_next();
		}
		temp->set_next(t->get_next());
		t->set_next(temp);
	}
	return;
}

void List::sort()
{
	int a_data, a_bin_no, b_data, b_bin_no;
	int pos = 1, i;
	Nodo* t = head;
	Nodo* p;
	while (1)
	{
		p = head;
		a_bin_no = t->get_bin_no();
		a_data = t->get_data();
		t = t->get_next();
		if (t == nullptr)
			break;
		b_bin_no = t->get_bin_no();
		b_data = t->get_data();
		if ((b_bin_no < a_bin_no) || (b_data < a_data))
		{
			i = pos;
			while (p->get_bin_no() < b_bin_no)
			{
				p = p->get_next();
				i--;
			}
			while ((p->get_data() < b_data) && (p->get_bin_no() == b_bin_no))
			{
				p = p->get_next();
				i--;
			}
			while (i--)
			{
				a_bin_no = p->get_bin_no();
				a_data = p->get_data();
				p->set_bin_no(b_bin_no);
				p->set_data(b_data);
				b_bin_no = a_bin_no;
				b_data = a_data;
				p = p->get_next();
			}
			p->set_bin_no( b_bin_no);
			p->set_data(b_data);
		}
		pos++;
	}
}

void List::print()
{
	Nodo* t = head;
	while (t != nullptr)
	{
		cout << t->get_bin_no() << ":" << t->get_data() << "  ";
		t = t->get_next();
	}
}
