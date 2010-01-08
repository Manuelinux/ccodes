#include <iostream>
using namespace std;
int main()
{
	int col[5];
	
	int opc;
	int indice=0;
	//int aux;
	do
	{
		//system("clear");
		cout<<"Menu"<<endl;
		cout<<"1.- Meter en la cola"<<endl;
		cout<<"2.-Sacar de la cola"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
			{
				if(indice==5)
				{
					cout<<"cola llena"<<endl;
				}
				else
				{
					cout<<"Valor:"<<endl;
					cin>>col[indice];
					indice++;
					
				}
				break;
			}
			case 2:
			{
				if(indice==0)
				{
					cout<<"cola vacia"<<endl;
				}
				else
				{
					cout<<col[0]<<endl;;
					indice--;
					for(int i=1;i<=indice;i++)
					{
						col[i-1] = col[i];
					}
				}
				break;
			}
			default: break;
		}
		//system("pause");
	}while(opc<3);
	return 0;
}
