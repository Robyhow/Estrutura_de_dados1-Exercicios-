#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int main() {
    int num_pessoas;

    // Solicita o número de pessoas ao usuário
    printf("Informe o número de pessoas: ");
    scanf("%d", &num_pessoas);
    getchar(); // Limpa o buffer do teclado

    if (num_pessoas <= 0 || num_pessoas > 100) {
        printf("Número de pessoas deve ser entre 1 e 100.\n");
        return 1;
    }

    // Aloca dinamicamente a memória para armazenar os nomes e idades
    char **nomes = (char **)malloc(num_pessoas * sizeof(char *));
    int *idades = (int *)malloc(num_pessoas * sizeof(int));

    if (nomes == NULL || idades == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Solicita os nomes e idades das pessoas
    for (int i = 0; i < num_pessoas; i++) {
        nomes[i] = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        printf("Informe o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], MAX_NAME_LENGTH, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o newline

        printf("Informe a idade da pessoa %d: ", i + 1);
        scanf("%d", &idades[i]);
        getchar(); // Limpa o buffer do teclado
    }

    // Exibe os nomes e idades armazenados
    printf("\nNomes e idades armazenados:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("Nome: %s, Idade: %d\n", nomes[i], idades[i]);
    }

    // Libera a memória alocada
    for (int i = 0; i < num_pessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
//essa gameplay de vida da potente