#include <iostream>
using namespace std;

void seleccion(int v[], int n){
	
	int Auxiliar;
	int Menor;
	for (int i=0; i<n; i++){
		Menor=i;
		for (int j=i+1; j<n; j++){
			if (v[j] < v[Menor]){
				Menor = j;}
		}
		Auxiliar = v[i];
		v[i] = v[Menor];
		v[Menor] = Auxiliar;
	}
}
	
int main() {
	
	int v[] = {4,3,1,2,5};
	int n = 5;
	
	seleccion(v, n);
	
	for(int i = 0; i < n; i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}

