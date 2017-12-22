/*********************
 *					 *
 *		Programa 04  *
 *					 *
 *********************/

#include <iostream>

using namespace std;
 
int main(){  

		int num1, num2, aux1, aux2, resul = 1, i = 2;

	  cout << "Numero 1 : ";
 	  cin >> num1;
 	  cout << "Numero 2 : ";
 	  cin >> num2;

 	  if(num1 < num2){
 	  	aux1 = num1;
 	  	aux2 = num2;
 	  }else{
 	  	aux1 = num2;
 	  	aux2 = num1;
 	  }

    do{

      if (aux1 % i == 0 && aux2 % i == 0){
        resul  = resul * i;
        aux1 = aux1 / i;
        aux2 = aux2 / i;
        i = 2;
      }else i++;

    }while(i <= aux1);

    cout << "El MCD es " << resul << endl;

 	return 0;
}