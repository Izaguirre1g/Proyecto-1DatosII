#ifndef MPOINTER_H
#define MPOINTER_H

#include "MPointerGC.h" // Asegúrate de incluir la definición de MPointerGC

template <typename T>
class MPointer {
public:
    T* dato_tipo_T;
    int id; // ID para identificar la instancia en MPointerGC

    // Constructor privado
    MPointer(T* ptr);

public:
    // Método estático para crear una nueva instancia de MPointer
    static MPointer<T> New();

    // Sobrecarga del operador de asignación para aceptar un valor del tipo T
    MPointer<T>& operator=(const T& valor);

    // Sobrecarga del operador de asignación para copiar otro MPointer
    MPointer<T>& operator=(const MPointer<T>& otro);

    // Destructor
    ~MPointer();

    // Sobrecarga del operador de desreferenciación (*)
    T& operator*();

    // Sobrecarga del operador de acceso a miembros (->)
    T* operator->();

    // Sobrecarga del operador == para comparar objetos MPointer
    bool operator==(const MPointer<T>& tipo_dato) const;

    // Sobrecarga del operador != para comparar objetos MPointer
    bool operator!=(const MPointer<T>& tipo_dato) const;
};

//Implementación de la plantilla

template <typename T>
MPointer<T>::MPointer(T* ptr) : dato_tipo_T(ptr) {
    // Registra la dirección de la nueva instancia en MPointerGC
    id = MPointerGC::getInstance().registrar(ptr); // Obtener el ID de MPointerGC
}

template <typename T>
MPointer<T> MPointer<T>::New() {
    //Crea una nueva instancia de MPointer
    T* newPtr = new T();
    return MPointer<T>(newPtr);
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const T& valor) {
    if (dato_tipo_T) {
        *dato_tipo_T = valor;
    }
    return *this;
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& otro) {
    if (this != &otro) { // Evitar auto-asignación
        //Disminuir el contador de referencias del puntero actual
        MPointerGC::getInstance().decrementarContador(id);

        // Copiar la dirección y ID del otro MPointer
        dato_tipo_T = otro.dato_tipo_T;
        id = otro.id;

        // Aumentar el contador de referencias del nuevo puntero
        MPointerGC::getInstance().incrementarContador(id);
    }
    return *this;
}

template <typename T>
MPointer<T>::~MPointer() {
    //Se encarga de disminuir las referencias
    MPointerGC::getInstance().decrementarContador(id);
    // No se realiza liberación de memoria aquí
}

template <typename T>
T& MPointer<T>::operator*() {
    return *dato_tipo_T;
}

template <typename T>
T* MPointer<T>::operator->() {
    return dato_tipo_T;
}

template <typename T>
bool MPointer<T>::operator==(const MPointer<T>& tipo_dato) const {
    return dato_tipo_T == tipo_dato.dato_tipo_T;
}

template <typename T>
bool MPointer<T>::operator!=(const MPointer<T>& tipo_dato) const {
    return !(*this == tipo_dato);
}

// Colocar las instanciaciones de plantilla necesarias
// template class MPointer<int>;

#endif // MPOINTER_H
