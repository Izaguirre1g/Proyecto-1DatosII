#include <iostream>
#include "ListaNodos.h"
#include "QuickSort.h"
#include "MPointer.h"
#include "MPointerGC.h"
using namespace std;

// Función principal
int main() {
    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    *myPtr = 5;
    myPtr2 = 7; //Deja en myPtr2 una referencia a la misma dirección

    /*ListaNodos lista;
    lista.insertar(*myPtr);
    lista.insertar(*myPtr2);
    lista.insertar(75);
    lista.insertar(8000);
    lista.insertar(780);
    lista.insertar(898);

    cout << "Lista antes de ordenar: ";
    lista.mostrarLista();

    ordenarLista(lista);

    cout << "Lista después de ordenar: ";
    lista.mostrarLista();*/

    MPointerGC::getInstance().mostrarNodos();
    return 0;
}
