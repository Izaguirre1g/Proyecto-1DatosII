#include "MPointer.h"
#include "MPointerGC.h"
#include "DoubleLinkedList.h"
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
    MPointer<int> myPtr5 = MPointer<int>::New();
    myPtr5=755;
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

    /******************************************************************/
    /******************************************************************/
    // Crear una lista doblemente enlazada
    DoubleLinkedList lista;

    // Agregar algunos valores a la lista
    lista.add(10);
    lista.add(20);
    lista.add(30);


    // Imprimir la lista
    cout << "Lista de elementos en MPointer"<<endl;
    lista.printList();



    return 0;

}



