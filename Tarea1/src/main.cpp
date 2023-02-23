#include "../include/SM.h"
#include <time.h>
#include <iostream>
#include <cmath>

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

int* data_y(int n)
{
    int* timess = new int[n];
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
    timess[0] = time_execution(insertionSort, arr_best, n);
    timess[1] = time_execution(selectionSort, arr_avg, n);
    timess[2] = time_execution(insertionSort, arr_worst, n);

    // Ordenamiento por selección
    timess[3] = time_execution(selectionSort, arr_best, n);
    timess[4] = time_execution(selectionSort, arr_avg, n);
    timess[5] = time_execution(selectionSort, arr_worst, n);

    // Ordenamiento por mezcla
    timess[6] = time_execution_g(mergeSort, arr_best, 0, n - 1);
    timess[7] = time_execution_g(mergeSort, arr_avg, 0, n - 1);
    timess[8] = time_execution_g(mergeSort, arr_worst, 0, n - 1);
    
    return timess;
}



int main() {
    const int n = 100000; // número máximo de elementos en el arreglo
    const int step = 5000; // cantidad de elementos a incrementar en cada iteración

    // arreglos para almacenar los tiempos de ejecución normalizados de cada método
    double y_ins_best[n/step];
    double y_ins_avg[n/step];
    double y_ins_worst[n/step];
    double y_sel_best[n/step];
    double y_sel_avg[n/step];
    double y_sel_worst[n/step];
    double y_mer_best[n/step];
    double y_mer_avg[n/step];
    double y_mer_worst[n/step];

    // imprimir los valores de x e y
    for (int i = 0; i < n/step; i++) {
        int x = (i + 1) * step;
        int *timess = data_y(x); // obtener los tiempos para el tamaño actual del arreglo

        // almacenar los tiempos normalizados en los arreglos correspondientes
        y_ins_best[i] = timess[0];
        y_ins_avg[i] = timess[1];
        y_ins_worst[i] = timess[2];
        y_sel_best[i] = timess[3];
        y_sel_avg[i] = timess[4];
        y_sel_worst[i] = timess[5];
        y_mer_best[i] = timess[6];
        y_mer_avg[i] = timess[7];
        y_mer_worst[i] = timess[8];

        // liberar la memoria asignada a timess
        delete[] timess;
    }

    cout << "x insertSortbest*1000 insertSortaverage insertSortworst selectionSortbest selectionSortaverage selectionSortworst mergebest mergeaverage mergeworst" << endl;
    for (int i = 0; i < n/step; i++) {
        cout << i << " " << (y_ins_best[i])*1000 << " " << y_ins_avg[i] << " " << y_ins_worst[i] << " "
            << y_sel_best[i] << " " << y_sel_avg[i] << " " << y_sel_worst[i] << " "
            << y_mer_best[i] << " " << y_mer_avg[i] << " " << y_mer_worst[i] << endl;
    }
    return 0;
}