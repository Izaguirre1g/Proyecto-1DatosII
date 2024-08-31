#ifndef LISTANODOS_H
#define LISTANODOS_H

#include "MPointer.h"

class ListaNodos {
private:
    struct Nodo {
        MPointer<int> dato;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(int valor) : dato(MPointer<int>::New()), siguiente(nullptr), anterior(nullptr) {
            *dato = valor;
        }
    };

    Nodo* cabeza;
    Nodo* cola;
    int longitud;

public:
    ListaNodos() : cabeza(nullptr), cola(nullptr), longitud(0) {}

    // Inserta un nodo al final de la lista
    void insertar(int valor);

    // Obtiene el valor del nodo en un índice específico
    int get(int index);

    // Establece el valor del nodo en un índice específico
    void set(int index, int valor);

    // Devuelve el tamaño de la lista
    int size();

    // Muestra la lista recorriéndola desde el principio hasta el final
    void mostrarLista();

    // Destructor para liberar la memoria de los nodos
    ~ListaNodos();
};

#endif // LISTANODOS_H
