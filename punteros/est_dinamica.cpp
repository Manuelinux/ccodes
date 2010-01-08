#include<iostream>
#include<string.h>
using namespace std;
struct directorio
{
	char nombre[20];
	int telefono;
};
int main()
{
int num,i;
cout<<"Numero de personas"<<endl;
cin>>num;
 directorio *personas[40];
 int *(x[]) = new int[5][3];
for(i=0;i<num;i++)
{
	personas[i] = new directorio;
	cout<<"Nombre"<<endl;
	cin>>personas[i]->nombre;
	cout<<"Telefono"<<endl;
	cin>>personas[i]->telefono;
}

for(i=0;i<num;i++)
{
	cout<<personas[i]->nombre<<" "<<personas[i]->telefono<<endl;
}
cin.get();
for(i=0;i<num;i++)
delete personas[i];
cin.get();
return 0;
}
