#pragma once
class Juego
{
private:
	int m_izq;
	int m_der;
	int c_izq;
	int c_der;
	bool lado;
public:
	Juego(int n);
	int get_m_izq();
	int get_c_izq();
	void set_m_izq(int new_m_izq);
	void set_c_izq(int new_c_izq);
	int get_m_der();
	int get_c_der();
	void set_m_der(int new_m_der);
	void set_c_der(int new_c_der);
	bool get_lado();
	void set_lado(bool new_lado);

};

