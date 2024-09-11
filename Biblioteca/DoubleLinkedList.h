//
// Created by Jose on 11/09/2024.
//
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "MPointer.h"
#include <iostream>

class Node {
public:
    int value;                       // Dato almacenado en el nodo.
    MPointer<Node> next = nullptr;   // Puntero MPointer que apunta al siguiente nodo.
    MPointer<Node> prev = nullptr;   // Puntero MPointer que apunta al nodo anterior.

    Node() = default;                // Constructor por defecto.
    Node(int val) : value(val) {}    // Constructor para inicializar el valor del nodo.
};

class DoubleLinkedList {
public:
    // Método para agregar un nuevo nodo al final de la lista.
    void add(int value) {
        try {
            MPointer<Node> newNode = MPointer<Node>::New(); // Crear un nuevo nodo usando MPointer.
            newNode->value = value;                         // Asignar el valor al nuevo nodo.

            if (first == nullptr) { // Si la lista está vacía, el nuevo nodo es el primer nodo.
                first = newNode;
                last = newNode;
            } else {
                // Enlazar el nuevo nodo al final de la lista.
                newNode->prev = last;
                last->next = newNode;
                last = newNode;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error al agregar un nuevo nodo: " << e.what() << std::endl;
        }
    }

    // Método para imprimir la lista.
    void printList() const {
        MPointer<Node> current = first; // Comenzar desde el primer nodo.
        while (current != nullptr) {
            std::cout << current->value << " "; // Imprimir el valor del nodo.
            current = current->next;            // Avanzar al siguiente nodo.
        }
        std::cout << std::endl;
    }

    // Método para registrar los valores de los nodos en MPointerGC.
    void registrarValores() const {
        MPointer<Node> current = first; // Comenzar desde el primer nodo.
        while (current != nullptr) {
            MPointerGC::getInstance().registrar(&(current->value)); // Registrar el valor del nodo.
            current = current->next;            // Avanzar al siguiente nodo.
        }
    }

private:
    MPointer<Node> first = nullptr;   // Puntero MPointer al primer nodo de la lista.
    MPointer<Node> last = nullptr;    // Puntero MPointer al último nodo de la lista.
};

#endif // DOUBLELINKEDLIST_H
