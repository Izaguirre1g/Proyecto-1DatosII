#include <iostream>
using namespace std;

template <typename T>//Se declara a la clase como una plantilla para establecer tipos de datos
class MPointer{
//Atributos
private:
    T dato_tipo_T;
//Métodos
public:
    //Constructor del objeto(clase)
    MPointer() : dato_tipo_T(){}

    //Método que permite realizar la llamada(instancia) de MPointer
    static MPointer<T> New(){
        return MPointer<T>();
    }

    T& operator*(){

    }




    struct SobrecargaOperadorAsterisco{

    };
};