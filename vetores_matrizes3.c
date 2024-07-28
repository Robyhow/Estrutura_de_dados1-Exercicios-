#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    // Solicita o número de ordem da matriz ao usuário
    printf("Informe o tamanho da matriz quadrada (n): ");
    scanf("%d", &n);

    // Aloca dinamicamente a memória para a matriz quadrada de ordem n
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Verifica se a alocação foi bem-sucedida
    if (matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche a matriz com números aleatórios entre 1 e 100
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    // Imprime a matriz resultante
    printf("Matriz resultante:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}