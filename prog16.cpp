/*********************
 *					 *
 *		Programa 16  *
 *					 *
 *********************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	
	int numero, acumulador = 0;

	srand(time(NULL));

	for(int i = 0; i <= 50; i++){
		numero = 1 + rand() % ((7+1) - 1);

		if(numero == 1){
			acumulador++;
		}
	}

	cout << "El numero 1 salio >> " << acumulador << " veces\n";

	return 0;	
}