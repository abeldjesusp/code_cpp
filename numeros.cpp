#include<iostream>
#include<string>
#include<stdlib.h>
//#include<conio.h>
using namespace std;

int main ()
{
	float num_validado;
	string aux_num;
	inicio:
		system("clear");
		cout<<"Digite un numero ";
		getline(cin, aux_num);
		if (aux_num == "0")
		{
			cout<<"\nEl numero fue 0.\n\n";
			cout<<"Presione una tecla para continuar...";
		//	getch();
			cin.ignore();
			goto inicio;
		}
		num_validado = atof(aux_num.c_str());
		if (num_validado == 0)
		{
			cout<<"\nNo es un numero.\n\n";
			cout<<"Presione una tecla para continuar...";
			//getch();
			cin.ignore();
			goto inicio;
		}	else
		{
			cout<<"\nEl numero fue "<<num_validado<<endl<<endl;
			cout<<num_validado<<" + "<<num_validado<<" = "<<num_validado*2<<endl<<endl; 
			cout<<"Presione una tecla para continuar...";
			//getch();
			cin.ignore();
			goto inicio;
		}
	return 0;
}
