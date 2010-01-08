#include <iostream>
using namespace std;
 
struct stEstructura {
   int a, b; 
} estructura, *e;
 
int main() { 
   estructura.a = 10;
   estructura.b = 32;
   e = &estructura;
 
   cout << "variable" << endl;
   cout << e->a << endl;
   cout << e->b << endl;
   cout << "puntero" << endl;
   cout << estructura.a << endl; 
   cout << estructura.b << endl; 

   cin.get();
   return 0; 
} 
