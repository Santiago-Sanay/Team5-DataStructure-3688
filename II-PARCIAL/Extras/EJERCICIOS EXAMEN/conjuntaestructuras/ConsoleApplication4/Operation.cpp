#include "Operation.h"

bool Operation::verificar_en_arreglo(int* arreglo, int numero,int tamanio)
{
    for (int i= 0; i < tamanio; i++) {
        if (*(arreglo + i) == numero) {
            return true;
        }
    }
    return false;
}

/*


*/
