#include <iostream>
using namespace std;
#include <time.h>

void mergeSort(int lista[], int, int);
void merge_(int lista[], int, int, int);
void mostrar(int lista[], int, int);

int main()
{
    srand (time(NULL));
    for(;;)
    {
        int tamano=5;
        int lista[tamano];
        for(int i=1; i<=tamano; i++) // Lleno el vector
        {
            lista[i] = rand()%10;
        }
        cout<<"\nLa secuencia inicial : ";
        mostrar(lista, 1, tamano);

        mergeSort(lista,1,tamano); // se ingresa la lista, la posicion inicial y la posicion final
        cout<<"\nLa secuencia ordenada: ";
        mostrar(lista, 1, tamano);

        system("pause");
    }
    return 0;
}

void mostrar(int lista[], int pos_inicial, int pos_final)
{
    for(int i=pos_inicial; i<=pos_final; i++)
    {
        cout<<" "<<lista[i];
    }
    cout<<"\n";
}

//int pos_inicial : primera posicion del vector [0]
//int pos_final : ultima posicion del vector
// int medio : la posicion media del vector -> (pos_inicial+pos_final)/2

void mergeSort(int lista[], int pos_inicial, int pos_final)
{
    if(pos_inicial<pos_final)
    {
        //0: consigo el medio
        int medio = (pos_inicial+pos_final)/2; // solo toma el entero

        // 1: ordena la mitad izquierda
        mergeSort(lista, pos_inicial, medio);
  ///      mostrar(lista, pos_inicial, medio);  ///

        // 2: ordena la mitad derecha
        mergeSort(lista, medio+1, pos_final);
 ///       mostrar(lista, medio+1, pos_final); ///

        //3: mezclo las dos listas (lista_izquierda ; lista_derecha)
        merge_(lista, pos_inicial, medio, pos_final);
        // no envio medio+1 porque se puede calcular

    }
}

// recibe dos listas
void merge_(int lista[], int pos_inicial, int medio, int pos_final)
{
    int auxiliar[pos_final]; // guarda los datos ordenados
    int indice_izquierda = pos_inicial; // recorre la lista izquierda
    int indice_derecha = medio+1; // recorre la lista derecha
    int indice_auxiliar = pos_inicial; // recorre el vector auxiliar

    while (indice_izquierda <= medio && indice_derecha <= pos_final)
    {
 ///       cout<<"\n Comparo "<<lista[indice_izquierda] <<" con "<< lista[indice_derecha]; ///

        // comparo los elementos en la primera posicion de ambas listas y guardo el menor
        if(lista[indice_izquierda] <= lista[indice_derecha])
        {
            auxiliar[indice_auxiliar] = lista[indice_izquierda];
///           cout<<"\nEl menor queda como: "<< auxiliar[indice_auxiliar]<<endl;    ///
            indice_izquierda++;
        }
        else
        {
            auxiliar[indice_auxiliar] = lista[indice_derecha];
  ///          cout<<"\nEl menor queda como: "<< auxiliar[indice_auxiliar]<<endl;///
            indice_derecha++;
        }
        indice_auxiliar++;
    }

    // aca ya una de las listas se ha integrado totalmente al arreglo auxiliar
    // por lo que queda agregar la lista que falta

    if(indice_izquierda>medio) // si ya la lista izquierda se proceso, se agrega la parte derecha
    {
        for(int k=indice_derecha; k<=pos_final; k++)
        {
            auxiliar[indice_auxiliar]=lista[k];
            indice_auxiliar++;
        }
    }
    else // sino se agrega la parte de lista izquierda
    {
        for(int k=indice_izquierda; k<=medio; k++)
        {
            auxiliar[indice_auxiliar]=lista[k];
            indice_auxiliar++;
        }
    }
    for(int k=pos_inicial; k<=pos_final; k++) // se copia la lista auxiliar en la final
    {
        lista[k]=auxiliar[k];
    }
}


// cuando envio las listas finales ya los terminos estan ordenados
