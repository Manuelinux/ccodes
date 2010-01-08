#include <iostream>
using namespace std;
 
int main() { 
   char cadena[10] = "Hola"; 
   char *c; 
   int *n; 
   void *v;
 
   c = cadena; // c apunta a cadena 
   n = (int *)cadena; // n también apunta a cadena 
   v = (void *)cadena; // v también 
   cout << "carácter: " << *c << endl; 
   cout << "entero:   " << *n << endl; 
   cout << "float:    " << *(float *)v << endl; 
   cin.get();
   return 0; 
}
