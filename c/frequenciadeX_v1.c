#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define mxN 1005

typedef struct {
    int vzx; // vezes repetidas
    int numb;// valor de referencia
} numero_repetido;
// formaçao de vetor de numeros menor que 100 1000 posiçoes
int* numeros_aleatorios (){
    int *valores = malloc (sizeof(int)* mxN);
    srand(time(NULL));
    for (int i = mxN - 1; i >= 0; i--){
        valores[i] = rand() % 5;
        printf ("%i ",valores[i]);
    }
    printf("\n");
    return valores;
}
void verifica_repeticoes(int valores_aleatorios[]){
    int i, j;
    numero_repetido mais_rep;
    numero_repetido atual; //atual_mais_repetido e atual
    mais_rep.vzx = 1;
    mais_rep.numb =  valores_aleatorios[0];
    for (i = 0; i < mxN - 1; i++){
        atual.numb = valores_aleatorios[i];
        atual.vzx = 1;
        j = 0;

        for ( j += i + 1; j < mxN; j++) 
            if (valores_aleatorios[i] == valores_aleatorios[j])
                atual.vzx++;

        if (mais_rep.vzx < atual.vzx){
            mais_rep.numb = atual.numb;
            mais_rep.vzx =  atual.vzx;
        for ( j += i++; j < 5; j++) if (valores_aleatorios[i] == valores_aleatorios[j]) valores[1].vzx++;
        if (valores[0].vzx < valores[1].vzx){
            valores[0].numb = valores[1].numb;
            valores[0].vzx =  valores[1].vzx;
        }
    }
    printf("%i repetiu mais vezes, sendo elas %i\n ", mais_rep.numb, mais_rep.vzx);
}
int* vetor_controlado(){
    int* vet_definido = malloc (sizeof(int)*5);
    for(int i = 0; i < 5; i++) scanf("%i", &vet_definido[i]);
    int* vet_definido = malloc (sizeof(int)*mxN);
    for(int i = 0; i < mxN; i++) scanf("%i", &vet_definido[i]);
    return vet_definido;
}

int main (){
    verifica_repeticoes(numeros_aleatorios()); //geraçao OK
    return 0;
}}
}