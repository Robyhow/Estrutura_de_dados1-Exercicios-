#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    // Solicita o tamanho do vetor ao usuário
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Aloca dinamicamente memória para armazenar o vetor
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Solicita os elementos do vetor ao usuário
    printf("Informe os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Imprime os elementos na ordem inversa
    printf("Elementos do vetor na ordem inversa:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    return 0;
}