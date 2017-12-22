/***********************
 *                     *
 *      Programa 07    *
 *                     *
 ***********************/

#include <iostream>

using namespace std;
 
void productoDeUnEntero(int);

int main(){  
    int num1;

    cout << "Numero : ";
    cin >> num1;
    
    productoDeUnEntero(num1);
    return 0;
}

void productoDeUnEntero(int num1){
    int num2, producto;
    if(num1 > 9 && num1 < 100){
        num2 = num1 % 10; // Obtiene el ultimp digito
        num1 = num1 / 10; // Obtiene el primero digito

        producto = num1 * num2;
        cout << "El producto es : " << producto << endl;
    }else{
        cout << "El numero no es de dos digitos\n";
    }
}