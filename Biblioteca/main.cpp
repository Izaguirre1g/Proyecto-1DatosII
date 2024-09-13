#include <iostream>

#include "BubbleSort.h"
#include "DoubleLinkedList.h"
#include "InsertionSort.h"
#include "MPointer.h"
#include "MPointerGC.h"
#include "QuickSort.h"

using namespace std;

void mostrarEstado() {
    MPointerGC::getInstance().mostrarNodos();
}

int main() {
    MPointerGC& gc = MPointerGC::getInstance();

    //Crea los MPointers
    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    MPointer<int> myPtr3 = MPointer<int>::New();
    MPointer<int> myPtr4 = MPointer<int>::New();
    MPointer<int> myPtr5 = MPointer<int>::New();
    myPtr5=755;
    // Asignar valor a myPtr
    *myPtr = 5;
    myPtr3 =78;
    myPtr4=85;
    cout <<"Verificación del correcto uso de los MPointers"<<endl;
    //Muestra el estado antes de la asignación
    cout << "Estado antes de myPtr2 = myPtr:" << endl;
    mostrarEstado();

    // Aquí sucede el Shallow copy
    myPtr2= myPtr;

    //Muestra el estado después de la asignación
    cout << "Estado despues de myPtr2 = myPtr:" << endl;
    mostrarEstado();

    // Limpia y finaliza para evitar problemas con la memoria
    gc.detener();

    /******************************************************************/
    /******************************************************************/
    cout <<"----Uso de los algoritmos de ordenamiento con MPointers: Quicksort, Bubblesort e Insertionsort----"<<endl;
    //Crea una lista doblemente enlazada
    DoubleLinkedList list;
    list.add(3895);
    list.add(1);
    list.add(44520);
    list.add(22);
    list.add(3865);
    list.add(1032);
    list.add(47966);
    list.add(20101);
    list.add(-785);
    list.add(1715);
    list.add(4);
    list.add(20);
    list.add(4696);
    list.add(2901);
    list.add(1215);
    list.add(-4);
    list.add(20786);
    cout << "Lista original: ";
    list.printList();

    //Ordenamiento con BubbleSort
    BubbleSort::sort(list);
    cout << "Lista ordenada con BubbleSort: "<<endl;
    list.printList();

    //Ordenamiento con InsertionSort
    InsertionSort::sort(list);
    cout << "Lista ordenada con InsertionSort: "<<endl;
    list.printList();

    //Ordenamiento con QuickSort
    QuickSort::sort(list);
    cout << "Lista ordenada con QuickSort: "<<endl;
    list.printList();

    return 0;

}
#include <gtest/gtest.h>


/*
TEST(SumarTest, Positivos) {
EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
