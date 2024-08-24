#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

class MPointerGC {
    struct Item {
        int id;      // ID del elemento
        int* ptr;    // Puntero al valor
        Item* next;  // Puntero al siguiente elemento de la lista

        Item(int i, int* p) : id(i), ptr(p), next(nullptr) {}
    };

    struct Nodo {
        Item* head;  // Cabeza de la lista de elementos
        Nodo* siguiente;

        Nodo(int* p, int i) : head(new Item(i, p)), siguiente(nullptr) {}
    };

    Nodo* inicial;
    Nodo* final;
    int siguiente_id;
    atomic<bool> activo;

    MPointerGC() : inicial(nullptr), final(nullptr), siguiente_id(1), activo(true) {}

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
        if (ptr == nullptr) {
            cerr << "Error: Puntero nulo pasado a registrar()" << endl;
            return -1;
        }

        int id = siguiente_id++;
        if (final == nullptr || final->head == nullptr || final->head->next != nullptr) {
            Nodo* nuevo_nodo = new Nodo(ptr, id);
            if (inicial == nullptr) {
                inicial = nuevo_nodo;
                final = nuevo_nodo;
            } else {
                final->siguiente = nuevo_nodo;
                final = final->siguiente;
            }
        } else {
            Item* newItem = new Item(id, ptr);
            Item* temp = final->head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
        return id;
    }

    void operator()(int id) {
        Nodo* actual = inicial;
        while (actual != nullptr) {
            Item* temp = actual->head;
            while (temp != nullptr) {
                if (temp->id == id) {
                    cout << "Elemento con ID " << id << " encontrado, valor: " << *(temp->ptr) << ", direccion de memoria: " << temp->ptr <<endl;
                    return;
                }
                temp = temp->next;
            }
            actual = actual->siguiente;
        }
        cout << "Elemento con ID " << id << " no encontrado." << endl;
    }

    void mostrarNodo() {
        Nodo* actual = inicial;
        if (actual == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }

        while (actual != nullptr) {
            Item* temp = actual->head;
            while (temp != nullptr) {
                if (temp->ptr != nullptr) {
                    cout << "Elemento con ID: " << temp->id<< ", Valor almacenado: " << *(temp->ptr)<< ", Direccion de memoria: " << temp->ptr << endl;
                } else {
                    cout << "Elemento con ID: " << temp->id << " tiene un puntero nulo." << endl;
                }
                temp = temp->next;
            }
            actual = actual->siguiente;
        }
    }

    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;
};