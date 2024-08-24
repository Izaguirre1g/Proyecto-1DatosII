#include <iostream>

#include "MPointer.cpp"
#include "MPointerGC.cpp"
//#include "MPointer.h"
using namespace std;

//class MPointer;

int main() {
    MPointerGC& gc = MPointerGC::getInstance();

    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    MPointer<int> myPtr3 = MPointer<int>::New();
    MPointer<int> myPtr4 = MPointer<int>::New();
    MPointer<int> myPtr5 = MPointer<int>::New();
    MPointer<int> myPtr6 = MPointer<int>::New();
    *myPtr = 5;
    *myPtr2=78;
    *myPtr3=7;
    *myPtr4=8;
    *myPtr5=780;
    *myPtr6=898;


    //myPtr2 = myPtr;


    if (myPtr == myPtr2) {
        gc.registrar(myPtr.obtenerPtr());
        gc.registrar(myPtr2.obtenerPtr());
        gc.registrar(myPtr3.obtenerPtr());
        gc.registrar(myPtr4.obtenerPtr());
        gc.registrar(myPtr5.obtenerPtr());
        gc.registrar(myPtr6.obtenerPtr());

        gc.mostrarNodo();
    } else {
        std::cout << "Los punteros son diferentes." << std::endl;
        *myPtr = 6;
    }

    return 0;






    /*myPtr=5;
    cout << "Sobrecargado *: " <<*myPtr<<endl;
    int valor = *myPtr;
    cout << "Sobrecargado &: "<< valor<<endl;*/


}
