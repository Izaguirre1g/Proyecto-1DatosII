using namespace std;

template <typename T>//Se declara a la clase como una plantilla para establecer tipos de datos
class MPointer{

//Atributos
private:
    T* dato_tipo_T; //Puntero a un dato tipo T de MPointer

    //Constructor del objeto(clase)
    MPointer() : dato_tipo_T(new T){}

//Métodos
public:
    //Método que permite realizar la llamada(instancia) de MPointer
    static MPointer<T> New(){
        return MPointer<T>();
    }

    //Evita los memory leaks (libera la memoria)
    ~MPointer(){
        delete dato_tipo_T;
    }

    //Sobrecarga del operador: * para utilizarlo sin haberlo declarado
    T& operator*(){
        return *dato_tipo_T;
    }

    //Sobrecarga del operador: &
    T& operator&(){
        return *dato_tipo_T;
    }
};



/*Referencias
 *
 * https://conclase.net/c/curso/cap22
 *
 * */