#include <iostream>
#include <fstream>

using namespace std;

struct Persona{
	char nombre[8];
	int edad;
};

int main(int argc, char const *argv[]){
	/** Archivos binarios **/
	// Escritura

	// ofstream salida;
	// salida.open("data.bin",ios::binary);

	// Persona p = {"Abel", 22};
	// salida.write((char*)&p, sizeof(Persona));
	// salida.close();

	// Lectura

	Persona p;
	ifstream entrada;
	entrada.open("data.bin", ios::binary);
	while(entrada.read((char*)&p, sizeof(Persona))){
		cout << p.nombre << endl;
		cout << p.edad << endl;
	}


	return 0;
}