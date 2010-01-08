#include <iostream>
using namespace std;
 
int main() { 
   char Mes[][11] = { "Enero", "Febrero", "Marzo", "Abril", 
      "Mayo", "Junio", "Julio", "Agosto", 
      "Septiembre", "Octubre", "Noviembre", "Diciembre"}; 
   char *Mes2[] = { "Enero", "Febrero", "Marzo", "Abril", 
      "Mayo", "Junio", "Julio", "Agosto", 
      "Septiembre", "Octubre", "Noviembre", "Diciembre"};
 
   cout << "Tamaño de Mes: " << sizeof(Mes) << endl; 
   cout << "Tamaño de Mes2: " << sizeof(Mes2) << endl; 
   cout << "Tamaño de cadenas de Mes2: " 
        << &Mes2[11][10]-Mes2[0] << endl; 
   cout << "Tamaño de Mes2 + cadenas : " 
        << sizeof(Mes2)+&Mes2[11][10]-Mes2[0] << endl;
 
   cin.get();
   return 0; 
} 
