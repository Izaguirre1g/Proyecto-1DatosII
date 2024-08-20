#include <cstring>
#include <thread>
using namespace std;

// Clase Singleton
class MPointerGC {
    struct Nodo {
        void* ptr;  //Puntero genérico
        int id;     //Identificador
        Nodo* siguiente;

        //Creación de nodos
        Nodo(void* p, int i) : ptr(p), id(i), siguiente(nullptr) {}
    };

    Nodo* inicial;
    Nodo* final;

    static int contadorId;  //Contador estático para generar IDs únicos

    //Constructor privado para evitar instanciación directa
    MPointerGC() : inicial(nullptr), final(nullptr) {}

    //Destructor privado para manejar la limpieza
    ~MPointerGC() {
        while (inicial != nullptr) {
            Nodo* tmp = inicial;
            inicial = inicial->siguiente;
            delete tmp;
        }
    }

public:
    //Método estático para acceder a la instancia única de la clase
    static MPointerGC& getInstance() {
        static MPointerGC instance;
        return instance;
    }

    //Elimina constructores de copia y operadores de asignación
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;

    //Método para registrar un nuevo MPointer en la lista
    int registrar(void* ptr) {
        int nuevoId = ++contadorId;  // Genera un nuevo ID
        Nodo* nuevo_nodo = new Nodo(ptr, nuevoId);
        if (inicial == nullptr) {
            inicial = nuevo_nodo;
            final = nuevo_nodo;
        } else {
            final->siguiente = nuevo_nodo;
            final = final->siguiente;
        }
        return nuevoId;  // Devuelve el ID generado
    }

    //Método para eliminar un nodo de la lista
    void eliminar(Nodo* posicion) {
        if (inicial == nullptr || posicion == nullptr) return; // Verificar si la lista o el nodo son nulos

        if (inicial == posicion) {  // Si el nodo a eliminar es el primero
            Nodo* referencia_nodo = inicial;
            inicial = inicial->siguiente;
            delete referencia_nodo;
            if (inicial == nullptr) {  // Si la lista quedó vacía
                final = nullptr;
            }
            return;
        }

        Nodo* actual = inicial;
        while (actual->siguiente != posicion && actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            Nodo* referencia_nodo = actual->siguiente;
            actual->siguiente = posicion->siguiente;
            if (referencia_nodo == final) { // Si el nodo a eliminar es el último
                final = actual;
            }
            delete referencia_nodo;
        }
    }
};

//Inicializa el contador estático
int MPointerGC::contadorId = 0;

