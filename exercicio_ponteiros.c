#include <stdio.h>
#include <math.h>

// Protótipo da função calcula_hexagono
void calcula_hexagono(float l, float *area, float *perimetro) {
    // Cálculo do perímetro
    *perimetro = 6 * l;
    
    // Cálculo da área
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
}

int main() {
    float lado, area, perimetro;

    // Solicita ao usuário o comprimento do lado do hexágono
    printf("Digite o comprimento do lado do hexagono: ");
    scanf("%f", &lado);

    // Chama a função para calcular área e perímetro
    calcula_hexagono(lado, &area, &perimetro);

    // Exibe os resultados
    printf("Area do hexagono: %.2f\n", area);
    printf("Perimetro do hexagono: %.2f\n", perimetro);

    return 0;
}