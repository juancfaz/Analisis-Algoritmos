#include "include/tests.h"
#include "include/SM.h"
#include <time.h>
#include <iostream>

double time_execution(void (*sortmethod)(int*, int), int* arr, int n) {
    clock_t start_time, end_time;
    // Registra el tiempo de inicio
    start_time = clock();
    // Ejecuta el método de ordenamiento
    sortmethod(arr, n);
    // Registra el tiempo de fin
    end_time = clock();
    // Calcula el tiempo de ejecución en milisegundos
    double execution_time = (double) (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
    return execution_time;
}

double time_execution_g(void (*sortmethod)(int*, int, int), int* arr, int left, int right) {
    clock_t start_time, end_time;
    // Registra el tiempo de inicio
    start_time = clock();
    // Ejecuta el método de ordenamiento
    sortmethod(arr, left, right);
    // Registra el tiempo de fin
    end_time = clock();
    // Calcula el tiempo de ejecución en milisegundos
    double execution_time = (double) (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
    return execution_time;
}


int main() {
    std::srand(std::time(nullptr));
    const int n = 10000; // Tamaño de la lista de elementos

    int arr_best[n]; // Lista para el mejor caso
    for (int i = 0; i < n; i++) {
        arr_best[i] = i;
    }

    int arr_avg[n];
    for (int i = 0; i < n; i++)
    {
        arr_avg[i] = std::rand() % n + 1;
    }

    int arr_worst[n]; // Lista para el peor caso
    for (int i = 0; i < n; i++) {
        arr_worst[i] = n - i;
    }

    // Ordenamiento por inserción
    std::cout << "Insercion - mejor caso: " << time_execution(insertionSort, arr_best, n) << " ms" << std::endl;
    std::cout << "Insercion - caso promedio: " << time_execution(selectionSort, arr_avg, n) << " ms" << std::endl;
    std::cout << "Insercion - peor caso: " << time_execution(insertionSort, arr_worst, n) << " ms" << std::endl << std::endl;

    // Ordenamiento por selección
    std::cout << "Seleccion - mejor caso: " << time_execution(selectionSort, arr_best, n) << " ms" << std::endl;
    std::cout << "Seleccion - caso promedio: " << time_execution(selectionSort, arr_avg, n) << " ms" << std::endl;
    std::cout << "Seleccion - peor caso: " << time_execution(selectionSort, arr_worst, n) << " ms" << std::endl << std::endl;

    // Ordenamiento por mezcla
    std::cout << "Merge - mejor caso: " << time_execution_g(mergeSort, arr_avg, 0, n - 1) << " ms" << std::endl;
    std::cout << "Merge - peor caso: " << time_execution_g(mergeSort, arr_avg, 0, n - 1) << " ms" << std::endl;

    std::cout << std::endl << "Tests" << std::endl;
    test_random_selection();
    test_random_insert();
    test_random_merge();
    return 0;
}
