#include "Arbol.h"

Arbol::Arbol(Nodo* raiz)
{
	this->raiz = raiz;
    this->raiz->setViudo(true);
}

int Arbol::cuantosBisNietos(Nodo* p)
{
    Nodo* aux = raiz;
    int cont=0,bisnietos=0;
    while (aux) {
        if (cont >=4 ) {
            bisnietos++;
        }
        cont++;
        aux = aux->getPrimerHijo();
    }
    return bisnietos;
}


void Arbol::buscarRelacionados(Nodo* p, string sexo, string oficio)
{
    Nodo* aux = raiz;
    int cont = 0, bisnietos = 0;
    cout << "\nUsuarios relacionados" << endl;

    while (aux) {
        if (aux->getSexo()==sexo&&aux->getOficio()==oficio) {
            cout << aux->getNombre() << endl;
        }
        aux = aux->getPrimerHijo();
    }
}

void Arbol::verParentesco(Nodo* p, Nodo* q)
{
    Nodo* aux=p;
    int nivel=0;
    bool encontrado=false;
    while (p) {
        nivel++; 
        if (p->getNombre()==q->getNombre()) {
            encontrado = true;
            break;
        }
        p = p->getPrimerHijo();
    }
    if (encontrado == false) {
        nivel = 0;
        while (q) {
            nivel++;
            if (aux->getNombre() == q->getNombre()) {
                break;
            }
            q = q->getPrimerHijo();
        }
    }
    cout << "Nivel de parentesco: "<< nivel-1 << endl;

}

Nodo* Arbol::buscarNombre(string nombre)
{
    Nodo* aux = raiz;
    while (aux) {
        if (aux->getNombre()._Equal(nombre))
            return aux;
        aux = aux->getPrimerHijo();
    }
    return nullptr;
}



Nodo* Arbol::getUltimo()
{
    Nodo* aux = raiz;
    Nodo* aux1 = nullptr;
    while (aux) {
        if (aux != nullptr) {
            aux1 = aux;
        }
        aux = aux->getPrimerHijo();
    }
    if (aux1 == nullptr) {
        return aux;
    }
    else {
        return aux1;
    }
}
