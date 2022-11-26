/*
Ejercicios hechos por:

CALEB SANCHEZ SOLORZANO
SEBASTIAN SEGURA MENDEZ
ANGELLY CORTES HERRERA
LUIS QUESADA BARRANTES
ESTEBAN RAMIREZ GARCIA

*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high);

void quicksort(int arr[], int l);

void quicksort(int arr[], int low, int high);

void exchange(int arr[], int i, int j);

int random(int min, int max);

void print(int arr[], int len);

int main() {
    int max = 100000;
    int length = 10;
    int a[length];
    for (int i = 0; i < length; ++i) {
        a[i] = random(0, max);
    }
    cout << "Array antes:";
    print(a, length);
    quicksort(a, length);
    cout << "Array despues:";
    print(a, length);
    return 0;
}

void print(int arr[], int length) {
    cout << "\n";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ((i + 1 == length) ? "" : ",");
    }
    cout << "\n";
}

void quicksort(int arr[], int length) {
    quicksort(arr, 0, length);
}

void quicksort(int arr[], int low, int high) {
    if (low >= high) return;
    int p = partition(arr, low, high);
    quicksort(arr, low, p);
    quicksort(arr, p + 1, high);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {//n-1
        while (arr[++i] <= pivot);//n/k
        while (arr[--j] > pivot);//n/k

        if (i < j)
            exchange(arr, i, j);
    }
    exchange(arr, j, low);
    return j;
}

void exchange(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int random(int min, int max) { //https://stackoverflow.com/a/7560171/11449132
    static bool first = true;
    if (first) {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}