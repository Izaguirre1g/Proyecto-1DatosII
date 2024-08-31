#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <atomic>
#include <mutex>
#include <thread>

using namespace std;

class MPointerGC {
private:
    struct Nodo {
        int id; // ID del elemento
        int* ptr; // Puntero al valor
        int referencia_contador; // Contador de referencias
        Nodo* siguiente; // Puntero al siguiente nodo

        Nodo(int i, int* p);
    };

    Nodo* cabeza; // Cabeza de la lista enlazada
    int siguiente_id; // Para autogenerar IDs
    std::atomic<bool> activo;
    std::mutex mtx;
    std::thread garbageCollectorThread;

    MPointerGC();
    ~MPointerGC();

    void ejecutar();
    void detener();

public:
    static MPointerGC& getInstance();

    int registrar(int* ptr);
    void incrementarContador(int id);
    void decrementarContador(int id);
    void mostrarNodos();

    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;
};

#endif // MPOINTERGC_H

