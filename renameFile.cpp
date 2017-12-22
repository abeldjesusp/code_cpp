#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]){
	/*** Eliminar y Renombrar Archivo ***/
	/** RENAME **/
		/*if(rename("writeInBinary.cpp", "writeAndReadInBinary.cpp")==0){
			cout << "El archivo se renombro con exito" << endl;
		}else{
			cout << "NO se pudo renombrar" << endl;
		}*/
	/** Remove **/
	if(remove("promedio.cpp") == 0){
		cout << "Se elimino con exito" <<  endl;
	}else{
		cout << "NO se pudo eliminar" << endl;
	}
	return 0;
}