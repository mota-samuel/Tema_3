#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char pais[30];                // Nome do país
    int populacao;                // População
    float area;                   // Área em km²
    float pib;                    // PIB em bilhões
    int pontos_turisticos;        // Número de pontos turísticos
    float densidade_demografica;  // População / Área
    float pib_per_capita;         // PIB / População
} Carta;

int main() {
    // Cadastro de duas cartas (pré-definidas)
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1600.0, 25, 0, 0};
    Carta carta2 = {"Argentina", 46000000, 2780400.0, 640.0, 18, 0, 0};

    // Cálculo dos atributos derivados
    carta1.densidade_demografica = (float)carta1.populacao / carta1.area;
    carta2.densidade_demografica = (float)carta2.populacao / carta2.area;

    carta1.pib_per_capita = carta1.pib * 1000000000.0 / carta1.populacao;
    carta2.pib_per_capita = carta2.pib * 1000000000.0 / carta2.populacao;

    int opcao;

    // Exibe menu para o jogador
    printf("===== SUPER TRUNFO - Comparacao de Cartas =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nComparacao entre %s e %s\n", carta1.pais, carta2.pais);

    // Lógica de comparação com switch + if/else
    switch(opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", carta1.pais, carta1.populacao);
            printf("%s: %d\n", carta2.pais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.pais, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", carta1.pais, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.pais, carta2.pontos_turisticos);

            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade demográfica (regra invertida: menor vence)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.6f hab/km²\n", carta1.pais, carta1.densidade_demografica);
            printf("%s: %.6f hab/km²\n", carta2.pais, carta2.densidade_demografica);

            if (carta1.densidade_demografica < carta2.densidade_demografica) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta1.pais);
            } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
    }

    return 0;
}