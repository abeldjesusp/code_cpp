/*********************
 *					 *
 *		Programa 10  *
 *					 *
 *********************/

#include <iostream>

using namespace std;

int main(){
	int num1, num2, num3, multiplicacion;
	cout << "Numero 1 : ";
	cin >> num1;
	cout << "Numero 2 : ";
	cin >> num2;
	cout << "Numero 3 : ";
	cin >> num3;

	multiplicacion = num1 * num2;

	if(multiplicacion == num3){
		cout << "Son iguales >> multiplicacion : " 
			 << multiplicacion 
			 << " igual al tecer numero : " 
			 << num3 << endl;
	}else{
		cout << "No son iguales >> multiplicacion : " 
			 << multiplicacion 
			 << " diferente al tercer numero : " 
			 << num3 << endl;
	}

	return 0;
	
}