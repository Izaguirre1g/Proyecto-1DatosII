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

    //Sobrecarga el operador: ==, para poder comparar objetos
    bool operator==(const MPointer<T>& objeto_comparacion) const{
        //Compara los objetos si son MPointer o no
        return dato_tipo_T == objeto_comparacion.dato_tipo_T;
    }
    //Sobrecarga el operador: !=, para lograr identificar cuando son isntancias distintas
    bool operator!=(const MPointer<T>& objeto_comparacion)const{
        return !(*this == objeto_comparacion);
    }
};



/*Referencias
 *
 * https://conclase.net/c/curso/cap22
 *
 * */