#include "include/tests.h"
#include "include/SM.h"
#include <time.h>
#include <iostream>
#include "gnuplot-iostream.h"

using namespace std;

long long time_execution(void (*sort_function)(int*, int), int *arr, int n) {
    auto start_time = chrono::high_resolution_clock::now();

    sort_function(arr, n);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    return duration.count();
}

long long time_execution_g(void (*sort_function)(int*, int, int), int *arr, int left, int right) {
    auto start_time = chrono::high_resolution_clock::now();

    sort_function(arr, left, right);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    return duration.count();
}

int main() {
    Gnuplot gp;
    gp << "plot sin(x)\n";
    //plot_complexity();
    return 0;
}
    /*
    srand(time(nullptr));
    const int n = 5; // Tamaño de la lista de elementos

    int arr_best[n]; // Lista para el mejor caso
    for (int i = 0; i < n; i++) {
        arr_best[i] = i;
    }

    int arr_avg[n];
    for (int i = 0; i < n; i++)
    {
        arr_avg[i] = rand() % n + 1;
    }

    int arr_worst[n]; // Lista para el peor caso
    for (int i = 0; i < n; i++) {
        arr_worst[i] = n - i;
    }

    // Ordenamiento por inserción
    std::cout << "Insercion - mejor caso: " << time_execution(insertionSort, arr_best, n) << " ms" << endl;
    std::cout << "Insercion - caso promedio: " << time_execution(selectionSort, arr_avg, n) << " ms" << endl;
    std::cout << "Insercion - peor caso: " << time_execution(insertionSort, arr_worst, n) << " ms" << endl << endl;

    // Ordenamiento por selección
    std::cout << "Seleccion - mejor caso: " << time_execution(selectionSort, arr_best, n) << " ms" << endl;
    std::cout << "Seleccion - caso promedio: " << time_execution(selectionSort, arr_avg, n) << " ms" << endl;
    std::cout << "Seleccion - peor caso: " << time_execution(selectionSort, arr_worst, n) << " ms" << endl << endl;

    // Ordenamiento por mezcla
    std::cout << "Merge - mejor caso: " << time_execution_g(mergeSort, arr_avg, 0, n - 1) << " ms" << endl;
    std::cout << "Merge - caso promedio: " << time_execution_g(mergeSort, arr_avg, 0, n - 1) << " ms" << endl;
    std::cout << "Merge - peor caso: " << time_execution_g(mergeSort, arr_avg, 0, n - 1) << " ms" << endl;

    cout << endl << "Tests" << endl;
    test_random_selection();
    test_random_insert();
    test_random_merge();
    */