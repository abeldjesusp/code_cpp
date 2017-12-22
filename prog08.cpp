/*********************
 *					 *
 *		Programa 8   *
 *					 *
 *********************/


#include <iostream>

using namespace std;

int main(){
	char letra;

	cout << "Escriba una letra\n";
	cin >> letra;

	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			cout << "Es una vocal\n";
			break;
		default:
			cout << "No es una vocal\n";
	}

	return 0;
	
}