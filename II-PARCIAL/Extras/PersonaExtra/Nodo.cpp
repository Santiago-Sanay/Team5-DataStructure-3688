#include "Nodo.h"

Nodo::Nodo(string nombre, string oficio, string sexo) {
	this->nombre = nombre;
	this->oficio = oficio;
	this->sexo = sexo;
}

int Nodo::cuantosBisNietos(Nodo* p)
{
	return 0;
}


void Nodo::tenerHijo(Nodo* p, Nodo* hijo)
{
}

void Nodo::buscarRelacionados(Nodo* p, string sexo, string oficio)
{
}

void Nodo::verParentesco(Nodo* p, Nodo* q)
{
}


Nodo* Nodo::getPadre() const
{
    return padre;
}

void Nodo::setPadre(Nodo* padre)
{
    this->padre = padre;
}

Nodo* Nodo::getMadre() const
{
    return madre;
}

void Nodo::setMadre(Nodo* madre)
{
    this->madre = madre;
}

Nodo* Nodo::getHermanomenorsig() const
{
    return hermano_menor_sig;
}

void Nodo::setHermanomenorsig(Nodo* hermanomenorsig)
{
    hermano_menor_sig = hermanomenorsig;
}

Nodo* Nodo::getPrimerHijo() const
{
    return primerHijo;
}

void Nodo::setPrimerHijo(Nodo* primerHijo)
{
    this->primerHijo = primerHijo;
}

Nodo* Nodo::getConyuge() const
{
    return conyuge;
}

void Nodo::setConyuge(Nodo* conyuge)
{
    this->conyuge = conyuge;
}


string Nodo::getNombre() const
{
    return nombre;
}

void Nodo::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Nodo::getOficio() const
{
    return oficio;
}

void Nodo::setOficio(string oficio)
{
    this->oficio = oficio;
}

string Nodo::getSexo() const
{
    return sexo;
}

void Nodo::setSexo(string sexo)
{
    this->sexo = sexo;
}


bool Nodo::getViudo() const
{
    if (this == nullptr) {
        return true;
    }
    else {
        return viudo;
    }
}

void Nodo::setViudo(bool viudo)
{
    this->viudo = viudo;
}

