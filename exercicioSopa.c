#include <stdio.h>
#include <stdlib.h>
    
double soupServings(int n) {
    if (n > 4451) {
        return 1.0; // 0.9999999999999999 podendo assim, arredondar para 1.0
    }
    n = (n + 24) / 25; // Arredondamento para cima
    double memo[n+1][n+1]; // Matriz de memoização
    for (int i = 0; i <= n; i++) { // Inicialização da matriz
        for (int j = 0; j <= n; j++) { 
            memo[i][j] = -1.0; // -1.0 significa que ainda não foi calculado
        }
    }

    double dp(int i, int j){
        if (memo[i][j] >= 0) { // Se já foi calculado, retorna o valor
            return memo[i][j];
        }
        if (i <= 0 && j <= 0) { // Se os dois ficarem vazios ao mesmo tempo, retorna 0.5
            return 0.5;
        }
        if (i <= 0) {
            return 1.0; // Se a sopa A ficar vazia primeiro, retorna 1.0
        }
        if (j <= 0) { // Se a sopa B ficar vazia primeiro, retorna 0.0
            return 0.0;
        }
        memo[i][j] = 0.25 * (dp(i - 4, j) + dp(i - 3, j - 1) + dp(i - 2, j - 2) + dp(i - 1, j - 3));
        return memo[i][j];
    }

    return dp(n, n);
}

int main() {
    int n = 100;
    double result = soupServings(n);
    printf("A probabilidade de a sopa A ficar vazia primeiro é: %f\n", result);
    return 0;
}
