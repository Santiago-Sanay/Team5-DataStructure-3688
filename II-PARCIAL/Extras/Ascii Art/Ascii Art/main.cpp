#include <iostream>
#include "ascii_art.h"

int main()
{
      //48 #Selecciona RGB de primer plano (foreground color).
      //38 #Selecciona el color de fondo RGB(background coloR).
      ascii_art art("../img/logo-espe-2.png", 48); //Ubicacion de la imagen.
      //art.gray_scale();
      art.console_font_size(2,2);  //tamaño de cada caracter en pixeles.
      //art.resize(50,50); //redimensiona la imagen.
      art.show_ascii_art(); //imrpime la imagen en ascii en la consola
      art.ascii_file("ascii_art.txt"); // Guarga el ascii art en un archivo.
}
