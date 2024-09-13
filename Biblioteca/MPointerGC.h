#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class MPointerGC {
private:
    struct Nodo {
        int id;
        void* ptr; // Usar void* para almacenar cualquier tipo de puntero
        int referencia_contador;
        Nodo* siguiente;
        Nodo(int id, void* ptr, int ref_count) : id(id), ptr(ptr), referencia_contador(ref_count), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    int siguiente_id;
    bool activo;
    mutex mtx;
    thread garbageCollectorThread;

    MPointerGC(); // Constructor privado
    void ejecutar();

public:
    ~MPointerGC();
    static MPointerGC& getInstance();//Clase Singleton
    void detener();
    int registrar(void* ptr);
    void incrementarContador(int id);
    void decrementarContador(int id);
    void mostrarNodos();
};

#endif // MPOINTERGC_H
