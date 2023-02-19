//
// Created by Juan Carlos Faz Leal on 18/02/23.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/SM.h"
#include "../include/tests.h"

using namespace std;

bool isSorted(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Función para realizar pruebas aleatorias del selection sort
void test_random_selection() {
    srand(time(0)); // Inicializar generador de números aleatorios

    const int MAX_SIZE = 100; // Tamaño máximo del arreglo
    const int MAX_VALUE = 1000; // Valor máximo de los elementos del arreglo
    bool flag = false;

    // Realizar 10 pruebas aleatorias
    for (int i = 0; i < 10; i++) {
        int n = rand() % MAX_SIZE; // Tamaño aleatorio del arreglo
        int* arr = new int[n]; // Crear arreglo dinámico

        // Inicializar arreglo con valores aleatorios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % MAX_VALUE;
        }

        // Ejecutar selection sort y verificar que el arreglo esté ordenado
        selectionSort(arr, n);

        if (!isSorted(arr, n)) {
            cout << "Fallo en la prueba " << i << endl;
            flag = false;
        }
        else
        {
            flag = true;
        }

        delete[] arr; // Liberar memoria del arreglo
    }
    if (flag == true) cout << "Tests all passed" << endl;
    else cout << "Test fail";
}

// Función para realizar pruebas aleatorias del insertion sort
void test_random_insert() {
    srand(time(0)); // Inicializar generador de números aleatorios

    const int MAX_SIZE = 100; // Tamaño máximo del arreglo
    const int MAX_VALUE = 1000; // Valor máximo de los elementos del arreglo
    bool flag = false;

    // Realizar 10 pruebas aleatorias
    for (int i = 0; i < 10; i++) {
        int n = rand() % MAX_SIZE; // Tamaño aleatorio del arreglo
        int* arr = new int[n]; // Crear arreglo dinámico

        // Inicializar arreglo con valores aleatorios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % MAX_VALUE;
        }

        // Ejecutar insertion sort y verificar que el arreglo esté ordenado
        insertionSort(arr, n);

        if (!isSorted(arr, n)) {
            cout << "Fallo en la prueba " << i << endl;
            flag = false;
        }
        else
        {
            flag = true;
        }

        delete[] arr; // Liberar memoria del arreglo
    }
    if (flag == true) cout << "Tests all passed" << endl;
    else cout << "Test fail";
}

// Función para realizar pruebas aleatorias del merge sort
void test_random_merge() {
    srand(time(0)); // Inicializar generador de números aleatorios

    const int MAX_SIZE = 100; // Tamaño máximo del arreglo
    const int MAX_VALUE = 1000; // Valor máximo de los elementos del arreglo
    bool flag = false;

    // Realizar 10 pruebas aleatorias
    for (int i = 0; i < 10; i++) {
        int n = rand() % MAX_SIZE; // Tamaño aleatorio del arreglo
        int* arr = new int[n]; // Crear arreglo dinámico

        // Inicializar arreglo con valores aleatorios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % MAX_VALUE;
        }

        // Ejecutar merge sort y verificar que el arreglo esté ordenado
        mergeSort(arr, 0, n-1);

        if (!isSorted(arr, n)) {
            cout << "Fallo en la prueba " << i << endl;
            flag = false;
        }
        else
        {
            flag = true;
        }

        delete[] arr; // Liberar memoria del arreglo
    }
    if (flag == true) cout << "Tests all passed" << endl;
    else cout << "Test fail";
}