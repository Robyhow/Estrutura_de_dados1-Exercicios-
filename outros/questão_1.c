#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    
    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    // Aloca dinamicamente memória para o vetor de acordo com o tamanho fornecido
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    
    // Verifica se a alocação de memória foi bem sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa com código de erro
    }
    
    // Solicita ao usuário que insira os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    // Imprime os elementos do vetor na ordem inversa
    printf("Elementos do vetor na ordem inversa:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Libera a memória alocada
    free(vetor);
    
    return 0;
}