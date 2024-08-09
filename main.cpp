#include <iostream>
#include "MPointer.cpp"
using namespace std;

//class MPointer;

int main() {
    MPointer<int> myPtr = MPointer<int>::New();

    int a = 10;
    int *ptr = nullptr;
    ptr = &a;
    cout << ptr;

    *myPtr=43;







    //std::cout << "Hello, World!" << std::endl;
    //return 0;
}
