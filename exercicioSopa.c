#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LOOP_MAX 1000

int ml1 = 0;
int ml2 = 25;
int ml3 = 50;
int ml4 = 75;
int ml5 = 100;

typedef struct pote{
    int sopaA, sopaB;
}pote;


void remover (pote* balde, int removeA, int removeB){
    if (balde->sopaA < removeA || balde->sopaB < removeB)
        return; 
    balde->sopaA -= removeA;
    balde->sopaB -= removeB;
    return;
}
int main (void){
    while(true){
    int jotinhaquerparar = 0;
    printf("Jotinha quer parar?(se quiser digita -1)\n");
    scanf("%i\n",&jotinhaquerparar);
    if(jotinhaquerparar == -1)break;

    int n;
    scanf("%i", &n);

    pote balde;
    balde.sopaA = balde.sopaB = n;

    time_t t;
    time(&t);
    unsigned int op = (unsigned int)t;
    
    srand(op);
    int vezes [3]; 
    
    for (int i = 0; i < 3; i++)
        vezes [i] = 0;

    // 0 A primeiro
    // 1 A e B juntos
    // 2 B primeiro

    /*Sirva 100ml de sopa A e 0ml de sopa B ,
    Sirva 75ml de sopa A e 25ml de sopa B ,    
    Sirva 50ml de sopa A e 50ml de sopa B , e
    Sirva 25ml de sopa A e 75ml de sopa B .*/

    for (int i = 0; i < LOOP_MAX; i++){
        while (balde.sopaA > 0 && balde.sopaB > 0){
            op = rand() % 4;
            switch (op){
                case 0: remover (&balde, ml5, ml1);    // int ml1 0
                    break;                            // int ml2 25
                case 1: remover (&balde, ml4, ml2);    // int ml3 50
                    break;                            // int ml4 75
                case 2: remover (&balde, ml3, ml3);    // int ml5 100
                    break;
                case 3: remover (&balde, ml2, ml4);
                    break;
                default:
                    break;
            }
        }

        //    LOOP_MAX -- 100 %
        //    vezes[i]--  x %

        if (balde.sopaA == 0 && balde.sopaB > 0)
            vezes[0] += 1;
        if (balde.sopaA == 0 && balde.sopaB == 0)
            vezes [1] += 1;
        if (balde.sopaA > 0 && balde.sopaB == 0)
            vezes[2] += 1;
        
        balde.sopaA = balde.sopaB = n;

    }
    double pr100[3];
    for (int i = 0; i < 3; i++){
        pr100[i] = (double) vezes[i] / LOOP_MAX;
        pr100[i] *= 100;
    }

    printf( " onde ml totais sao %i as chances sao de somente A primeiro %.2f,\n A e B juntos %.2f \n somente B primeiro %.2f \n\n", n, pr100[0], pr100[1], pr100[2]);

    }
    return 0;

}