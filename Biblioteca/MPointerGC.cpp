#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
using namespace std;

class MPointerGC {
    struct Nodo {
        int id;        // ID del elemento
        int* ptr;      // Puntero al valor
        int ref_count; // Contador de referencias
        Nodo* siguiente; // Puntero al siguiente nodo

        Nodo(int i, int* p) : id(i), ptr(p), ref_count(1), siguiente(nullptr) {}
    };

    Nodo* cabeza; // Cabeza de la lista enlazada
    int siguiente_id; // Para autogenerar IDs
    atomic<bool> activo;
    mutex mtx;

    MPointerGC() : cabeza(nullptr), siguiente_id(1), activo(true) {}

public:
    static MPointerGC& getInstance() {
        static MPointerGC instance;
        return instance;
    }

    void ejecutar(int n) {
        int contador = 0;
        while (activo && contador < n) {
            this_thread::sleep_for(std::chrono::seconds(1));
            cout << "Thread MPointerGC ejecutándose, iteración: " << contador + 1 << endl;
            contador++;
        }
    }

    void detener() {
        activo = false;
    }

    int registrar(int* ptr) {
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

    void incrementarContador(int id) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->id == id) {
                actual->ref_count++;
                break;
            }
            actual = actual->siguiente;
        }
    }

    void decrementarContador(int id) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->id == id) {
                actual->ref_count--;
                if (actual->ref_count == 0) {
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

    void mostrarNodos() {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        if (actual == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }

        while (actual != nullptr) {
            cout << "ID: " << actual->id << ", Valor: " << *(actual->ptr) << ", Referencias: " << actual->ref_count << endl;
            actual = actual->siguiente;
        }
    }

    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;
};

