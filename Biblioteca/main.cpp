#include "MPointer.h"
#include "MPointerGC.h"
#include <iostream>

using namespace std;

void mostrarEstado() {
    MPointerGC::getInstance().mostrarNodos();
}

int main() {
    MPointerGC& gc = MPointerGC::getInstance();

    // Crear MPointers
    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    MPointer<int> myPtr3 = MPointer<int>::New();
    MPointer<int> myPtr4 = MPointer<int>::New();
    // Asignar valor a myPtr
    *myPtr = 5;
    myPtr3 =78;
    myPtr4=85;

    // Mostrar el estado antes de la asignación
    cout << "Estado antes de myPtr2 = myPtr:" << endl;
    mostrarEstado();

    // Realizar shallow copy
    myPtr2= myPtr;

    // Mostrar el estado después de la asignación
    cout << "Estado despues de myPtr2 = myPtr:" << endl;
    mostrarEstado();

    // Limpiar y finalizar
    gc.detener();

    return 0;
}
