#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "DoubleLinkedList.h"

class QuickSort {
public:
    static void sort(DoubleLinkedList& list) {
        quickSort(list, 0, list.sizeList() - 1);  // Llamada inicial con los índices correctos.
    }

private:
    static void quickSort(DoubleLinkedList& list, int low, int high) {
        if (low < high) {
            int pi = partition(list, low, high);
            quickSort(list, low, pi - 1);
            quickSort(list, pi + 1, high);
        }
    }

    static int partition(DoubleLinkedList& list, int low, int high) {
        int pivot = list.get(high);
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (list.get(j) < pivot) {
                ++i;
                int temp = list.get(i);
                list.set(i, list.get(j));
                list.set(j, temp);
            }
        }

        int temp = list.get(i + 1);
        list.set(i + 1, list.get(high));
        list.set(high, temp);

        return i + 1;
    }
};

#endif // QUICKSORT_H
