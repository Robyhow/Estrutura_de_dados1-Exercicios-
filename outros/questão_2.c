#include <stdio.h>

typedef enum {
    RG = 1,
    CPF,
    PASSAPORTE,
    SUS,
    MASCULINO = 1,
    FEMININO
} TipoDocumento;

typedef union {
    int rg[11];
    int cpf[11];
    int passaporte[11];
    int sus[15];
} Documento;

typedef struct {
    char nome[20];
    Documento documento;
    int idade;
    char genero[20]; 
} Pessoa;

void preenche_pessoa(Pessoa *pessoa) {
    int escolha;
    
    printf("Informe o nome: ");
    scanf("%s", pessoa->nome);
    
    printf("Informe a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Informe o gênero (MASCULINO/FEMININO): ");
    scanf("%s", pessoa->genero);
    
    printf("Escolha o tipo de documento (1-RG, 2-CPF, 3-Passaporte, 4-SUS): ");
    scanf("%d", &escolha);

    switch (escolha) {
        case RG:
            printf("Informe o RG: ");
            for (int i = 0; i < 11; i++) {
                scanf("%d", &pessoa->documento.rg[i]);
            }
            break; 
        case CPF:
            printf("Informe o CPF: ");
            for (int i = 0; i < 11; i++) {
                scanf("%d", &pessoa->documento.cpf[i]);
            }
            break;
        case PASSAPORTE:
            printf("Informe o Passaporte: ");
            for (int i = 0; i < 11; i++) {
                scanf("%d", &pessoa->documento.passaporte[i]);
            }
            break;
        case SUS:
            printf("Informe o Número SUS: ");
            for (int i = 0; i < 15; i++) {
                scanf("%d", &pessoa->documento.sus[i]);
            }
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

void imprimir_pessoa(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Gênero: %s\n", pessoa->genero);
    
    printf("Documento: ");
    for (int i = 0; i < 11; i++) {
        printf("%d\n", pessoa->documento.rg[i]);
    }
    printf("\n");
}

void atualizar_idade(Pessoa *pessoa, int novaIdade) {
    pessoa->idade = novaIdade;
}

void encontrar_mais_velho_mais_novo(Pessoa pessoas[], int n) {
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
    printf("Gênero: %s\n", maisVelho->genero);

    printf("Pessoa mais nova:\n");
    printf("Nome: %s\n", maisNovo->nome);
    printf("Gênero: %s\n", maisNovo->genero);
}

int main() {
    Pessoa p1, p2, p3;
    printf("Preenchendo dados da primeira pessoa:\n");
    preenche_pessoa(&p1);
    imprimir_pessoa(&p1);

    printf("\nAtualizando idade...\n");
    atualizar_idade(&p1, p1.idade + 1);
    imprimir_pessoa(&p1);

    printf("\nPreenchendo dados de mais duas pessoas:\n");
    preenche_pessoa(&p2);
    preenche_pessoa(&p3);

    Pessoa pessoas[3] = {p1, p2, p3};
    encontrar_mais_velho_mais_novo(pessoas, 3);

    return 0;
}