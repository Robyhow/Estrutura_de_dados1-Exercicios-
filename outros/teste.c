#include <stdio.h>

#define MAX 100

typedef struct {
    char nome[MAX];
    char documento[MAX];
    int idade;
    char genero;
} Pessoa;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerNovaLinha(char *str) {
    while (*str) {
        if (*str == '\n') {
            *str = '\0';
            break;
        }
        str++;
    }
}

void preencherPessoa(Pessoa *p) {
    printf("Digite o nome: ");
    fgets(p->nome, MAX, stdin);
    removerNovaLinha(p->nome);

    printf("Digite o documento (RG, CPF, Passaporte, Num. SUS): ");
    fgets(p->documento, MAX, stdin);
    removerNovaLinha(p->documento);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    limparBuffer(); // Limpa o buffer de entrada

    printf("Digite o gênero (M/F): ");
    scanf("%c", &p->genero);
    limparBuffer(); // Limpa o buffer de entrada
}

void imprimirPessoa(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d\n", p->idade);
    printf("Gênero: %c\n", p->genero);
}

void atualizarIdade(Pessoa *p, int novaIdade) {
    p->idade = novaIdade;
}

void encontrarMaisVelhoMaisNovo(Pessoa pessoas[], int n) {
    if (n <= 0) return;

    Pessoa *maisVelho = &pessoas[0];
    Pessoa *maisNovo = &pessoas[0];

    for (int i = 1; i < n; ++i) {
        if (pessoas[i].idade > maisVelho->idade) {
            maisVelho = &pessoas[i];
        }
        if (pessoas[i].idade < maisNovo->idade) {
            maisNovo = &pessoas[i];
        }
    }

    printf("Pessoa mais velha:\n");
    printf("Nome: %s\n", maisVelho->nome);
    printf("Gênero: %c\n", maisVelho->genero);

    printf("Pessoa mais nova:\n");
    printf("Nome: %s\n", maisNovo->nome);
    printf("Gênero: %c\n", maisNovo->genero);
}

int main() {
    Pessoa p1, p2, p3;
    preencherPessoa(&p1);
    imprimirPessoa(&p1);

    printf("\nAtualizando idade...\n");
    atualizarIdade(&p1, p1.idade + 1);
    imprimirPessoa(&p1);

    printf("\nPreenchendo mais duas pessoas...\n");
    preencherPessoa(&p2);
    preencherPessoa(&p3);

    Pessoa pessoas[3] = {p1, p2, p3};
    encontrarMaisVelhoMaisNovo(pessoas, 3);

    return 0;
}