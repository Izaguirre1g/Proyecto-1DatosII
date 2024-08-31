#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "ListaNodos.h"

// Declara las funciones de QuickSort
int particion(ListaNodos& lista, int bajo, int alto);

void quickSort(ListaNodos& lista, int bajo, int alto);

void ordenarLista(ListaNodos& lista);

#endif // QUICKSORT_H

