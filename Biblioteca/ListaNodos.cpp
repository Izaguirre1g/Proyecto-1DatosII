#include "ListaNodos.h"
#include <stdexcept>
#include <iostream>
/*
// Inserta un nodo al final de la lista
void ListaNodos::insertar(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (cola == nullptr) {
        cabeza = cola = nuevoNodo;
    } else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
    longitud++;
}

// Obtiene el valor del nodo en un índice específico
int ListaNodos::get(int index) {
    if (index < 0 || index >= longitud) {
        throw std::out_of_range("Índice fuera de rango");
    }
    Nodo* actual = cabeza;
    for (int i = 0; i < index; i++) {
        actual = actual->siguiente;
    }
    return *(actual->dato);
}

// Establece el valor del nodo en un índice específico
void ListaNodos::set(int index, int valor) {
    if (index < 0 || index >= longitud) {
        throw std::out_of_range("Índice fuera de rango");
    }
    Nodo* actual = cabeza;
    for (int i = 0; i < index; i++) {
        actual = actual->siguiente;
    }
    *(actual->dato) = valor;
}

// Devuelve el tamaño de la lista
int ListaNodos::size() {
    return longitud;
}

// Muestra la lista recorriéndola desde el principio hasta el final
void ListaNodos::mostrarLista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << *(actual->dato) << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Destructor para liberar la memoria de los nodos
ListaNodos::~ListaNodos() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}*/

