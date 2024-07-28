#include <stdio.h>

int main() {
    int N;
    printf("Informe o número de pessoas entrevistadas: ");
    scanf("%d", &N);

    char sexo[N];
    char opiniao[N];

    // Leitura das respostas
    for (int i = 0; i < N; i++) {
        printf("Informe o sexo da pessoa %d (M/F): ", i + 1);
        scanf(" %c", &sexo[i]); // O espaço antes de %c é para ignorar espaços em branco
        
        printf("A pessoa %d gostou do produto? (S/N): ", i + 1);
        scanf(" %c", &opiniao[i]); // O espaço antes de %c é para ignorar espaços em branco
    }

    // Cálculo das porcentagens
    int totalFeminino = 0, totalMasculino = 0;
    int gostouFeminino = 0, naoGostouMasculino = 0;

    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'F' || sexo[i] == 'f') {
            totalFeminino++;
            if (opiniao[i] == 'S' || opiniao[i] == 's') {
                gostouFeminino++;
            }
        } else if (sexo[i] == 'M' || sexo[i] == 'm') {
            totalMasculino++;
            if (opiniao[i] == 'N' || opiniao[i] == 'n') {
                naoGostouMasculino++;
            }
        }
    }

    double porcentagemGostouFeminino = 0;
    double porcentagemNaoGostouMasculino = 0;

    if (totalFeminino > 0) {
        porcentagemGostouFeminino = (double)gostouFeminino / totalFeminino * 100;
    }

    if (totalMasculino > 0) {
        porcentagemNaoGostouMasculino = (double)naoGostouMasculino / totalMasculino * 100;
    }

    printf("Porcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n", porcentagemGostouFeminino);
    printf("Porcentagem de pessoas do sexo masculino que não gostaram do produto: %.2f%%\n", porcentagemNaoGostouMasculino);

    return 0;
}