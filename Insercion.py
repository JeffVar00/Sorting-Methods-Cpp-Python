"""Ramses Solano Arias
Warner Herrera Santamaria
Jurgen Perez Cespedes
Bryan Abarca
Jose Rodriguez Martinez"""


def insercion(arreglo):
    # Ciclo que recorre el arreglo
    for i in range(1, len(arreglo)):
        W = arreglo[i]
        # Ciclo que mueve las cartas
        while i > 0 and arreglo[i - 1] > W:
            arreglo[i] = arreglo[i - 1]
            i = i - 1
        arreglo[i] = W


def mostrar_arreglo(arreglo):
    for i in arreglo:
        print(i, end=" ")


def main():
    arreglo = [5, 25, 3, 4, 1]
    insercion(arreglo)
    mostrar_arreglo(arreglo)


if __name__ == "__main__":
    main()
