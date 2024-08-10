#include <iostream>
#include "MPointer.cpp"
using namespace std;

//class MPointer;

int main() {
   /** MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    *myPtr = 5;
    if (myPtr2 = myPtr){

    }**/
    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr=5;
    cout << "Sobrecargado *: " <<*myPtr<<endl;
    int valor = *myPtr;
    cout << "Sobrecargado &: "<< valor<<endl;









    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}
