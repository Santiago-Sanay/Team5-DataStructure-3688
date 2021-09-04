/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROGRAMA DE COLAS
*FECHA DE CREACION : 05 DE JULIO DE 2021
*FECHA DE MODIFICACION: 11 DE JULIO 2021
*/

#include <iostream>
#include "Queue.h"
#include "Client.h"
#include "Operation.h"
#include "Utils.h"
#include <thread>
#include <Windows.h>
#include "Marquee1.h"

void marquee_limit(std::string text, size_t limit) {
    bool ciclo = true;
    while (ciclo)
    {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        //poner titulo en la consola
        
        SetConsoleTitleA(text.substr(0, limit).c_str());
        if (GetAsyncKeyState(VK_RETURN)) {
            ciclo = false;
            break;
        }

    }
}

using namespace std;
int main()
{    
    std::string test = "UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
    std::thread t2(marquee_limit, test, test.size());
    Queue<Client> queue;
    Operation op;
    Utils  utils;
    int num;
    Marquee mark1("THEO YULI JUNIOR ALEX SANTIAGO ");
    mark1.transicion();
    cout << endl;
    cout << "Ingrese el numero de clientes: ";
    num = utils.validate_number(2);
    cout << endl;
    cout << "\n";
    queue = op.generate_table(num);
    op.mostrar(queue);    
    op.calculate_summary(queue);
    t2.join();
}

