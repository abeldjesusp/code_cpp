#include <iostream>

using namespace std;


void mayor(int, int, int, int);

int main(int argc, char** argv){
    int num1, num2, num3, num4;

    cout << "Numero 1 : ";
    cin >> num1;
    cout << "Numero 2 : ";
    cin >> num2;
    cout << "Numero 3 : ";
    cin >> num3;
    cout << "Numero 4 : ";
    cin >> num4;

    mayor(num1, num2, num3, num4);

    return 0;
}

void mayor(int num1, int num2, int num3, int num4){
    string mensaje = "Es mayor ";
    if(num1 > num2){
        if(num1 > num3){
            if(num1 > num4){
                cout << mensaje << num1;
            }else{
                cout << mensaje << num4;
            }
        }else if(num3 > num4){
                cout << mensaje << num3;
        }else{
            cout << mensaje << num4;
        }
    }else if(num2 > num3){
        if(num2 > num4){
            cout << mensaje << num2;
        }
    }else if(num3 > num4){
        cout << mensaje << num3;
    }else{
        cout << mensaje << num4;
    }

}
