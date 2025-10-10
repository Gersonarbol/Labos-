#include <iostream>
using namespace std;

int main()

{
    int numero;
    
    
    cout << "ingrese un numero" <<endl <<endl;
    cin >> numero;
    
    cout << "Tabla de multiplicar del " << numero ;
    for(int i=1; i<=20; i++){
        cout << numero << " x " << i << " = " << numero * i << endl;
    }










  return 0;
}