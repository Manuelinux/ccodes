#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
main()
{
  char s[20]={NULL}; int i,j;
  
  int r,max=1,c=0;
  for(i=100;i<=999;i++)
  {
   for(j=100;j<=999;j++)
   {
 
    r=i*j;
    sprintf(s,"%d",r);
    if(s[0]==s[strlen(s)-1])
    {
    char reversed[20]={NULL};
    int z=strlen(s)-1,y=0;
    for(z;z>=0;z--)
    {
     reversed[y]=s[z]; y++;
     }
     if(strcmp(s,reversed)==0)
     {
     if(r>max)
      max=r;
     }
    }
   }
  }
  
  cout<<"El resultado es: "<<max<<endl;
  return 0;
}
