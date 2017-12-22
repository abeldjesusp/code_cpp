/***********************
 *		               *
 *		Programa 2     *
 *				       *
 ***********************/

#include <iostream>

using namespace std;

void convertirEnteroLargo(int);

int main(){
	int longitud1, longitud2, longitud3, suma;
	cout << "Longitud 1 : ";
	cin >> longitud1;
	cout << "Longitud 2 : ";
	cin >> longitud2;
	cout << "Longitud 3 : ";
	cin >> longitud3;

	suma = longitud1 + longitud2;

	if(suma > longitud3){
		cout << "Existe un triangulo\n";
	}else{
		cout << "No existe un triangulo\n";
	}

	return 0;
	
}