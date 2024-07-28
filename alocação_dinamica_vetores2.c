#include <stdio.h>
#define NUM_ALUNOS 10

int main() {
    int N;  // Número de questões
    printf("Informe o número de questões: ");
    scanf("%d", &N);

    char gabarito[N];
    printf("Informe o gabarito da prova: ");
    for (int i = 0; i < N; i++) {
        scanf(" %c", &gabarito[i]); // O espaço antes de %c é para ignorar espaços em branco
    }

    char respostas[NUM_ALUNOS][N];
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Informe as respostas do aluno %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf(" %c", &respostas[i][j]); // O espaço antes de %c é para ignorar espaços em branco
        }
    }

    double pontosPorQuestao = 10.0 / N;
    double notas[NUM_ALUNOS] = {0};
    int aprovados = 0;

    // Calcular a nota de cada aluno
    for (int i = 0; i < NUM_ALUNOS; i++) {
        double nota = 0;
        for (int j = 0; j < N; j++) {
            if (respostas[i][j] == gabarito[j]) {
                nota += pontosPorQuestao;
            }
        }
        notas[i] = nota;
        if (nota >= 6) {
            aprovados++;
        }
    }

    // Exibir a nota de cada aluno
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
    }

    // Calcular e exibir a porcentagem de aprovação
    double porcentagemAprovacao = (double)aprovados / NUM_ALUNOS * 100;
    printf("Porcentagem de aprovacao: %.2f%%\n", porcentagemAprovacao);

    return 0;
}