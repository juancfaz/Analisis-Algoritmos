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

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std :: cout << time_execution(insertionSort, arr, n) << std :: endl;

    // Tests
    test_random_selection();
    test_random_insert();
    test_random_merge();
    return 0;
}
