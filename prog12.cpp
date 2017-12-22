/**********************
 *					  *
 *		Programa 12   *
 *					  *
 *********************/

#include <iostream>

using namespace std;

int main(){
	float importeBruto, importeNeto;

	cout << "Digite importe bruto : ";
	cin >> importeBruto;

	if(importeBruto > 15000){
		importeNeto = importeBruto * 0.16;
	}else{
		importeNeto = importeBruto * 0.10;
	}


	cout << "\n\n*********Resultado********\n\n";
	cout << "El importe neto es de " << importeNeto << endl;

	return 0;
	
}