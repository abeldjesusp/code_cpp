#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
#include<fstream>
using namespace std;

struct Triangulo {
	float Lado1;
	float Lado2;
	float Lado3;
	int No_Triangulo;
	int No_Figura;
};
struct Circulo{
	float Radio;
	int No_Circulo;
	int No_Figura;
};
struct Trapecio{
	float Base_Mayor;
	float Base_Menor;
	float Lado1;
	float Lado2;
	int No_Trapecio;
	int No_Figura;
};
struct Rombo{
	float Diagonal_Mayor;
	float Diagonal_Menor;
	int No_Rombo;
	int No_Figura;
};
struct Paralelogramo{
	float Base;
	float Lado;
	float Angulo;
	int No_Paralelogramo;
	int No_Figura;
};
struct DatosArea{
	string FiguraAreaMayor;
	string FiguraAreaMenor;
	string AuxFigura;
	float AreaMayor = -999999;
	float AreaMenor = 999999;
	float AreaEvaluar;
	int No_Figura_Area_Menor;
	int No_Figura_Area_Mayor;
	int No_Figura_Area_Menor_Especifica;
	int No_Figura_Area_Mayor_Especifica;
	float Promedio;
}	;
struct DatosPerimetro{
	string FiguraPerimetroMayor;
	string FiguraPerimetroMenor;
	string AuxFigura;
	float PerimetroMayor = -9999999;
	float PerimetroMenor = 9999999;
	float PerimetroEvaluar;
	int No_Figura_Perimetro_Menor;
	int No_Figura_Perimetro_Mayor;
	int No_Figura_Perimetro_Menor_Especifica;
	int No_Figura_Perimetro_Mayor_Especifica;
	float Promedio;
}	Perimetro;
struct Auxiliares_Contador{
	int cont_ejecucion = 0;
	int aux_posi_tri = 0;
	int aux_posi_cir = 0;
	int aux_posi_tra = 0;
	int aux_posi_rom = 0;
	int aux_posi_par = 0;
}	Contador; 
int Cont_aux = 0;
int cont_ejecucion = 0;
bool exito;
bool Hay_Resultadoros = false;
vector<Triangulo>Conjunto_de_Triangulos;
vector<Circulo>Conjunto_de_Circulos;
vector<Trapecio>Conjunto_de_Trapecios;
vector<Rombo>Conjunto_de_Rombos;
vector<Paralelogramo>Conjunto_de_Paralelogramos;
DatosArea Area;
void MostrarMenu();
int CapturarOpcion();
int EvaluarOpcion(int P_Opcion);
void CapturarTriangulo(Triangulo P_UnTriangulo);
void MostrarResultado();
float GetAreaTriangulo(Triangulo P_UnTriangulo);
float GetPerimetroTriangulo(Triangulo P_UnTriangulo);
float GetAreaCirculo(Circulo P_UnCirculo);
float GetPerimetroCirculo(Circulo P_UnCirculo);
void MostrarResultado(DatosArea P_MostrarArea, DatosPerimetro P_MostrarPerimetro);
DatosArea ComparacionArea(DatosArea P_AreaEvaluar);
DatosPerimetro ComparacionPerimetro(DatosPerimetro P_PerimetroEvaluar);
void CapturarCirculo(Circulo P_UnCirculo);
void CapturarTrapecio(Trapecio P_UnTrapecio);
float GetAreaTrapecio(Trapecio P_UnTrapecio);
float GetPerimetroTrapecio(Trapecio P_UnTrapecio);
void CapturarRombo(Rombo P_UnRombo);
float GetAreaRombo(Rombo P_UnRombo);
float GetPerimetroRombo(Rombo P_UnRombo);
void CapturarParalelogramo(Paralelogramo P_UnParalelogramo);
float GetAreaParalelogramo(Paralelogramo P_UnParalelogramo);
float GetPerimetroParalelogramo(Paralelogramo P_UnParalelogramo);
string CapturarOpcionGrabar();
void OpcionGrabar();
void GrabarArchivo(vector<Triangulo>P_Conjunto_de_Triangulos, vector<Circulo> P_Conjunto_de_Circulos, vector<Trapecio> P_Conjunto_de_Trapecios, vector<Rombo> P_Conjunto_de_Rombos, vector<Paralelogramo>  P_Conjunto_de_Paralelogramos);
void GrabarTriangulo(vector<Triangulo> P_Conjunto_de_Triangulos);
void GrabarCirculo(vector<Circulo> P_Conjunto_de_Circulos);
void GrabarTrapecio(vector<Trapecio> P_Conjunto_de_Trapecios);
void GrabarRombo(vector<Rombo> P_Conjunto_de_Rombos);
void GrabarParalelogramo(vector<Paralelogramo> P_Conjunto_de_Paralelogramos);
void DestruirArchivoAnterior();

int main ()
{
	MostrarMenu();
	return 0;
}
void MostrarMenu()
{
	system("cls");
	cout<<"MENU DE SELECCION DE FIGURA\n";
	if (cont_ejecucion > 0) 
		cout<<"\nVan "<<cont_ejecucion<<" figuras ingresadas\n_________________________________________\n";
	cout<<"\n1.Triangulo";
	cout<<"\n2.Circulo";
	cout<<"\n3.Trapecio";
	cout<<"\n4.Rombo";
	cout<<"\n5.Paralelogramo";
	cout<<"\n0.Finalizar seleccion";
	int Opcion = CapturarOpcion();
	if (EvaluarOpcion(Opcion) == 0)
	{
		system("cls");
		MostrarResultado(Area, Perimetro);
		if (exito == true)
			OpcionGrabar();
	}	else
	{
			Area = ComparacionArea(Area);
			Perimetro = ComparacionPerimetro(Perimetro);
			MostrarMenu();
	}
	return;
}
int CapturarOpcion()
{
	string Aux_Opcion;
	bool repetir;
	do
	{
		repetir = false;
		cout<<"\n\nQue figura quiere? ";
		getline(cin, Aux_Opcion);
		if (Aux_Opcion != "1" && Aux_Opcion != "2" && Aux_Opcion != "3" && Aux_Opcion != "4" && Aux_Opcion != "5" && Aux_Opcion != "0")
		{
			cout<<"\nHa elegido una opcion no valida.";
			repetir = true;
		}
	}	while(repetir == true);
	return atoi(Aux_Opcion.c_str());
}
int EvaluarOpcion(int P_Opcion)
{
	switch(P_Opcion)
	{
	case 1:
		Triangulo UnTriangulo;
		CapturarTriangulo(UnTriangulo);
		break;
	case 2:
		Circulo UnCirculo;
		CapturarCirculo(UnCirculo);
		break;
	case 3:
		Trapecio UnTrapecio;
		CapturarTrapecio(UnTrapecio);
		break;
	case 4:
		Rombo UnRombo;
		CapturarRombo(UnRombo);
		break;
	case 5: 
		Paralelogramo UnParalelogramo;
		CapturarParalelogramo(UnParalelogramo);
		break;
	}
	return P_Opcion;
}
void CapturarTriangulo(Triangulo P_UnTriangulo)
{
	system("cls");
	exito = true;
	Cont_aux = (Contador.aux_posi_tri += 1);
	P_UnTriangulo.No_Triangulo = Cont_aux;
	Area.AuxFigura = "Triangulo";
	Perimetro.AuxFigura = "Triangulo";
	P_UnTriangulo.No_Figura = (cont_ejecucion+=1);
	cout<<"AREA Y PERIMETRO DEL TRIAGUNLO\n\n";
	cout<<"\nDigite lado numero 1 del triangulo : ";
	cin>>P_UnTriangulo.Lado1;
	cout<<"\nDigite lado numero 2 del triangulo : ";
	cin>>P_UnTriangulo.Lado2;
	cout<<"\nDigite lado numero 3 del triangulo : ";
	cin>>P_UnTriangulo.Lado3;
	Conjunto_de_Triangulos.push_back(P_UnTriangulo);
	cin.ignore(1000, '\n');
	Area.AreaEvaluar = GetAreaTriangulo(P_UnTriangulo);
	Perimetro.PerimetroEvaluar = GetPerimetroTriangulo(P_UnTriangulo);
	cout<<"\n\nEl area es : "<<Area.AreaEvaluar;
	cout<<"\n\nEl perimetro es  : "<<Perimetro.PerimetroEvaluar<<endl<<endl;
	system("pause");
	return;
}
void CapturarCirculo(Circulo P_UnCirculo)
{
	system("cls");
	exito = true;
	Cont_aux = (Contador.aux_posi_cir += 1);
	P_UnCirculo.No_Circulo = Cont_aux;
	Area.AuxFigura = "Circulo";
	Perimetro.AuxFigura = "Circulo";
	P_UnCirculo.No_Figura = (cont_ejecucion+=1);
	cout<<"AREA Y PERIMETRO DEL CIRCULO\n";
	cout<<"\nDigite el radio del circulo ";
	cin>>P_UnCirculo.Radio;		
	Conjunto_de_Circulos.push_back(P_UnCirculo);
	cin.ignore(1000, '\n');
	Area.AreaEvaluar = GetAreaCirculo(P_UnCirculo);
	Perimetro.PerimetroEvaluar = GetPerimetroCirculo(P_UnCirculo);
	cout<<"\n\nEl area es : "<<Area.AreaEvaluar;
	cout<<"\n\nEl perimetro es  : "<<Perimetro.PerimetroEvaluar<<endl<<endl;
	system("pause");
	return;
}
void CapturarTrapecio(Trapecio P_UnTrapecio)
{
	system("cls");
	exito = true;
	Cont_aux = (Contador.aux_posi_tra += 1);
	P_UnTrapecio.No_Trapecio = Cont_aux;
	Area.AuxFigura = "Trapecio";
	Perimetro.AuxFigura = "Trapecio";
	P_UnTrapecio.No_Figura = (cont_ejecucion+=1);
	cout<<"AREA Y PERIMETRO DEL TRAPECIO\n\n";
	cout<<"\nDigite la base mayor del trapecio : ";
	cin>>P_UnTrapecio.Base_Mayor;	
	cout<<"\nDigite la base menor del trapecio : ";
	cin>>P_UnTrapecio.Base_Menor;
	cout<<"\nDigite lado numero 1 del trapecio : ";
	cin>>P_UnTrapecio.Lado1;	
	cout<<"\nDigite lado numero 2 del trapecio : ";
	cin>>P_UnTrapecio.Lado2;
	Conjunto_de_Trapecios.push_back(P_UnTrapecio);
	cin.ignore(1000, '\n');
	Area.AreaEvaluar = GetAreaTrapecio(P_UnTrapecio);
	Perimetro.PerimetroEvaluar = GetPerimetroTrapecio(P_UnTrapecio);
	cout<<"\n\nEl area es : "<<Area.AreaEvaluar;
	cout<<"\n\nEl perimetro es  : "<<Perimetro.PerimetroEvaluar<<endl<<endl;
	system("pause");
	return;
}
void CapturarRombo(Rombo P_UnRombo)
{
	system("cls");
	exito = true;
	Cont_aux = (Contador.aux_posi_rom += 1);
	P_UnRombo.No_Rombo = Cont_aux;
	Area.AuxFigura = "Rombo";
	Perimetro.AuxFigura = "Rombo";
	P_UnRombo.No_Figura = (cont_ejecucion+=1);
	cout<<"AREA Y PERIMETRO DEL ROMBO\n";
	cout<<"\nDigite la diagonal Mayor del rombo : ";
	cin>>P_UnRombo.Diagonal_Mayor;					
	cout<<"\nDigite la diagonal Menor del rombo : ";
	cin>>P_UnRombo.Diagonal_Menor;
	Conjunto_de_Rombos.push_back(P_UnRombo);
	cin.ignore(1000, '\n');
	Area.AreaEvaluar = GetAreaRombo(P_UnRombo);
	Perimetro.PerimetroEvaluar = GetPerimetroRombo(P_UnRombo);
	cout<<"\n\nEl area es : "<<Area.AreaEvaluar;
	cout<<"\n\nEl perimetro es  : "<<Perimetro.PerimetroEvaluar<<endl<<endl;
	system("pause");
	return;
}
void CapturarParalelogramo(Paralelogramo P_UnParalelogramo)
{
	system("cls");
	exito = true;
	Cont_aux = (Contador.aux_posi_par += 1);
	P_UnParalelogramo.No_Paralelogramo = Cont_aux;
	Area.AuxFigura = "Paralelogramo";
	Perimetro.AuxFigura = "Paralelogramo";
	P_UnParalelogramo.No_Figura = (cont_ejecucion+=1);
	cout<<"AREA Y PERIMETRO DEL PARALELOGRAMO\n";	
	cout<<"\nDigite el angulo paralelogramo ";
	cin>>P_UnParalelogramo.Angulo;
	cout<<"\nDigite el lado inclinado del paralelogramo ";
	cin>>P_UnParalelogramo.Lado;		
	cout<<"\nDigite la base el paralelogramo ";
	cin>>P_UnParalelogramo.Base;
	Conjunto_de_Paralelogramos.push_back(P_UnParalelogramo);
	cin.ignore(1000, '\n');
	Area.AreaEvaluar = GetAreaParalelogramo(P_UnParalelogramo);
	Perimetro.PerimetroEvaluar = GetPerimetroParalelogramo(P_UnParalelogramo);
	cout<<"\n\nEl area es : "<<Area.AreaEvaluar;
	cout<<"\n\nEl perimetro es  : "<<Perimetro.PerimetroEvaluar<<endl<<endl;
	system("pause");
	return;
}
float GetAreaParalelogramo(Paralelogramo P_UnParalelogramo)
{
	float Altura = P_UnParalelogramo.Lado * (sin (P_UnParalelogramo.Angulo * 3.14159265/180));
	return (P_UnParalelogramo.Base * Altura); 
}
float GetPerimetroParalelogramo(Paralelogramo P_UnParalelogramo)
{
	return (P_UnParalelogramo.Base * 2) + (P_UnParalelogramo.Lado * 2);
}
float GetAreaRombo(Rombo P_UnRombo)
{
	return (P_UnRombo.Diagonal_Mayor * P_UnRombo.Diagonal_Menor) / 2;
}
float GetPerimetroRombo(Rombo P_UnRombo)
{
	float Lado = sqrt(pow((P_UnRombo.Diagonal_Mayor / 2), 2) + pow((P_UnRombo.Diagonal_Menor / 2), 2));
	return Lado * 4;
}
float GetAreaTrapecio(Trapecio P_UnTrapecio)
{
	float Altura = (sqrt((4 * pow((P_UnTrapecio.Base_Mayor - P_UnTrapecio.Base_Menor) , 2) * pow(P_UnTrapecio.Lado2, 2)) -  (pow ((pow(P_UnTrapecio.Lado2, 2) + pow((P_UnTrapecio.Base_Mayor - P_UnTrapecio.Base_Menor), 2) - pow(P_UnTrapecio.Lado1, 2)), 2)))) / (2 * (P_UnTrapecio.Base_Mayor - P_UnTrapecio.Base_Menor));
	return ((P_UnTrapecio.Base_Mayor + P_UnTrapecio.Base_Menor) * Altura) / 2;
}
float GetPerimetroTrapecio(Trapecio P_UnTrapecio)
{
	return (P_UnTrapecio.Base_Mayor + P_UnTrapecio.Base_Menor + P_UnTrapecio.Lado1 + P_UnTrapecio.Lado2);	
}
float GetAreaCirculo(Circulo P_UnCirculo)
{
	return 3.14159265 * (P_UnCirculo.Radio * P_UnCirculo.Radio);
}
float GetPerimetroCirculo(Circulo P_UnCirculo)
{
	return 2 * 3.14159265 * P_UnCirculo.Radio;
}
float GetAreaTriangulo(Triangulo P_UnTriangulo)
{
	float SemiPerimetro = (P_UnTriangulo.Lado1 + P_UnTriangulo.Lado2 + P_UnTriangulo.Lado3) / 2;
	return sqrt(SemiPerimetro * (SemiPerimetro - P_UnTriangulo.Lado1) * (SemiPerimetro - P_UnTriangulo.Lado2) * (SemiPerimetro - P_UnTriangulo.Lado3));
}
float GetPerimetroTriangulo(Triangulo P_UnTriangulo)
{
	return P_UnTriangulo.Lado1 + P_UnTriangulo.Lado2 + P_UnTriangulo.Lado3;
}
DatosArea ComparacionArea(DatosArea P_AreaEvaluar)
{
	if(P_AreaEvaluar.AreaEvaluar >= P_AreaEvaluar.AreaMayor)
	{
		P_AreaEvaluar.AreaMayor = P_AreaEvaluar.AreaEvaluar;
		P_AreaEvaluar.FiguraAreaMayor = P_AreaEvaluar.AuxFigura;
		P_AreaEvaluar.No_Figura_Area_Mayor_Especifica = Cont_aux;
		P_AreaEvaluar.No_Figura_Area_Mayor = cont_ejecucion;
	}
	if(P_AreaEvaluar.AreaEvaluar <= P_AreaEvaluar.AreaMenor)
	{
		P_AreaEvaluar.AreaMenor = P_AreaEvaluar.AreaEvaluar;
		P_AreaEvaluar.FiguraAreaMenor = P_AreaEvaluar.AuxFigura;
		P_AreaEvaluar.No_Figura_Area_Menor_Especifica = Cont_aux;
		P_AreaEvaluar.No_Figura_Area_Menor = cont_ejecucion;
	}
	P_AreaEvaluar.Promedio = P_AreaEvaluar.Promedio+=P_AreaEvaluar.AreaEvaluar;
	return P_AreaEvaluar;
}
DatosPerimetro ComparacionPerimetro(DatosPerimetro P_PerimetroEvaluar)
{
	if(P_PerimetroEvaluar.PerimetroEvaluar >= P_PerimetroEvaluar.PerimetroMayor)
	{
		P_PerimetroEvaluar.PerimetroMayor = P_PerimetroEvaluar.PerimetroEvaluar;
		P_PerimetroEvaluar.FiguraPerimetroMayor = P_PerimetroEvaluar.AuxFigura;
		P_PerimetroEvaluar.No_Figura_Perimetro_Mayor_Especifica = Cont_aux;
		P_PerimetroEvaluar.No_Figura_Perimetro_Mayor = cont_ejecucion;
	}
	if(P_PerimetroEvaluar.PerimetroEvaluar <= P_PerimetroEvaluar.PerimetroMenor)
	{
		P_PerimetroEvaluar.PerimetroMenor = P_PerimetroEvaluar.PerimetroEvaluar;
		P_PerimetroEvaluar.FiguraPerimetroMenor = P_PerimetroEvaluar.AuxFigura;
		P_PerimetroEvaluar.No_Figura_Perimetro_Menor_Especifica = Cont_aux;
		P_PerimetroEvaluar.No_Figura_Perimetro_Menor = cont_ejecucion;
	}
	P_PerimetroEvaluar.Promedio+=P_PerimetroEvaluar.PerimetroEvaluar;
	return P_PerimetroEvaluar;
}
void MostrarResultado(DatosArea P_MostrarArea, DatosPerimetro P_MostrarPerimetro)
{
	char dos = 253;
	if(exito == true)
	{
		cout<<"\nTotal de figuras procesadas "<<cont_ejecucion<<"\n_____________________________________________\n";
		if (P_MostrarArea.AreaMayor != P_MostrarArea.AreaMenor)
		{
			cout<<"\n\nEl area mayor es "<<fixed<<setprecision(2)<<P_MostrarArea.AreaMayor<<" cm"<<dos<<" de la figura No."<<P_MostrarArea.No_Figura_Area_Mayor<<" que es el "<<P_MostrarArea.FiguraAreaMayor<<" No."<<P_MostrarArea.No_Figura_Area_Mayor_Especifica<<"\n";
			cout<<"\n\nEl area menor es "<<fixed<<setprecision(2)<<P_MostrarArea.AreaMenor<<" cm"<<dos<<" de la figura No."<<P_MostrarArea.No_Figura_Area_Menor<<" que es el "<<P_MostrarArea.FiguraAreaMenor<<" No."<<P_MostrarArea.No_Figura_Area_Menor_Especifica<<"\n";
			cout<<"\n\nEl promedio de las areas es de "<<fixed<<setprecision(2)<<(P_MostrarArea.Promedio /= cont_ejecucion)<<endl;
			cout<<"\n________________________________________________________________________________\n";
		}	else
		{
			cout<<"\n\nNo hay un area mayor o menor.\n";
			cout<<P_MostrarArea.AreaMayor<<endl;
			cout<<P_MostrarArea.AreaMenor<<endl;
		}
		if (P_MostrarPerimetro.PerimetroMayor != P_MostrarPerimetro.PerimetroMenor)
		{
			cout<<"\n\nEl perimetro mayor es "<<fixed<<setprecision(2)<<P_MostrarPerimetro.PerimetroMayor<<" cm de la figura No."<<P_MostrarPerimetro.No_Figura_Perimetro_Mayor<<" que es el "<<P_MostrarPerimetro.FiguraPerimetroMayor<<" No."<<P_MostrarPerimetro.No_Figura_Perimetro_Mayor_Especifica<<"\n";
			cout<<"\n\nEl perimetro menor es "<<fixed<<setprecision(2)<<P_MostrarPerimetro.PerimetroMenor<<" cm de la figura No."<<P_MostrarPerimetro.No_Figura_Perimetro_Menor<<" que es el "<<P_MostrarPerimetro.FiguraPerimetroMenor<<" No."<<P_MostrarPerimetro.No_Figura_Perimetro_Menor_Especifica<<"\n";
			cout<<"\n\nEl promedio de los perimetros es de "<<fixed<<setprecision(2)<<(P_MostrarPerimetro.Promedio /= cont_ejecucion)<<"\n";
			cout<<"\n________________________________________________________________________________\n";
		}	else
		{
			cout<<"\n\nNo hay un perimetro mayor o menor.\n";
			cout<<P_MostrarPerimetro.PerimetroMayor<<endl;
			cout<<P_MostrarPerimetro.PerimetroMenor<<endl;
		}	
	}	else
	   cout<<"\n\nDebe ingresar una figura.\n\n";
}
string CapturarOpcionGrabar()
{
	string Aux_Opcion;
	bool repetir;
	do
	{
		repetir = false;
		cout<<"\n\nDesea Guardar los Datos Ingresados? <S/N> : ";
		getline(cin, Aux_Opcion);
		if (Aux_Opcion != "S" && Aux_Opcion != "s" && Aux_Opcion != "N" && Aux_Opcion != "n")
		{
			cout<<"\nHa elegido una opcion no valida.";
			repetir = true;
		}
	}	while(repetir == true);
	return Aux_Opcion;;
}
void OpcionGrabar()
{
	string Aux = CapturarOpcionGrabar();
	if(Aux == "S" || Aux == "s")
		GrabarArchivo(Conjunto_de_Triangulos, Conjunto_de_Circulos, Conjunto_de_Trapecios, Conjunto_de_Rombos, Conjunto_de_Paralelogramos);
	return;
}
void GrabarArchivo(vector<Triangulo> P_Conjunto_de_Triangulos, vector<Circulo> P_Conjunto_de_Circulos, vector<Trapecio> P_Conjunto_de_Trapecios, vector<Rombo> P_Conjunto_de_Rombos, vector<Paralelogramo> P_Conjunto_de_Paralelogramos)
{
	DestruirArchivoAnterior();
	GrabarTriangulo(P_Conjunto_de_Triangulos);
	GrabarCirculo(P_Conjunto_de_Circulos);
	GrabarTrapecio(P_Conjunto_de_Trapecios);
	GrabarRombo(P_Conjunto_de_Rombos);
	GrabarParalelogramo(P_Conjunto_de_Paralelogramos);
	return;
}
void GrabarTriangulo(vector<Triangulo> P_Conjunto_de_Triangulos)
{
	if (P_Conjunto_de_Triangulos.size() >= 1)
	{
		ofstream outFile;
		outFile.open("E:\\DatosGuardados.txt", ios::out | ios::app);
		for(int i = 0; i < P_Conjunto_de_Triangulos.size(); i++)
		{
			outFile<<"                                   *\n";
			outFile<<"TRIANGULO                         ***\n";
			outFile<<"---------                        *****\n";
			outFile<<"                                *******\n";
			outFile<<"                               *********\n";
			outFile<<"                              ***********\n";
			outFile<<endl<<P_Conjunto_de_Triangulos[i].Lado1<<"Cm del Lado 1."<<endl;
			outFile<<P_Conjunto_de_Triangulos[i].Lado2<<"Cm del Lado 2."<<endl;
			outFile<<P_Conjunto_de_Triangulos[i].Lado3<<"Cm del Lado 3."<<endl;
			outFile<<P_Conjunto_de_Triangulos[i].No_Triangulo<<" Posicion en Triangulos Ingresadas."<<endl;
			outFile<<P_Conjunto_de_Triangulos[i].No_Figura<<" Posicion en Figuras Ingresadas."<<endl;
			outFile<<"\n\n_____________________________________________________________";
			outFile<<"\n_____________________________________________________________\n\n";
		}
		outFile.close();
	}
}
void GrabarCirculo(vector<Circulo> P_Conjunto_de_Circulos)
{
	if (P_Conjunto_de_Circulos.size() >= 1)
	{
		ofstream outFile;
		outFile.open("E:\\DatosGuardados.txt", ios::out | ios::app);
		for(int i = 0; i < P_Conjunto_de_Circulos.size(); i++)
		{
			outFile<<"                                  ***\n";
			outFile<<"CIRCULO                         *******\n";
			outFile<<"-------                        *********\n";
			outFile<<"                               *********\n";
			outFile<<"                                *******\n";
			outFile<<"                                  ***\n";
			outFile<<endl<<P_Conjunto_de_Circulos[i].Radio<<"Cm de Radio del Circulo."<<endl;
			outFile<<P_Conjunto_de_Circulos[i].No_Circulo<<" Posicion en Circulos Ingresadas."<<endl;
			outFile<<P_Conjunto_de_Circulos[i].No_Figura<<" Posicion en Figuras Ingresadas."<<endl;
			outFile<<"\n\n_____________________________________________________________";
			outFile<<"\n_____________________________________________________________\n\n";
		}
		outFile.close();
	}
}
void GrabarTrapecio(vector<Trapecio> P_Conjunto_de_Trapecios)
{
	if (P_Conjunto_de_Trapecios.size() >= 1)
	{
		ofstream outFile;
		outFile.open("E:\\DatosGuardados.txt", ios::out | ios::app);
		for(int i = 0; i < P_Conjunto_de_Trapecios.size(); i++)
		{
			outFile<<"                                *******\n";
			outFile<<"TRAPECIO                       *********\n";
			outFile<<"--------                      ***********\n";
			outFile<<"                             *************\n";
			outFile<<"                            ***************\n";
			outFile<<"                           *****************\n";
			outFile<<endl<<P_Conjunto_de_Trapecios[i].Base_Mayor<<"Cm de la Base Mayor."<<endl;
			outFile<<P_Conjunto_de_Trapecios[i].Base_Menor<<"Cm de la Base Menor."<<endl;
			outFile<<P_Conjunto_de_Trapecios[i].Lado1<<"Cm del Lado 1."<<endl;
			outFile<<P_Conjunto_de_Trapecios[i].Lado2<<"Cm del Lado 2."<<endl;
			outFile<<P_Conjunto_de_Trapecios[i].No_Trapecio<<" Posicion en Trapecios Ingresados."<<endl;
			outFile<<P_Conjunto_de_Trapecios[i].No_Figura<<" Posicion en Figuras Ingresadas."<<endl;
			outFile<<"\n\n_____________________________________________________________";
			outFile<<"\n_____________________________________________________________\n\n";
		}
		outFile.close();
	}
}
void GrabarRombo(vector<Rombo> P_Conjunto_de_Rombos)
{
	if (P_Conjunto_de_Rombos.size() >= 1)
	{
		ofstream outFile;
		outFile.open("E:\\DatosGuardados.txt", ios::out | ios::app);
		for(int i = 0; i < P_Conjunto_de_Rombos.size(); i++)
		{
			outFile<<"                                   *\n";
			outFile<<"ROMBO                             ***\n";
			outFile<<"-----                            *****\n";
			outFile<<"                                *******\n";
			outFile<<"                                 *****\n";
			outFile<<"                                  ***\n";
			outFile<<"                                   *\n";
			outFile<<endl<<P_Conjunto_de_Rombos[i].Diagonal_Mayor<<"Cm de la Diagonal Mayor."<<endl;
			outFile<<P_Conjunto_de_Rombos[i].Diagonal_Menor<<"Cm de la Diagonal Menor."<<endl;
			outFile<<P_Conjunto_de_Rombos[i].No_Rombo<<" Posicion en Rombos Ingresados."<<endl;
			outFile<<P_Conjunto_de_Rombos[i].No_Figura<<" Posicion en Figuras Ingresadas."<<endl;
			outFile<<"\n\n_____________________________________________________________";
			outFile<<"\n_____________________________________________________________\n\n";
		}
		outFile.close();
	}
}
void GrabarParalelogramo(vector<Paralelogramo> P_Conjunto_de_Paralelogramo)
{
	if (P_Conjunto_de_Paralelogramo.size() >= 1)
	{
		ofstream outFile;
		outFile.open("E:\\DatosGuardados.txt", ios::out | ios::app);
		for(int i = 0; i < P_Conjunto_de_Paralelogramo.size(); i++)
		{
			outFile<<"                             *************\n";
			outFile<<"PARALELOGRAMO               *************\n";
			outFile<<"-------------              *************\n";
			outFile<<"                          *************\n";
			outFile<<"                         *************\n";
			outFile<<"                        *************\n";
			outFile<<endl<<P_Conjunto_de_Paralelogramo[i].Base<<"Cm de la Base."<<endl;
			outFile<<P_Conjunto_de_Paralelogramo[i].Lado<<"Cm de Lado."<<endl;
			outFile<<P_Conjunto_de_Paralelogramo[i].Angulo<<"Cm de Angulo."<<endl;
			outFile<<P_Conjunto_de_Paralelogramo[i].No_Paralelogramo<<" Posicion en Paralelogramos Ingresados."<<endl;
			outFile<<P_Conjunto_de_Paralelogramo[i].No_Figura<<" Posicion en Figuras Ingresadas."<<endl;
			outFile<<"\n\n_____________________________________________________________";
			outFile<<"\n_____________________________________________________________\n\n";
		}
		outFile.close();
	}
}
void DestruirArchivoAnterior()
{
	ofstream outFile;
	outFile.open("E:\\DatosGuardados.txt", ios::out);
	outFile<<"";
}
