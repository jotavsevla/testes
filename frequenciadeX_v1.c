#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define mxN 5

typedef struct {
    int vzx;
    int numb;
} numero_repetido;
// formaçao de vetor de numeros menor que 100 1000 posiçoes
int* numeros_aleatorios (){
    int *valores = malloc (sizeof(int)* mxN);
    srand(time(NULL));
    for (int i = mxN - 1; i >= 0; i--){
        valores[i] = rand() % 100;
        printf ("%i ",valores[i]);
    }
    printf("\n");
    return valores;
}
void verifica_repeticoes(int* valores_aleatorios){
    int i, j;
    numero_repetido valores[2]; //atual mais repetido e atual
    valores[0].vzx = 1;
    valores[0].numb =  *valores_aleatorios;
    for (i = 0; i < mxN; i++){
        valores[1].numb = valores_aleatorios[i++];
        valores[1].vzx = 1;
        j = 0;
        for ( j += i++; j < mxN; j++) if (valores_aleatorios[i] == valores_aleatorios[j]) valores[1].vzx++;
        if (valores[0].vzx < valores[1].vzx){
            valores[0].numb = valores[1].numb;
            valores[0].vzx =  valores[1].vzx;
        }
    }
    printf("%i repetiu mais vezes, sendo elas %i\n ", valores[0].numb, valores[0].vzx);
}
int* vetor_controlado(){
    int* vet_definido = malloc (sizeof(int)*mxN);
    for(int i = 0; i < mxN; i++) scanf("%i", &vet_definido[i]);
    return vet_definido;
}

int main (){
    verifica_repeticoes(vetor_controlado()); //geraçao OK
    
    return 0;
}
