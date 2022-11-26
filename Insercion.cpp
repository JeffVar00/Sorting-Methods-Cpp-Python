/*Ramses Solano Arias
Warner Herrera Santamaria
Jurgen Perez Cespedes
Bryan Abarca
Jose Rodriguez Martinez*/

#include <iostream>
using namespace std;
void Insercion(int arreglo[]) {
	int W;
	//Ciclo que recorre el arreglo
	for (int i=0;i<5;i++){
		W=arreglo[i];
		// Ciclo que mueve el contenido de las posiciones
		while((i>0) && (arreglo[i-1] >W)){
			arreglo[i] = arreglo[i-1];
			i--;
		}
		arreglo[i] = W;
	}
}
void mostrarArreglo(int arreglo[]) {
	for (int i=0; i<5; i++){
		cout << arreglo[i] << " ";
	}
	cout<< endl;
}
int main() {
	int arreglo[5] = {5, 25, 3, 4, 1};
	Insercion(arreglo);
	mostrarArreglo(arreglo);
	return 0;
}
