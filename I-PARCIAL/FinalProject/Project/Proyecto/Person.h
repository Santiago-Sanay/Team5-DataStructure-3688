/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 09 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  09 DE JUNIO DE 2021
*/

#pragma once
#include <iostream> 

class Person
{

public:
    Person() = default;
    Person(std::string, std::string, std::string, std::string, std::string, std::string);
    void set_name(std::string);
    void set_last_name(std::string);
    void set_addres(std::string);
    void set_number(std::string);
    void set_email(std::string);
    void set_id(std::string);
    void set_age(int);
    void set_date_of_birth(std::string);
    std::string get_name();
    std::string get_last_name();
    std::string get_addres();
    std::string get_number();
    std::string get_email();
    std::string get_id();
    std::string get_date_of_birth();
    int get_age();

private:
    std::string id_;
    std::string name_;
    std::string last_name_;
    std::string date_of_birth_;
    std::string email_;
    std::string addres_;
    std::string number_phone_;
    int age_ = 0;
};

