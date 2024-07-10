#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define mxN 20

void imprime(int* vetor){
    for(int i = 0; i < mxN; i++)
        printf("%i ", vetor[i]);
    
    printf("\n");

}
// indice meio é o último valor da parte esquerda e meio+1 representa o primeiro valor da segunda metade
// inicio é primeiro posiçao da primeira parte e fim é, efetivamente, a ultima posiçao da segunda parte
void merge(int vetor [], int inicio, int meio, int fim){
    int* copia = malloc(sizeof(fim-inicio+1));
    int count_inicio, count_meio, count_sort;
    count_inicio = inicio; count_meio = meio + 1; count_sort = inicio;

    for(int i = 0; i <= fim; ++i)
        copia[i] = vetor[i];
    
    while(count_inicio <= meio && count_meio <= fim){
        if( copia[count_inicio] < copia[count_meio]){
            vetor[count_sort] =  copia [count_inicio];
            count_inicio++;
        }
        else{
            vetor[count_sort] = copia[count_meio];
            count_meio++;
        }
            count_sort++;
    }

    while(count_inicio <= meio){
        vetor[count_sort] =  copia [count_inicio];
        count_inicio++;
        count_sort++;
    }
    while (count_meio <= fim){
        vetor[count_sort] = copia[count_meio];
        count_meio++;
        count_sort++;
    }

    return;
}
void merge_aux (int vetor[],int inicio, int fim){
    if(fim - inicio < 1) return;
    int meio = (inicio + fim)/2;
    merge_aux(vetor, inicio, meio);
    merge_aux(vetor, meio+1, fim);
    merge(vetor, inicio, meio, fim);
}
int* numeros_aleatorios (){
    int *valores = malloc (sizeof(int)* mxN);
    //int valores[mxN];
    srand(time(NULL));
    for (int i = mxN - 1; i >= 0; i--)
        valores[i] = rand() % 9;
    printf("\n");
    return valores;
}
int* vetor_controlado(){
    int* vet_definido = malloc (sizeof(int)*mxN);
    for(int i = 0; i < mxN; i++)
        scanf("%i", &vet_definido[i]);
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
