/*********************
 *					 *
 *		Programa 6   *
 *				  	 *
 *********************/

#include <iostream>

using namespace std;

void convertirEnteroLargo(int);

int main(){
	int num;
	cout << "Escriba un numero\n";
	cin >> num;
	convertirEnteroLargo(num);

	return 0;
	
}

void convertirEnteroLargo(int num){
	cout << "El numero es " << (float)num;
}