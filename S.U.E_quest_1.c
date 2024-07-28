#include <stdio.h>
#include <string.h>

// Definicao do enum para genero
typedef enum {
    MASCULINO,
    FEMININO
} Genero;

// Definicao da struct Pessoa
typedef struct {
    char nome[100];
    int idade;
    Genero genero;
} Pessoa;

// Funcao para ler os dados de uma pessoa
void lerPessoa(Pessoa *p) {
    char genero_str[10];
    printf("Digite o nome: ");
    scanf(" %[^\n]%*c", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    printf("Digite o genero (MASCULINO/FEMININO): ");
    scanf(" %s", genero_str);

    if (strcmp(genero_str, "MASCULINO") == 0) {
        p->genero = MASCULINO;
    } else if (strcmp(genero_str, "FEMININO") == 0) {
        p->genero = FEMININO;
    } else {
        printf("Genero invalido. Definindo como MASCULINO por padrao.\n");
        p->genero = MASCULINO;
    }
}

// Funcao para imprimir os dados de uma pessoa
void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Genero: %s\n", p.genero == MASCULINO ? "MASCULINO" : "FEMININO");
}

int main() {
    Pessoa p;
    lerPessoa(&p);
    imprimirPessoa(p);
    return 0;
}