#ifndef MPOINTER_H
#define MPOINTER_H

#include "MPointerGC.h" // Asegúrate de incluir la definición de MPointerGC

template <typename T>
class MPointer {
private:
    T* dato_tipo_T;

    // Constructor privado
    MPointer();

public:
    // Método estático para crear una nueva instancia de MPointer
    static MPointer<T> New();

    // Sobrecarga del operador de asignación para aceptar un valor del tipo T
    MPointer<T>& operator=(const T& valor);

    // Destructor
    ~MPointer();

    // Sobrecarga del operador de desreferenciación (*)
    T& operator*();

    // Sobrecarga del operador de dirección (&)
    T* operator&();

    // Sobrecarga del operador == para comparar objetos MPointer
    bool operator==(const MPointer<T>& tipo_dato) const;

    // Sobrecarga del operador != para comparar objetos MPointer
    bool operator!=(const MPointer<T>& tipo_dato) const;
};

// Implementación de la plantilla

template <typename T>
MPointer<T>::MPointer() : dato_tipo_T(new T) {
    // Registrar la dirección de la nueva instancia en MPointerGC
    //MPointerGC::Registrar(this);
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
    // Desregistrar la dirección de la instancia en MPointerGC
    //MPointerGC::Desregistrar(this);
    // No se realiza liberación de memoria aquí
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
bool MPointer<T>::operator==(const MPointer<T>& tipo_dato) const {
    return dato_tipo_T == tipo_dato.dato_tipo_T;
}

template <typename T>
bool MPointer<T>::operator!=(const MPointer<T>& tipo_dato) const {
    return !(*this == tipo_dato);
}

// Explicitar las instanciaciones de plantilla necesarias
template class MPointer<int>; // Agrega otras instanciaciones si es necesario
// Puedes agregar otras instanciaciones aquí, por ejemplo:
// template class MPointer<double>;
// template class MPointer<std::string>;

#endif // MPOINTER_H
