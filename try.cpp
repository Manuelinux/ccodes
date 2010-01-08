#include <stdio.h>
#include <stdlib.h>

void pedir_numero(int &num);
void obtener_binario(int num, int bin[]);
void mostrar_binario(int tamano, int bin[]);

int main(){
    int numero;
    int vector[0];
    pedir_numero(numero);
    obtener_binario(numero, vector);
    //system("pause");
}

void pedir_numero(int &num){
     printf("Teclea un Numero de 0 a 256. \n");
     printf("Cual es tu numero: ");
     scanf("%d", &num);
}

void obtener_binario(int num, int bin[]){
      int i = 0;
      while(num > 0){
                bin[i] = (num % 2);
                num = (num / 2);
                i++;
      }
      mostrar_binario(i, bin);
}

void mostrar_binario(int tamano, int bin[]){
     printf("El numero Binario es: ");
     for(tamano; tamano >= 0 ; tamano--){
		printf ("%d", bin[tamano]);
     }
     printf("\n");
}
