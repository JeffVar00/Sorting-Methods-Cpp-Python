#include <iostream>
using namespace std;
void imprimir(int[], int n); // imprime el arreglo, despues de ser actualizado por shell
void shell(int[], int n); 
int main()
{
	int total; 
	cout << "Enter total elements: " << endl;
	cin >> total;
	int* num = new int;
	for (int i = 0; i < total; i++)
	{
		cout << "Enter the element [ " << (i + 1) << " ] :" << endl;
		cin >> num[i];
	}
	shell(num, total);
}

void shell(int a[], int n)
{
	int ints, i, aux;
	bool band;
	ints = n;  //Se le asigna a ints el tamanio del arreglo
	while (ints > 1)
	{
		
		ints = (ints / 2); //Se divide ints entre 2
		
		band = true;
		while (band == true)
		{
			band = false;
			i = 0;
			while ((i + ints) <= n)
			{
				//Cambio de posicion en caso de que el numero actual sea mayor al de ints+i adelante
				if (a[i] > a[i + ints])
				{
					aux = a[i]; //Se guarda numero actual
					a[i] = a[i + ints];//Se asigna el numero menor en la pos actual
					a[i + ints] = aux;//Se asigna el numero guardado en la otra posicion
					band = true;
				}
				i++;
				
			}
			imprimir(a, n);//Se imprime para ver el progreso
			cout<<endl;
		}
	}
}

void imprimir(int a[], int n)
{
	cout << "Elementos Ordenados: " << endl;
	
	for (int i = 0; i < n; i++)
		cout << "[ " << a[i] << " ]";
}
