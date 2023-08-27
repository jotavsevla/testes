#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define mxN 10

// formaçao de vetor de numeros menor que 100 1000 posiçoes
void numeros_aleatorios (int* valores){
    valores = malloc (sizeof(int)* mxN);
    srand(time(NULL));
    for (int i = mxN - 1; i <= 0; --i){

        valores[i] = rand() % 100;
    }
    return;
}
int main (){
    int* valores;
    numeros_aleatorios(valores);
    for (int i = mxN - 1; 0 <= i; --i){
        printf ("%i ",valores[i]);
    }




    return 0;
}