#include <stdio.h>
#include <string.h>

// Definicao da estrutura Funcionario
typedef struct {
    char nome[100];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

// Funcao para preencher os campos da estrutura Funcionario
void preencheFuncionario(Funcionario *func) {
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]%*c", func->nome); // Le uma linha inteira, incluindo espacos
    printf("Digite o salario do funcionario: ");
    scanf("%f", &func->salario);
    printf("Digite o identificador do funcionario: ");
    scanf("%d", &func->identificador);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]%*c", func->cargo); // Le uma linha inteira, incluindo espacos
}

// Funcao para imprimir os valores dos campos da estrutura Funcionario
void imprimeFuncionario(const Funcionario *func) {
    printf("Nome: %s\n", func->nome);
    printf("Salario: %.2f\n", func->salario);
    printf("Identificador: %d\n", func->identificador);
    printf("Cargo: %s\n", func->cargo);
}

// Funcao para alterar o salario de uma estrutura Funcionario
void alteraSalario(Funcionario *func, float novoSalario) {
    func->salario = novoSalario;
}

// Funcao para imprimir o cargo e salario do funcionario com maior e menor salario
void imprimeMaiorMenorSalario(Funcionario *funcs, int n) {
    if (n <= 0) {
        printf("Nao ha funcionarios no vetor.\n");
        return;
    }

    int indiceMaior = 0;
    int indiceMenor = 0;
    
    for (int i = 1; i < n; i++) {
        if (funcs[i].salario > funcs[indiceMaior].salario) {
            indiceMaior = i;
        }
        if (funcs[i].salario < funcs[indiceMenor].salario) {
            indiceMenor = i;
        }
    }

    printf("Funcionario com maior salario:\n");
    printf("Cargo: %s\n", funcs[indiceMaior].cargo);
    printf("Salario: %.2f\n", funcs[indiceMaior].salario);

    printf("Funcionario com menor salario:\n");
    printf("Cargo: %s\n", funcs[indiceMenor].cargo);
    printf("Salario: %.2f\n", funcs[indiceMenor].salario);
}

int main() {
    Funcionario funcionarios[3];
    
    // Preenche dados dos funcionarios
    for (int i = 0; i < 3; i++) {
        printf("Funcionario %d:\n", i + 1);
        preencheFuncionario(&funcionarios[i]);
    }

    // Imprime dados dos funcionarios
    for (int i = 0; i < 3; i++) {
        printf("\nDados do Funcionario %d:\n", i + 1);
        imprimeFuncionario(&funcionarios[i]);
    }

    // Altera o salario do primeiro funcionario
    alteraSalario(&funcionarios[0], 5000.0);
    printf("\nDados do Funcionario 1 apos alteracao de salario:\n");
    imprimeFuncionario(&funcionarios[0]);

    // Imprime o cargo e salario do funcionario com maior e menor salario
    printf("\nFuncionario com maior e menor salario:\n");
    imprimeMaiorMenorSalario(funcionarios, 3);

    return 0;
}