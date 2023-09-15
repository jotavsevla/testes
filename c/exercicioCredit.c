#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* get_card (){
    long int cartao;
    scanf ("%li", &cartao); //optamos por transformar 2x para que o usuario nao pudesse poluir o vetor com outros char's
    long int count = cartao;
    int i;
    for (i =0; count > 0; i++) count /= 10;
    char* string_de_numeros = malloc (sizeof(char) * i);
    sprintf (string_de_numeros, "%li", cartao);
    string_de_numeros [i] = '\0';
    return string_de_numeros;
}
void invalido(){
    printf ("Cartao invalido\n");
    exit(0);
}

void validar_bandeira (int inicial){
    printf ("Cartao valido com ");
    switch(inicial){
        case 3: printf("bandeira do tipo American Express\n");
            break;
        case 4: printf("bandeira do tipo Visa\n");
            break;
        case 5: printf("bandeira do tipo Master Card\n");
            break;
    }
    return;
}
void soma_algarismos (char* cartao_em_string){
    int n = strlen (cartao_em_string);
    int cartao_em_numero [n];
    for (int i = 0; i < n; i++)
        cartao_em_numero [i] = cartao_em_string [i] - '0';
    int inicial = cartao_em_numero[0];

    int acumulador = 0;
    for (int i = n - 2; i >= 0; i -= 2){
        if (cartao_em_numero[i] >= 5){
            cartao_em_numero[i] -= 5;
            acumulador++;
        }
        acumulador += (cartao_em_numero[i] * 2);
    }
    for (int i = n - 1; i >= 0; i -= 2) acumulador += cartao_em_numero[i];
    printf("Acumulador: %i\n", acumulador);
    acumulador % 10 == 0 ? validar_bandeira(inicial) : invalido();
    return;
}
int main (void){
    soma_algarismos(get_card());
    return 0;
}