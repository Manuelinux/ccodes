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
bool eofile();
bool wsp();
bool naturales();

type lexer();   

extern FILE *actual;
extern FILE *busqueda;

/*---------------------------------------------------------------------------------------*/








/*-----------------------------------------------------------------------------------*/

void retroceso(){ fseek (busqueda, -1, SEEK_CUR); }
char siguiente(){return fgetc(busqueda);  }
void acepta(){ fseek (actual, ftell(busqueda), SEEK_SET); }
void falla(){ fseek (busqueda, ftell(actual), SEEK_SET); }

type lexer(){   
    
    while(wsp());

    if(identificador()) return _id;
    else if(naturales()) return _nat;
    else if(hexadecimales()) return _hex;
    else if(eofile()) return _eof;

    return _error;
}

