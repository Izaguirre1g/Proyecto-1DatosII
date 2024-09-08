#include <iostream>
using namespace std;

// Incluye el encabezado de MPointer
#include "MPointer.h"

int main() {
    MPointer<int> myPtr = MPointer<int>::New(); // Crear un MPointer de tipo int
    MPointer<int> myPtr2 = MPointer<int>::New(); // Crear otro MPointer de tipo int
    MPointer<bool> myPtr3 = MPointer<bool>::New(); // Crear un MPointer de tipo bool

    myPtr3 = true;
    myPtr = 5; // Asignar un valor a myPtr
    myPtr=myPtr2;
    // Comparar si las direcciones de memoria son iguales
    if (&*myPtr == &*myPtr2) {
        cout << "myPtr y myPtr2 apuntan a la misma dirección de memoria" << endl;
    } else {
        cout << "myPtr y myPtr2 no apuntan a la misma dirección de memoria" << endl;
    }

    if ((void*)&*myPtr3 == (void*)&*myPtr) {
        cout << "myPtr y myPtr3 apuntan a la misma dirección de memoria" << endl;
    } else {
        cout << "myPtr y myPtr3 no apuntan a la misma dirección de memoria" << endl;
    }

    return 0;
}

