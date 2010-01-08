#include <cstdlib>
#include <cstdio>
#include "types.h"
#include<iostream>
using namespace std;

FILE *actual;
FILE *busqueda;

 extern type lexico();  

int main(int n, char **arg){
	
    actual = fopen(arg[1],"rb");
    busqueda = actual;
    
    type token= lexico();
    
      while(token != _eof && token != _error){
        
        switch(token){
            case _id:
                printf("Encontre identificador\n");
                token = lexico();
                break;

                case _nat:
                printf("Encontre un numero natural\n");
                token = lexico();  
                break; 
                               
           case _oct:
                 printf("Encontre un numero octal\n");
                 token = lexico();  
                 break; 
           
           case _hex:
                printf("Encontre un numero hexadecimal\n");
                token = lexico();  
                break; 
                
            case _parent_izq:
                printf("\nEncontre un parentesis izqS");
                token = lexico();  
                break; 
                
                              
        
           
        }

    }
    
               if (token == _error) printf("encontre un error\n");
              else printf("Fin de archivo\n");

    fclose(actual);    // para cerrar
    fclose(busqueda);    

    system("PAUSE");
    return EXIT_SUCCESS;
}

    
    
    
