#include <typeinfo>
#include "MPointerGC.cpp"
using namespace std;

template <typename T>//Se declara a la clase como una plantilla para establecer tipos de datos
class MPointer {
private:
    T* dato_tipo_T; // Puntero al dato
    int id;         // ID único en MPointerGC

    MPointer() : dato_tipo_T(new T) {
        id = MPointerGC::getInstance().registrar(dato_tipo_T);
    }

public:
    static MPointer<T> New() {
        return MPointer<T>();
    }

    ~MPointer() {
        MPointerGC::getInstance().decrementarContador(id);
    }

    // Sobrecarga del operador de dereferenciación
    T& operator*() {
        return *dato_tipo_T;
    }

    // Sobrecarga del operador de dirección
    T* operator&() {
        return dato_tipo_T;
    }

    // Constructor de copia para manejar shallow copy
    MPointer(const MPointer<T>& repetido) {
        dato_tipo_T = repetido.dato_tipo_T;
        id = repetido.id;
        MPointerGC::getInstance().incrementarContador(id);
    }

    // Operador de asignación para manejar shallow copy
    MPointer<T>& operator=(const MPointer<T>& copia) {
        if (this == &copia) return *this;

        // Decrementar el contador de la instancia actual
        MPointerGC::getInstance().decrementarContador(id);

        // Copiar datos de la otra instancia
        dato_tipo_T = copia.dato_tipo_T;
        id = copia.id;

        // Incrementar el contador de la nueva instancia
        MPointerGC::getInstance().incrementarContador(id);

        return *this;
    }

    // Sobrecarga del operador == para comparar objetos MPointer
    bool operator==(const MPointer<T>& tipo_dato) const {
        return dato_tipo_T == tipo_dato.dato_tipo_T;
    }

    // Sobrecarga del operador != para comparar objetos MPointer
    bool operator!=(const MPointer<T>& tipo_dato) const {
        return !(*this == tipo_dato);
    }
};


/*Referencias
 *
 * https://conclase.net/c/curso/cap22
 * https://www.youtube.com/watch?v=cPcDuIUqEO4&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=108
 * https://gist.github.com/AlmuHS/c23a10d4531f33b0b3d015773e2246e5
 * https://www.geeksforgeeks.org/multithreading-in-cpp/
 *
 * */