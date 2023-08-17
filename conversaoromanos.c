#include <stdio.h>
#include <string.h>

#define INDICE_ROMANO 13
const char *letra_romanos [INDICE_ROMANO]={"I","IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int val_romanos [INDICE_ROMANO]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

void imprime_romano (int valor_algarismo){
    for (int i = INDICE_ROMANO - 1; i >= 0 ;){
        if (valor_algarismo-val_romanos[i] < 0)
            i--;
        else {
            printf ("%s", letra_romanos[i]);
            valor_algarismo -= val_romanos[i];
        }
    }
}
int main (void){
    int n = 0;
    scanf("%i", &n);
    imprime_romano (n);
    return 0;
}