#include <stdio.h>
#include <string.h>

// Definicao da estrutura Pessoa
typedef struct {
    char nome[100];
    char documento[20];
    int idade;
} Pessoa;

// Funcao para preencher os campos da estrutura Pessoa
void preenchePessoa(Pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]%*c", pessoa->nome); // Le uma linha inteira, incluindo espacos
    printf("Digite o numero do documento: ");
    scanf(" %[^\n]%*c", pessoa->documento); // Le uma linha inteira, incluindo espacos
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa->idade);
}

// Funcao para imprimir os valores dos campos da estrutura Pessoa
void imprimePessoa(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Documento: %s\n", pessoa->documento);
    printf("Idade: %d\n", pessoa->idade);
}

// Funcao para atualizar a idade de uma estrutura Pessoa
void atualizaIdade(Pessoa *pessoa, int novaIdade) {
    pessoa->idade = novaIdade;
}

// Funcao para imprimir o nome da pessoa mais velha e mais nova
void imprimeMaisVelhaMaisNova(Pessoa *pessoas, int n) {
    if (n <= 0) {
        printf("Nao ha pessoas no vetor.\n");
        return;
    }

    int indiceMaisVelha = 0;
    int indiceMaisNova = 0;
    
    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade > pessoas[indiceMaisVelha].idade) {
            indiceMaisVelha = i;
        }
        if (pessoas[i].idade < pessoas[indiceMaisNova].idade) {
            indiceMaisNova = i;
        }
    }

    printf("Pessoa mais velha:\n");
    printf("Nome: %s\n", pessoas[indiceMaisVelha].nome);
    printf("Idade: %d\n", pessoas[indiceMaisVelha].idade);

    printf("Pessoa mais nova:\n");
    printf("Nome: %s\n", pessoas[indiceMaisNova].nome);
    printf("Idade: %d\n", pessoas[indiceMaisNova].idade);
}

int main() {
    Pessoa pessoas[3];
    
    // Preenche dados das pessoas
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i + 1);
        preenchePessoa(&pessoas[i]);
    }

    // Imprime dados das pessoas
    for (int i = 0; i < 3; i++) {
        printf("\nDados da Pessoa %d:\n", i + 1);
        imprimePessoa(&pessoas[i]);
    }

    // Atualiza a idade da primeira pessoa
    atualizaIdade(&pessoas[0], 30);
    printf("\nDados da Pessoa 1 apos atualizacao de idade:\n");
    imprimePessoa(&pessoas[0]);

    // Imprime o nome da pessoa mais velha e mais nova
    printf("\nPessoa mais velha e mais nova:\n");
    imprimeMaisVelhaMaisNova(pessoas, 3);

    return 0;
}