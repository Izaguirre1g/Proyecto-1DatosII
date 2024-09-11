#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "DoubleLinkedList.h"


#include "DoubleLinkedList.h"

class BubbleSort {
public:
    static void sort(DoubleLinkedList& list) {
        int size = list.sizeList();  // Obtener el tamaño de la lista.
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (list.get(j) > list.get(j + 1)) {
                    int temp = list.get(j);
                    list.set(j, list.get(j + 1));
                    list.set(j + 1, temp);
                }
            }
        }
    }
};

#endif // BUBBLESORT_H
