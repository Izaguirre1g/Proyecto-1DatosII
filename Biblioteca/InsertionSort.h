#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "DoubleLinkedList.h"


#include "DoubleLinkedList.h"

class InsertionSort {
public:
    static void sort(DoubleLinkedList& list) {
        int size = list.sizeList();  // Obtener el tamaño de la lista.
        for (int i = 1; i < size; ++i) {
            int key = list.get(i);
            int j = i - 1;

            while (j >= 0 && list.get(j) > key) {
                list.set(j + 1, list.get(j));
                --j;
            }
            list.set(j + 1, key);
        }
    }
};

#endif // INSERTIONSORT_H
