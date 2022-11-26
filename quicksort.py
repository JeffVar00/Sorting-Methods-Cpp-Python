import random
"""
Ejercicios hechos por:
    CALEB SANCHEZ SOLORZANO
    SEBASTIAN SEGURA MENDEZ
    ANGELLY CORTES HERRERA
    LUIS QUESADA BARRANTES
    ESTEBAN RAMIREZ GARCIA
"""

def exchange(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp


def partition(arr, low, high):
    pivot = arr[low]
    i = low
    j = high - 1
    while i < j:
        while i < j:
            if arr[i] <= pivot:
                i += 1
            else:
                break

        while True:
            if arr[j] > pivot:
                j -= 1
            else:
                break
        if i < j:
            exchange(arr, i, j)
    exchange(arr, j, low)
    return j


def quicksort1(arr, low, high):
    if low >= high: return
    j = partition(arr, low, high)
    quicksort1(arr, low, j)
    quicksort1(arr, j + 1, high)


def quicksort(arr):
    quicksort1(arr, 0, len(arr))


def check(arr):
    return arr == sorted(arr)


if __name__ == '__main__':
    length = 25
    a = [random.randint(1, 100000) for i in range(length)]
    print("Array antes de quicksort:", a)
    quicksort(a)
    print("Array despues de quicksort:", a)
    print("La lista está ordenada?", "si" if check(a) else "no")
