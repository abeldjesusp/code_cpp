#include <iostream>

using namespace std;

struct Alumno{
	char nombre[30];
	float nota1;
	float nota2;
	float nota3;
	float promedio;
};

void llenarAlumnos(Alumno[], int);
void mostrarAlumnos(Alumno[], int);
void ordenarPromedios(Alumno[], int);

int main(int argc, char const *argv[]){
	
	Alumno alumnos[30];
	int N = 3;

	llenarAlumnos(alumnos, N);
	ordenarPromedios(alumnos, N);
	mostrarAlumnos(alumnos, N);

	return 0;
}

void llenarAlumnos(Alumno A[], int N){
	for(int i = 0; i < N; i++){
		cout << "Alumno " << i+1 << endl;
		cout << "Nombre : ";
		cin.getline(A[i].nombre, 30);
		cout << "Nota 1 : ";
		cin >> A[i].nota1;
		cout << "Nota 2 : ";
		cin >> A[i].nota2;
		cout << "Nota 3 : ";
		cin >> A[i].nota3;
		cin.ignore();
		cout << endl;
		A[i].promedio = (A[i].nota1 + A[i].nota2 + A[i].nota3) / 3;
	}
}

void mostrarAlumnos(Alumno A[], int N){
	for(int i = 0; i < N; i++){
			cout << "Nombre   : " << A[i].nombre << endl;
			cout << "Promedio : " << A[i].promedio << endl;
			cout << endl;
	}
}

void ordenarPromedios(Alumno A[], int N){
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < N-1; j++){
			if(A[j].promedio < A[j+1].promedio){
				Alumno aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
		}
	}
}