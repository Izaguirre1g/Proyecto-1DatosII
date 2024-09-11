#include "quicksort.h"
/*
// Función de partición para QuickSort
int particion(ListaNodos& lista, int bajo, int alto) {
    int pivot = lista.get(alto); // Elegir el último elemento como pivote
    int i = bajo - 1; // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        if (lista.get(j) <= pivot) {
            i++;
            // Intercambiar elementos
            int temp = lista.get(i);
            lista.set(i, lista.get(j));
            lista.set(j, temp);
        }
    }

    // Intercambiar el pivote con el elemento en i + 1
    int temp = lista.get(i + 1);
    lista.set(i + 1, lista.get(alto));
    lista.set(alto, temp);

    return i + 1;
}

// Función recursiva QuickSort
void quickSort(ListaNodos& lista, int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(lista, bajo, alto); // Obtener el índice del pivote
        quickSort(lista, bajo, pi - 1); // Ordenar elementos antes del pivote
        quickSort(lista, pi + 1, alto); // Ordenar elementos después del pivote
    }
}

// Función para ordenar la lista utilizando QuickSort
void ordenarLista(ListaNodos& lista) {
    quickSort(lista, 0, lista.size() - 1);
*/
