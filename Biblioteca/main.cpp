#include <iostream>

#include "MPointer.cpp"
#include "MPointerGC.cpp"
#include "MPointer.h"
using namespace std;

//class MPointer;

int main() {
    MPointerGC gc;

    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    *myPtr = 5;
    myPtr2 = myPtr;
    if (myPtr == myPtr2){
        cout << "Los punteros son iguales." << endl;
    }else{
        cout << "Los punteros son diferentes." << endl;
        *myPtr=6;
    }

    /*
    int a = 10;
    int *ptr = nullptr;
    ptr =&a;
    cout <<*ptr ;
    /**myPtr=5;
    cout << "Sobrecargado *: " <<*myPtr<<endl;
    int valor = *myPtr;
    cout << "Sobrecargado &: "<< valor<<endl;
    */

}
