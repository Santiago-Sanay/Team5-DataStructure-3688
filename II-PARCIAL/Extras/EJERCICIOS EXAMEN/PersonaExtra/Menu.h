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
*FECHA DE CREACION : 15 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 25 DE JUNIO 2021
*/
#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "MenuOption.h"
#include <conio.h>
#include <iostream>

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESCAPE = 27;


class Menu
{
public:
    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu() = default;

    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu(std::vector<MenuOption>);
    
    /**
     * @brief desplazar por coordenada
     * 
     */
    void navigation();
    
    /**
     * @brief mostrar en pantalla
     * 
     */
    void display(size_t);

private:
    std::vector<MenuOption> menu_option_;
    HANDLE console_;
};




