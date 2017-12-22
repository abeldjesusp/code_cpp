/*********************
 *					 *
 *		Programa 9   *
 *					 *
 *********************/

#include <iostream>

using namespace std;

int main(){
	int num1, num2;
	cout << "Numero1 : ";
	cin >> num1;
	cout << "Numero2 : ";
	cin >> num2;

	if(num1 <= 5 && num2 <= 5 && num1 > 0 && num2 > 0){
		if( num1 == 2){
			cout << "Es primo >> " << num1 << endl;
		}
		else if(num1 == 1){
			cout << "No es primo >> " << num1 << endl;
		}
		else if(num1 % 2 != 0){
			cout << "Es primo >> " << num1 << endl;
		}else{
			cout << "No es primo >> " << num1 << endl;
		}
	
		if( num2 == 2){
			cout << "Es primo >> " <<  num2 << endl;
		}
		else if(num2 == 1){
			cout << "No es primo >> " <<  num2 << endl;
		}
		else if(num2 % 2 != 0)	{
			cout << "Es primo >> " <<  num2 << endl;
		}else{
			cout << "No es primo >> " <<  num2 << endl;
		}
	}else{
		cout << "Numero incorrecto" << endl;
	}


	return 0;
}