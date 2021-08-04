/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Nodo Persona
*FECHA DE CREACION : 3 DE AGOSTO DE 2021
*FECHA DE MODIFICACION: 3 DE AGOSTO DE 2021
*/

#pragma once
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

class Nodo
{
private:
	string nombre;
	string oficio;
	string sexo;
	Nodo* padre,* madre;
	Nodo* hermano_menor_sig;
	Nodo* primerHijo;
	Nodo* conyuge;
	int namigos;
	Nodo* amigos;
    bool viudo;

public:
    /**
     * @brief Construct a new Nodo object
     * 
     * @param nombre 
     * @param oficio 
     * @param sexo 
     */
	Nodo(string nombre, string oficio, string sexo);
    /**
     * @brief Contar bisnietos
     * 
     * @param p 
     * @return int 
     */
	int cuantosBisNietos(Nodo* p);
    /**
     * @brief Agregar hijo
     * 
     * @param p 
     * @param hijo 
     */
	void tenerHijo(Nodo* p, Nodo* hijo);
    /**
     * @brief Buscar relacionados
     * 
     * @param p 
     * @param sexo 
     * @param oficio 
     */
	void buscarRelacionados(Nodo* p, string sexo, string oficio);
    /**
     * @brief Ver parentesco
     * 
     * @param p 
     * @param q 
     */
	void verParentesco(Nodo* p, Nodo* q);
    /**
     * @brief Get the Padre object
     * 
     * @return Nodo* 
     */
    Nodo* getPadre() const;
    /**
     * @brief Set the Padre object
     * 
     * @param padre 
     */
    void setPadre(Nodo* padre);
    /**
     * @brief Get the Madre object
     * 
     * @return Nodo* 
     */
    Nodo* getMadre() const;
    /**
     * @brief Set the Madre object
     * 
     * @param madre 
     */
    void setMadre(Nodo* madre);
    /**
     * @brief Get the Hermanomenorsig object
     * 
     * @return Nodo* 
     */
    Nodo* getHermanomenorsig() const;
    /**
     * @brief Set the Hermanomenorsig object
     * 
     * @param hermanomenorsig 
     */
    void setHermanomenorsig(Nodo* hermanomenorsig);
    /**
     * @brief Get the Primer Hijo object
     * 
     * @return Nodo* 
     */
    Nodo* getPrimerHijo() const;
    /**
     * @brief Set the Primer Hijo object
     * 
     * @param primerHijo 
     */
    void setPrimerHijo(Nodo* primerHijo);
    /**
     * @brief Get the Conyuge object
     * 
     * @return Nodo* 
     */
    Nodo* getConyuge() const;
    /**
     * @brief Set the Conyuge object
     * 
     * @param conyuge 
     */
    void setConyuge(Nodo* conyuge);
    /**
     * @brief Get the Nombre object
     * 
     * @return string 
     */
    string getNombre() const;
    /**
     * @brief Set the Nombre object
     * 
     * @param nombre 
     */
    void setNombre(string nombre);
    /**
     * @brief Get the Oficio object
     * 
     * @return string 
     */
    string getOficio() const;
    /**
     * @brief Set the Oficio object
     * 
     * @param oficio 
     */
    void setOficio(string oficio);
    /**
     * @brief Get the Sexo object
     * 
     * @return string 
     */
    string getSexo() const;
    /**
     * @brief Set the Sexo object
     * 
     * @param sexo 
     */
    void setSexo(string sexo);
    /**
     * @brief Get the Viudo object
     * 
     * @return true 
     * @return false 
     */
    bool getViudo() const;
    /**
     * @brief Set the Viudo object
     * 
     * @param viudo 
     */
    void setViudo(bool viudo);

};
