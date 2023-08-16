#include <stdio.h>
#include <string.h>

#define INDICE_ROMANO 13
const char *letra_romanos [INDICE_ROMANO]={"I","IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int val_romanos [INDICE_ROMANO]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

void imprime_conversor(int valor_algarismo);
void conversor(int n);

int main (void){
    int n = 0;
    scanf("%i", &n);
    conversor(n);
    return 0;
}
void conversor(int n){
    int val [4];
    val[3] = n;
    for (int i = 0; i < 3; i++)
        val[i] = 0;
    for (int j = 3, k = 2, i = 1000; k >= 0;j--, k--, i /= 10){
        val[k] = val[j]%i;
        val[j] -= val[k];
    }
    for (int i = 3; i > -1; i--){
        imprime_conversor(val[i]);
    }
    
}
void imprime_conversor(int valor_algarismo){
    int n = INDICE_ROMANO - 2;
    int acc = 0;
    while (n >= 1){
        if (valor_algarismo == 0) return;
        if (valor_algarismo < val_romanos[n] && valor_algarismo >= val_romanos[n-1]){
            while (acc != valor_algarismo){
                printf ("%s", letra_romanos[n-1]);
                acc += val_romanos[n-1];
            }
            return;
        }
        if (valor_algarismo == val_romanos[n]){
            printf ("%s", letra_romanos[n]);
            return;
        }
        if (valor_algarismo == val_romanos[n+1]){
            printf ("%s", letra_romanos[n+1]);
            return;
        }
        n -= 2;
    }   
}