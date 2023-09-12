#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define mxN 10

void imprime(int* vetor){
    for(int i = 0; i < mxN; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");

}
void merge(int vetor [], int inicio, int meio, int fim){
    int count_inicio = 0, count_meio = meio;
    int count_aux = 0;
    int *vet_aux;
    vet_aux = vetor;

    while (count_inicio < meio && count_meio <= fim){

        if (vet_aux [count_inicio] > vet_aux [count_meio]){
            vetor[count_aux] = vetor[count_meio];
            count_meio++;
        }

        else if (vet_aux [count_meio] > vet_aux [count_inicio]){
            vetor[count_aux] = vetor[count_inicio];
            count_inicio++;
        }
        
    }
    while (count_inicio < meio){
        vetor [count_aux] = vet_aux [count_inicio];
        count_inicio++;
    }
    while (count_meio <= fim){
        vetor [count_aux] = vet_aux [count_meio];
        count_meio++;
    }
    return ;
}
void merge_aux (int vetor[],int inicio, int fim){
    if(fim - inicio < 1) return;
    int meio = (inicio + fim)/2;
    merge_aux(vetor, inicio, meio-1);
    merge_aux(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);
}
int* numeros_aleatorios (){
    int *valores = malloc (sizeof(int)* mxN);
    //int valores[mxN];
    srand(time(NULL));
    for (int i = mxN - 1; i >= 0; i--){
        valores[i] = rand() % 5;
    }
    printf("\n");
    return valores;
}
int* vetor_controlado(){
    int* vet_definido = malloc (sizeof(int)*mxN);
    for(int i = 0; i < mxN; i++) scanf("%i", &vet_definido[i]);
    return vet_definido;
}
int main (void){
    int meio, inicio, fim;
    fim = mxN-1;
    inicio = 0;
    int* vetor = numeros_aleatorios();
    imprime(vetor);
    merge_aux(vetor, inicio, fim);
    imprime(vetor);
    return 0;
}