#include "MPointerGC.h"
#include <iostream>

using namespace std;

MPointerGC::Nodo::Nodo(int i, int* p) : id(i), ptr(p), referencia_contador(1), siguiente(nullptr) {}

MPointerGC::MPointerGC() : cabeza(nullptr), siguiente_id(1), activo(true) {
    garbageCollectorThread = thread(&MPointerGC::ejecutar, this); // Inicia el hilo
}

MPointerGC::~MPointerGC() {
    detener();
    if (garbageCollectorThread.joinable()) {
        garbageCollectorThread.join(); // Espera a que el hilo termine
    }
}

MPointerGC& MPointerGC::getInstance() {
    static MPointerGC instance;
    return instance;
}

void MPointerGC::ejecutar() {
    while (activo) {
        this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread MPointerGC ejecutándose" << endl;

        mostrarNodos();
    }
}

void MPointerGC::detener() {
    activo = false;
}

int MPointerGC::registrar(int* ptr) {
    lock_guard<mutex> lock(mtx);
    if (ptr == nullptr) {
        cerr << "Error: Puntero nulo pasado a registrar()" << endl;
        return -1;
    }

    int id = siguiente_id++;
    Nodo* nuevo_nodo = new Nodo(id, ptr);
    nuevo_nodo->siguiente = cabeza;
    cabeza = nuevo_nodo;

    return id;
}

void MPointerGC::incrementarContador(int id) {
    lock_guard<mutex> lock(mtx);
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->id == id) {
            actual->referencia_contador++;
            break;
        }
        actual = actual->siguiente;
    }
}

void MPointerGC::decrementarContador(int id) {
    lock_guard<mutex> lock(mtx);
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->id == id) {
            actual->referencia_contador--;
            if (actual->referencia_contador == 0) {
                // Eliminar el nodo de la lista
                if (anterior == nullptr) {
                    cabeza = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual->ptr;
                delete actual;
            }
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void MPointerGC::mostrarNodos() {
    lock_guard<mutex> lock(mtx);
    Nodo* actual = cabeza;
    if (actual == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    while (actual != nullptr) {
        cout << "ID: " << actual->id << ", Valor: " << *(actual->ptr) << ", Referencias: " << actual->referencia_contador << ", Dirección de memoria: " << &*(actual->ptr) << endl;
        actual = actual->siguiente;
    }
}

