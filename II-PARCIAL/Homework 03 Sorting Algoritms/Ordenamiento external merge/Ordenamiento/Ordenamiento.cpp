#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Operation.h"
#include "Vector.h"


int main(void) {

    Vector<int> vector;
    Operation<int> op;
    int cantidad = 10;
    vector.set_vector(op.segment(cantidad));
    op.add(vector, cantidad);
    op.print(vector, cantidad, [](int value) {
        cout << value << endl;
        });
    cout << "ordenado" << endl;
    vector = op.selectionSort(vector, cantidad);
    op.print(vector, cantidad, [](int value) {
        cout << value << endl;
        });
}