#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define mxN 5

void imprime(int* vetor){
    for(int i = 0; i < mxN; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");

}
// indice meio é o último valor da parte esquerda e meio+1 representa o primeiro valor da segunda metade
// inicio é primeiro posiçao da primeira parte e fim é, efetivamente, a ultima posiçao da segunda parte
void merge(int vetor [], int inicio, int meio, int fim){
    int count_inicio = inicio, count_meio = meio+1;
    int count_aux = 0;
    int *vet_aux = malloc (sizeof(int)*((fim-inicio)+1));
    //imprime(vet_aux);
   
    for (int i = 0; i <= fim; i++){
        vet_aux[i] = vetor[i];
    }
    // TODO: trocar passagem de referencia sendo atraves do aux para o vetor original
    while (count_inicio <= meio && count_meio <= fim){

        if (vet_aux [count_inicio] > vet_aux [count_meio]){
            vetor[count_aux] = vet_aux[count_meio];
            count_meio++;
        }

        else {
            vetor[count_aux] = vet_aux[count_inicio];
            count_inicio++;
        }
        count_aux++;
    }
    while (count_inicio <= meio){
        vetor[count_aux] = vet_aux[count_inicio];
        count_inicio++;
        count_aux++;

    }
    while (count_meio <= fim){
        vetor[count_aux] = vet_aux[count_meio];
        count_meio++;
        count_aux++;
    }
    imprime(vetor);
    return ;
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
    for (int i = mxN - 1; i >= 0; i--){
        valores[i] = rand() % 9;
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
    int* vetor = vetor_controlado();
    imprime(vetor);
    merge_aux(vetor, inicio, fim);
    imprime(vetor);
    return 0;
}