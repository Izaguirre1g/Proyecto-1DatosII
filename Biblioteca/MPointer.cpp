#include "MPointerGC.h"

template <typename T>
MPointer<T>::MPointer() : dato_tipo_T(new T) {
    id = MPointerGC::getInstance().registrar(dato_tipo_T);
}

template <typename T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const T& valor) {
    *dato_tipo_T = valor;
    return *this;
}

template <typename T>
MPointer<T>::~MPointer() {
    MPointerGC::getInstance().decrementarContador(id);
    delete dato_tipo_T; // Liberar la memoria
}

template <typename T>
T& MPointer<T>::operator*() {
    return *dato_tipo_T;
}

template <typename T>
T* MPointer<T>::operator&() {
    return dato_tipo_T;
}

template <typename T>
MPointer<T>::MPointer(const MPointer<T>& repetido) {
    dato_tipo_T = repetido.dato_tipo_T;
    id = repetido.id;
    MPointerGC::getInstance().incrementarContador(id);
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& copia) {
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

template <typename T>
bool MPointer<T>::operator==(const MPointer<T>& tipo_dato) const {
    return dato_tipo_T == tipo_dato.dato_tipo_T;
}

template <typename T>
bool MPointer<T>::operator!=(const MPointer<T>& tipo_dato) const {
    return !(*this == tipo_dato);
}

template <typename T>
MPointer<T>::MPointer(T valor) : dato_tipo_T(new T(valor)) {
    id = MPointerGC::getInstance().registrar(dato_tipo_T);
}


/*Referencias
 *
 * https://conclase.net/c/curso/cap22
 * https://www.youtube.com/watch?v=cPcDuIUqEO4&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=108
 * https://gist.github.com/AlmuHS/c23a10d4531f33b0b3d015773e2246e5
 * https://www.geeksforgeeks.org/multithreading-in-cpp/
 *
 * */