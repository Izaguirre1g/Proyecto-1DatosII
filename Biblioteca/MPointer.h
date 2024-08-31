#ifndef MPOINTER_H
#define MPOINTER_H

#include <typeinfo>
#include "MPointerGC.h"

template <typename T>
class MPointer {
private:
    T* dato_tipo_T;
    int id;

    // Constructor privado predeterminado
    MPointer();

public:
    // Método estático para crear una nueva instancia de MPointer
    static MPointer<T> New();

    // Sobrecarga del operador de asignación para aceptar un valor del tipo T
    MPointer<T>& operator=(const T& valor);

    // Destructor
    ~MPointer();

    // Sobrecarga del operador de dereferenciación
    T& operator*();

    // Sobrecarga del operador de dirección
    T* operator&();

    // Constructor de copia
    MPointer(const MPointer<T>& repetido);

    // Operador de asignación para manejar shallow copy
    MPointer<T>& operator=(const MPointer<T>& copia);

    // Sobrecarga del operador == para comparar objetos MPointer
    bool operator==(const MPointer<T>& tipo_dato) const;

    // Sobrecarga del operador != para comparar objetos MPointer
    bool operator!=(const MPointer<T>& tipo_dato) const;

    // Constructor privado que acepta un valor del tipo T
    MPointer(T valor);
};

#include "MPointer.cpp"

#endif // MPOINTER_H
