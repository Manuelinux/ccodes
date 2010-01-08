#include <iostream>
using namespace std;
 
int main() { 
   int cadena[10] = {1,2,3,4,5,6,7,8}; 
   int *c=NULL; 
   
 
   c = cadena; // c apunta a cadena 
   while(*c)
   {
   	cout<<*c;
   	c++;
}
   cin.get();
   return 0; 
}
