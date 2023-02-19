//
// Created by Juan Carlos Faz Leal on 18/02/23.
//
#include <iostream>
#include "../include/SM.h"

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mueve los elementos mayores a la derecha del elemento ordenado actual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Inserta el elemento ordenado actual en la posición correcta
        arr[j + 1] = key;
    }
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Encuentra el elemento mínimo en el arreglo sin ordenar
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Intercambia el elemento mínimo con el primer elemento sin ordenar
        if (minIndex != i) {
            std :: swap(arr[minIndex], arr[i]);
        }
    }
}

void merge(int *arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crea arreglos temporales para almacenar las sub-listas izquierda y derecha
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    // Copia los elementos de la sub-lista izquierda en el arreglo temporal
    for (i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    // Copia los elementos de la sub-lista derecha en el arreglo temporal
    for (j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Combina las sub-listas izquierda y derecha en el arreglo ordenado
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de la sub-lista izquierda (si los hay)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de la sub-lista derecha (si los hay)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Libera la memoria del arreglo temporal
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordena la sub-lista izquierda
        mergeSort(arr, left, middle);

        // Ordena la sub-lista derecha
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}