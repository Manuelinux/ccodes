#include <stdio.h>
#include <stdlib.h> 
void pedir_numero(int *num);
int obtener_binario(int num, int bin[]);
 
int main(){
    int numero;
    int vector[0];
    pedir_numero(numero);
    printf("asdasd %d", obtener_binario(numero, vector));
    system("pause");
}
 
void pedir_numero(int &num){
     printf("Teclea un Numero de 0 a 256. \n");
     printf("Cual es tu numero: ");
     scanf("%d", &num);
}
 
int obtener_binario(int num, int bin[]){
      while(num > 0){
                int i = 0;
                if (num == 1){
                        bin[i] = num;
                        return bin[i];
                }
      }
}
