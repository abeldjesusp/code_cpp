#include <iostream>

using namespace std;

struct Proveedor{
	char nombre[30];
	int cantidadVendida;
	float precioUnitario;
	float importe;
};

void llenarProveedores(Proveedor[], int);
Proveedor buscarMasCaro(Proveedor[], int);
Proveedor buscarMasBarato(Proveedor[], int);
void mostrarProveedor(Proveedor);

int main(int argc, char const *argv[]){
	
	Proveedor proveedores[30], masBarato, masCaro;
	const int N = 5;

	llenarProveedores(proveedores, N);
	masBarato = buscarMasBarato(proveedores, N);
  masCaro = buscarMasCaro(proveedores, N);
 	cout << "PROVEEDOR MAS BARATO" << endl;
 	mostrarProveedor(masBarato);
 	cout << "PROVEEDOR MAS CARO" << endl;
 	mostrarProveedor(masCaro);

	return 0;
}

void llenarProveedores(Proveedor A[], int N){
	for(int i = 0; i < N; i++){
		cout << "Proveedor " << i+1 << endl;
		cout << "Nombre : ";
		cin.getline(A[i].nombre, 30);
		cout << "Cantidad vendida : ";
		cin >> A[i].cantidadVendida;
		cout << "Precio unitario  : ";
		cin >> A[i].precioUnitario;
		cin.ignore();
		cout << endl;
		A[i].importe = A[i].precioUnitario * A[i].cantidadVendida;
	}
}

Proveedor buscarMasCaro(Proveedor A[], int N){
	Proveedor masCaro = A[0];
	for(int i = 1; i < N; i++){
		if(A[i].precioUnitario > masCaro.precioUnitario){
			masCaro = A[i];
		}
	}

	return masCaro;
}

Proveedor buscarMasBarato(Proveedor A[], int N){
	Proveedor masBarato = A[0];
	for(int i = 1; i < N; i++){
		if(A[i].precioUnitario < masBarato.precioUnitario){
			masBarato = A[i];
		}
	}

	return masBarato;
}

void mostrarProveedor(Proveedor p){
	cout << "Nombre           : " << p.nombre << endl;
	cout << "Precio Unitario  : " << p.precioUnitario << endl;
	cout << "Cantidad vendida : " << p.cantidadVendida << endl;
	cout << "Importe          : " << p.importe << endl;

}