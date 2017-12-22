/**********************
 *					  *
 *		Programa 01   *
 *					  *
 *********************/
#include <iostream>

using namespace std;

struct Nomina{
	char nombre[30];
	float sueldo1;
	float sueldo2;
	float sueldo3;
	float totalIngresos;
}empleados[4];

int main(){
	float ingresoMayor = 0;
	char j;

	for(int i = 0; i < 4; i++){
		cout << "Nombre : ";
		cin >> empleados[i].nombre;
		cout << "Sueldo 1: ";
		cin >> empleados[i].sueldo1;
		cout << "Sueldo 2: ";
		cin >> empleados[i].sueldo2;
		cout << "Sueldo 3: ";
		cin >> empleados[i].sueldo3;
		cout << endl;

		empleados[i].totalIngresos = empleados[i].sueldo1 + empleados[i].sueldo2 + empleados[i].sueldo3;
	}

	for(int i = 0; i < 4; i++){
		cout << "Nombre            : " <<  empleados[i].nombre << endl;
		cout << "Total de ingresos : " << empleados[i].totalIngresos << endl;
		cout << endl;

		if(ingresoMayor < empleados[i].totalIngresos){
			ingresoMayor = empleados[i].totalIngresos;
			j = i;
		}		
	}

	cout << "Empleado con mayores ingresos" << endl;
	cout  << empleados[j].nombre << endl;
	cout  << ingresoMayor << endl;

	return 0;	
}