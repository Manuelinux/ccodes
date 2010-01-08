#include<iostream>
#include<string.h>
using namespace std;
main()
{
 char s[20]={NULL},r[20]={NULL};
 int x;
 cout<<"introduce un numero";
 cin>>x;
 sprintf(s,"%d",x);
 int z=strlen(s);
 int i=z-1,y=0;
 for(i;i>=0;i--)
 {
  r[y]=s[i]; y++;
 }
 cout<<s<<endl;
 cout<<r<<endl;
 if(strcmp(s,r)==0){
 cout<<"si"<<endl;}
 return 0;
}
