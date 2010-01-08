
#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
	char c;
	do
	{
		c=toupper(getchar());         //toupper es para convertir a mayusculas  tolower a minusculas
		if(c==' ')
		{
			cout<<c;
			c=65;
		}
		else
		{
			if(c<78)
			{
				c=90-(13-(78-c));
				cout<<c;
			}
			else
			{
				c=65+(12-(c-78));
				cout<<c;
			}
		}
	}while((c<91));
	return 0;
}
