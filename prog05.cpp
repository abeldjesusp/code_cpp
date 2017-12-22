/*********************
 *									 *
 *		Programa 05    *
 *									 *
 *********************/

#include <iostream>

using namespace std;

void conversor(float, char);
 
int main(){  
    char unidad;
    float longitud, resul;
    cout << "Kilometros  => (K)\nCentimetros => (C)\nPulgadas    => (P)\n\n";
    cout << "Unidad de medida : ";
    cin >> unidad;
    cout << "Longitud         : ";
    cin >> longitud;
    
    conversor(longitud, unidad);


 	return 0;
}

void conversor(float num, char unidad){
  switch(unidad){
    case 'p':
    case 'P':
      num = num * 0.0254;
      cout << "\nResultado => " << num << " metros" << endl;
      break;
    case 'c'  :
    case 'C'  :
      num = num * 0.01;
      cout << "\nResultado => " << num << " metros\n";
      break;
    case 'K'  :
    case 'k'  :
      num = num * 1000;
      cout << "\nResultado => " << num << " metros\n";
      break;
    default:
      cout << "Unidad incorrecta\n";
  }
}