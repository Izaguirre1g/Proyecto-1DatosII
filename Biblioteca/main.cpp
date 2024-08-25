#include <iostream>
#include <thread>
#include <atomic>
#include <unordered_map>
#include <chrono>
#include <mutex>

#include "MPointer.cpp"
using namespace std;

// Función principal
int main() {
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

    cout << "Valor de p1: " << *&*myPtr << endl;
    cout << "Valor de p2: " << *myPtr2 << endl;

    // El destructor se invocará automáticamente al salir de main()
    return 0;
}