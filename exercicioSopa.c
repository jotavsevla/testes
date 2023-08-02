#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int ml1 = 0;
int ml2 = 25;
int ml3 = 50;
int ml4 = 75;
int ml5 = 100;

typedef struct pote{
    int sopaA, sopaB;
}pote;


void remove (pote* balde, int removeA, int removeB){
    if (balde->sopaA < removeA || balde->sopaB < removeB)
        return; 
    balde->sopaA -= removeA;
    balde->sopaB -= removeB;
    return;
}
int main (void){
    int n;
    scanf("%i", &n);

    pote balde;
    balde.sopaA = balde.sopaB = n;

    time_t t;
    time(&t);
    unsigned int op = (unsigned int)t;
    srand(op);
    int per100 [3]; 
    for (int i = 0; i < 3; i++)
        per100 [i] = 0;

    // 0 A primeiro
    // 1 A e B juntos
    // 2 B primeiro

    /*Sirva 100ml de sopa A e 0ml de sopa B ,
    Sirva 75ml de sopa A e 25ml de sopa B ,    
    Sirva 50ml de sopa A e 50ml de sopa B , e
    Sirva 25ml de sopa A e 75ml de sopa B .*/

    for (int i = 0; i < 100; i++){
        while (balde.sopaA > 0 && balde.sopaB > 0){
            op = rand() % 4;
            switch (op){
                case 0: remove (&balde, ml5, ml1);    // int ml1 0
                    break;                            // int ml2 25
                case 1: remove (&balde, ml4, ml2);    // int ml3 50
                    break;                            // int ml4 75
                case 2: remove (&balde, ml3, ml3);    // int ml5 100
                    break;
                case 3: remove (&balde, ml2, ml4);
                    break;
                default:
                    break;
            }
        }

        if (balde.sopaA == 0 && balde.sopaB > 0)
            per100[0] += 1;
        if (balde.sopaA == 0 && balde.sopaB == 0)
            per100 [1] += 1;
        if (balde.sopaA > 0 && balde.sopaB == 0)
            per100[2] += 1;
        
        balde.sopaA = balde.sopaB = n;

    }
    printf( "chances onde ml totais sao %i sao de A %i, A e B %i e so B %i ", n, per100[0], per100[1], per100[2]);

    return 0;

}