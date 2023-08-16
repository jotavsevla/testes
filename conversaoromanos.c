#include <stdio.h>
#include <string.h>

int indice_romano = 13;
const char *romanos [13]={"I","IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int romanos [13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
void conversor(int n){
    int val [4];
    val[3] = n;
    for (int i = 0; i < 3; i++)
        val[i] = 0;

    for (int i = 1000, j = 0; i > 0; i /= 10, j++) // Dividindo e armazenando fatores
        val[j] = (n / i) * i; // Calculando o fator de potência de 10
    for (int i = 3; i > 0; i--) 
        val[i] -= val[i - 1];
    for (int i = 3; i > -1; i--)
        imprime_romano(val[i]);
    
}
imprime_conversor(int valor_algarismo){
    int n = 0;
    while(n < indice_romano){
        if (romanos[n] == )
    }
}
void imprime_romano (int valor_algarismo){
    int k, acumulador;
    if(valor_algarismo >= 1000){
        k = valor_algarismo / 1000;
        acumulador = valor_algarismo / k; 
    }
    else if(valor_algarismo >= 100){
        k = valor_algarismo / 100;
        acumulador = valor_algarismo / k; 
    }
    else if(valor_algarismo >= 10){
        k = valor_algarismo / 10;
        acumulador = valor_algarismo / k;
         
    }
    else{ k = valor_algarismo;}
    if (k > 3 && k < 5 || k > 8 && k < 10){
        switch (valor_algarismo){
        case 4:
            
            break;
        case 9:
            break;
        case 40:
            break;
        case 90: 
        default:
            break;
        }
    }
    while (k != 0){

        switch (valor_algarismo){
            case 1: 
            printf ("%s", romanos[0]);
                break;
            printf ("%s", romanos[1]);
            case 4:
            printf ("%s", romanos[2]);
                break;
            case 5:
            printf ("%s", romanos[3]);
                break;
            case 10:
            printf ("%s", romanos[4]);
                break;
            case 40:
            printf ("%s", romanos[5]);
                break;
            case 50:
            printf ("%s", romanos[6]);
                break;
            case 90:
            printf ("%s", romanos[7]);   /*"I","IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"*/
                break;
            case 100:
            printf ("%s", romanos[8]);
                break;
            case 400:
            printf ("%s", romanos[9]);
                break;
            case 500:
            printf ("%s", romanos[10]);
                break;
            case 900:
            printf ("%s", romanos[11]);
                break;
            case 1000:
            printf ("%s", romanos[12]);
                break;
            default:
                break;
        }
    }
}

int main (void){
    int n = 0;
    scanf("%i", &n);
    conversor(n);
    return 0;
}