/*********************
 *					 *
 *		Programa 11  *
 *					 *
 *********************/

#include <iostream>

using namespace std;

int main(){
	int num1, num2, num3, resto;
	cout << "Numero 1 : ";
	cin >> num1;
	cout << "Numero 2 : ";
	cin >> num2;
	cout << "Numero 3 : ";
	cin >> num3;

	resto = num1 % num2;

	if(resto == num3){
		cout << "Son iguales >> resto : " << resto << " igual al tecer numero : " <<num3 << endl;
	}else{
		cout << "No son iguales >> resto : " << resto << " diferente al tercer numero : "  << num3 << endl;
	}

	return 0;
	
}