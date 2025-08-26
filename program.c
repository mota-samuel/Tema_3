#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];              // Ex: "SP"
    char codigo[5];              // Ex: "A01"
    char cidade[30];             // Nome da cidade
    int populacao;               // População da cidade
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões
    int pontos_turisticos;       // Número de pontos turísticos
    float densidade_populacional;// População / Área
    float pib_per_capita;        // PIB / População
} Carta;

int main() {
    // Cadastro das duas cartas ------------------------
    Carta carta1 = {"SP", "A01", "Sao Paulo", 12300000, 1521.0, 699.28, 20};
    Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6718903, 1182.3, 400.12, 15};

    // Cálculo dos atributos derivados -----------------
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area;

    carta1.pib_per_capita = carta1.pib * 1000000000.0 / carta1.populacao;
    carta2.pib_per_capita = carta2.pib * 1000000000.0 / carta2.populacao;

    // Escolha do atributo para comparação --------------
    // Opções: populacao, area, pib, densidade, pib_per_capita
    // Para este exemplo, vamos comparar pelo PIB per capita.
    printf("Comparacao de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);

    // Comparação e resultado ---------------------------
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
