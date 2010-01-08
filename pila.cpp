#include <iostream>
using namespace std;
int main()
{
	int col[5];
	
	int opc;
	int indice=5;
	do
	{
		//system("clear");
		cout<<"Menu"<<endl;
		cout<<"1.- Meter en la pila"<<endl;
		cout<<"2.- Sacar de la pila"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
			{
				if(indice==1)
				{
					cout<<"Pila llena"<<endl;
				}
				else
				{
					indice--;
					cout<<"Valor:"<<endl;
					cin>>col[indice];
					
				}
				break;
			}
			case 2:
			{
				if(indice==5)
				{
					cout<<"Pila vacia"<<endl;
				}
				else
				{
					cout<<col[indice]<<endl;;
					indice++;
				}
				break;
			}
			default: break;
		}
		//system("pause");
	}while(opc<3);
	return 0;
}
