# include <stdio.h>
# include <ctype.h>
# include "types.h"

# define UDEF -1

typedef int estado;

void retroceso();
char siguiente();
void acepta();
void falla();

bool identificador();
bool eof();
bool esp_blanco();
bool naturales();
bool octal();
bool isCarOctal(char c);
bool hexadecimal();
bool parent_izq();

type lexico();   

extern FILE *actual;
extern FILE *busqueda;

/*--------------------------identificadores-------------------------------------------------------------*/

bool identificador(){                            //hex, oct,nat, y flot
     
     estado estado_anterior, estado_actual = 0;
      

     while(estado_actual !=UDEF){
     
     estado_anterior = estado_actual;
     char c = siguiente();
     
        switch (estado_actual){
            
            case 0:
                 if(c=='_') estado_actual =1;
                 else if(isalpha(c)) estado_actual = 2;
                 else estado_actual = UDEF;
                 break;                 
                 
            case 1:    
                 if(isdigit(c) || c == '_');
                 else if(isalpha(c)) estado_actual = 2;
                 else estado_actual = UDEF;          
                 break;                              
                              
            case 2:    
                 
                // if (isdigit(c)|| isalpha(c) || c == '_');
                 if (isalnum (c) || c == '_');
                 else estado_actual = UDEF;                                                       

        }          
     }

    if (estado_anterior == 2){
        retroceso();
        acepta();
        return true;

    } 
    else{
       falla();
       return false;
   }
}
/*------------------------espacio en blanco-------------------------------------------------------*/


bool esp_blanco(){

     if(isspace(siguiente())){ 
        acepta();
        return true;
     }
     
     else{
        falla();
        return false;
    }
}
/*-------------------------------numeros hexadecimales-----------------------------------------------------------------*/
bool isCarHex(char c){
       return (c=='A'||c=='a'||c=='B'||c=='b'||c=='C'||c=='c'||c=='D'||c=='d'||c=='E'||c=='e'||c=='F'||c=='f');
     }
     
bool hexadecimal(){
 
     estado estado_anterior, estado_actual = 0;

     while(estado_actual !=UDEF){

     estado_anterior = estado_actual;
     char c = siguiente();
     
        switch (estado_actual){
            
            case 0:  
                    if(c=='0') estado_actual = 1;
                    else estado_actual = UDEF;
                    break;
            case 1:                                                     
                    if((c=='X')||(c=='x')) estado_actual = 2;
                    else estado_actual = UDEF;
                    break;
            case 2: 
                    if ((isdigit(c))||(isCarHex(c))) estado_actual = 3;
                    else estado_actual = UDEF;
                    break;
            case 3: 
                    if ((isdigit(c))||(isCarHex(c)));
                    else estado_actual = UDEF;
                    break;

        }          
     }

    if (estado_anterior == 1){
        retroceso();
        acepta();
        return true;
    } 

    else{
      falla();
       return false;
   }
}

/*----------------------------numeros octales---------------------------------------------*/
bool isCarOctal(char c){
     return (c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'||c=='7');
     }

bool octal(){  //debe comenzar con  0
 
     estado estado_anterior, estado_actual = 0;

     while(estado_actual !=UDEF){

     estado_anterior = estado_actual;
     char c = siguiente();
     
        switch (estado_actual){
               
           case 0:
                  if (c=='0') estado_actual=1;
                  else estado_actual=UDEF;
                  break;
           
           case 1:
                   if (isCarOctal(c))estado_actual=2;
                   else estado_actual=UDEF;
                   break;
           
           case 2: if (isCarOctal(c) ||    c=='0' );
                   else estado_actual=UDEF;
                   
        }
     }
     
     if (estado_actual== 2){
       retroceso();
       acepta();
       return true;
      }
      
      else {
         falla();
         return false; 
      
      }
}
       



/*----------------------------numeros naturales----------------------------------------------------------------*/

bool naturales(){  //no debe tener 0
 
     estado estado_anterior, estado_actual = 0;
    

     while(estado_actual !=UDEF){

     estado_anterior = estado_actual;
     char c = siguiente();
     
        switch (estado_actual){
            
            case 0: 
                    if(isdigit(c)&& c!='0') estado_actual = 1;
                    else estado_actual = UDEF;
                    break;
            case 1:                                                    
                    if(isdigit(c));
                    else estado_actual = UDEF;
        }          
     }




    if (estado_anterior == 1){
        retroceso();
        acepta();
        
        return true;
    } 

    else{
       falla();
       return false;
   }
}
/*-------------------------------------fin de archivo----------------------------------------------*/

bool eof(){

     if(siguiente()==EOF){
        acepta();
        return true;
     }
     
     else{
        falla();
        return false;
    }
}



       
 
 /*-------------------------------parentesis izquierdo------------------------------------------*/                        

bool parent_izq(){
     
     estado estado_anterior, estado_actual = 0;

     while(estado_actual !=UDEF){
     
     estado_anterior = estado_actual;
     char c = siguiente();
     
        switch (estado_actual){
               
            
            case 0:
                 if(c=='(') estado_actual =1;
                 else estado_actual = UDEF;
                 break;  
            
            case 1:
                 if (c=='(');
                 else estado_anterior=estado_actual;
                 break;
                 }
                 }
                 
          if (estado_anterior==1){
              retroceso();
              acepta();
			  return true;
           } 
           
          else{
       falla();
       return false;
   }
}

                                   







/*-------------------------------------------------------------------------*/

void retroceso(){ fseek (busqueda, -1, SEEK_CUR); }
char siguiente(){return fgetc(busqueda);  }
void acepta(){ fseek (actual, ftell(busqueda), SEEK_SET); }
void falla(){ fseek (busqueda, ftell(actual), SEEK_SET); }

type lexico(){   
    
    while(esp_blanco());

    if(identificador()) return _id;
    else if(naturales()) return _nat;
    else if(octal()) return _oct;
    else if(eof()) return _eof;
    else if (hexadecimal()) return _hex;
    else if (parent_izq()) return _parent_izq;

    return _error;
}

