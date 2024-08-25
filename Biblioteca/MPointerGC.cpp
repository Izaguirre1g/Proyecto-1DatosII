#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
using namespace std;

struct Nodo {
    int id;        // ID del elemento
    int* ptr;      // Puntero al valor
    int ref_count; // Contador de referencias
    Nodo* siguiente; // Puntero al siguiente elemento de la lista

    Nodo(int i, int* p) : id(i), ptr(p), ref_count(1), siguiente(nullptr) {}
};

class MPointerGC {
    Nodo* inicial; // Cabeza de la lista enlazada
    Nodo* final;   // Final de la lista enlazada
    int siguiente_id; // Para autogenerar IDs
    atomic<bool> activo;
    mutex mtx;

    MPointerGC() : inicial(nullptr), final(nullptr), siguiente_id(1), activo(true) {}

public:
    static MPointerGC& getInstance() {
        static MPointerGC instance;
        return instance;
    }

    // Función para ejecutar el hilo de GC
    void ejecutar(int n) {
        int contador = 0;
        while (activo && contador < n) {
            this_thread::sleep_for(std::chrono::seconds(1));
            cout << "Thread MPointerGC ejecutándose, iteración: " << contador + 1 << endl;
            contador++;
        }
    }

    // Detener el thread de GC
    void detener() {
        activo = false;
    }

    // Registrar un nuevo puntero en la lista
    int registrar(int* ptr) {
        lock_guard<mutex> lock(mtx);
        if (ptr == nullptr) {
            cerr << "Error: Puntero nulo pasado a registrar()" << endl;
            return -1;
        }

        int id = siguiente_id++;
        Nodo* nuevo_nodo = new Nodo(id, ptr);

        // Inserta al final de la lista
        if (inicial == nullptr) {
            inicial = nuevo_nodo;
            final = nuevo_nodo;
        } else {
            final->siguiente = nuevo_nodo;
            final = nuevo_nodo;
        }

        return id;
    }

    // Incrementar el contador de referencias
    void incrementarContador(int id) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = inicial;
        while (actual != nullptr) {
            if (actual->id == id) {
                actual->ref_count++;
                break;
            }
            actual = actual->siguiente;
        }
    }

    // Decrementar el contador de referencias y liberar memoria si es necesario
    void decrementarContador(int id) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = inicial;
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->id == id) {
                actual->ref_count--; // Decrementar el contador de referencias
                if (actual->ref_count == 0) {
                    // Si el contador llega a cero, liberar memoria y eliminar el nodo
                    if (anterior == nullptr) { // Eliminar la cabeza
                        inicial = actual->siguiente;
                        if (inicial == nullptr) {
                            final = nullptr; // Si la lista queda vacía
                        }
                    } else {
                        anterior->siguiente = actual->siguiente;
                        if (anterior->siguiente == nullptr) {
                            final = anterior; // Actualizar el final si se elimina el último nodo
                        }
                    }
                    delete actual->ptr; // Liberar la memoria del puntero
                    delete actual;      // Eliminar el nodo
                }
                break;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    // Mostrar todos los elementos en la lista
    void mostrarItems() {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = inicial;
        if (actual == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }

        while (actual != nullptr) {
            cout << "ID: " << actual->id << ", Valor: " << *(actual->ptr) << ", Referencias: " << actual->ref_count << endl;
            actual = actual->siguiente;
        }
    }

    // Sobrecarga del operador () para mostrar un elemento por ID
    void operator()(int id) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = inicial;
        while (actual != nullptr) {
            if (actual->id == id) {
                cout << "Elemento con ID " << id << " encontrado, valor: " << *(actual->ptr) << ", direccion de memoria: " << actual->ptr << endl;
                return;
            }
            actual = actual->siguiente;
        }
        cout << "Elemento con ID " << id << " no encontrado." << endl;
    }

    // Evitar la copia del singleton
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;
};


