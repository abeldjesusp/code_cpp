/*********************
 *					 *
 *		Programa 15  *
 *					 *
 *********************/

#include <iostream>

using namespace std;

long Factorial(long);

int main(){

	int numero;
	cout << "Ingrese un numero\n";
	cin >> numero;

	for(int i = 0; i <= numero; i++){
		cout << Factorial(i) << endl;
	}

	return 0;	
}

long Factorial(long numero){
	if(numero <= 1){
		return 1;
	}else{
		return(numero * Factorial(numero-1));
	}
}