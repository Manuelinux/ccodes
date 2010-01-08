#include <iostream>

using namespace std;

 

class Fibonacci{

      private:

           short *vector, maximo;

           

          

      public:

           Fibonacci(short tam);

           ~Fibonacci();

           void valor (short n,short &val);
           short fib(short n);

          

   };

  

   Fibonacci::Fibonacci(short tam){

     vector = new short[tam];

     maximo=tam;

    

     for (short i=0; i<maximo; i++){

        vector [i]=fib(i); // fibonacci

               

         }

                             

      }

     

      Fibonacci::~Fibonacci(){

      delete [] vector;

     }

    

    

   void Fibonacci::valor (short n,

                   short &val){

        if (n>=maximo) {               //n>=maximo

           val=vector[n];

        }else{

            val=fib (n);

        }

            //return val;

                    

   }

  

   short Fibonacci::fib (short n){

         short i=1,j=0,t;

         for (short k=1; k<=n; k++){

                   

              t=i+j;

              i=j;

              j=t;

             

             

           }

            return j;

           

       }

      

      

   int main (){

     Fibonacci f(5);

     short numero;

     int i;

    

     for(i=0; i<5;i++){

                

        f.valor (i, numero);

        cout <<i<<":__" <<numero

              <<endl;

     }

     numero=f.fib (5);

     cout <<"5:__"<<numero<<endl;

          

           return 0;

    

     }    
