#include <stdio.h>

int main() {
    // Declaração das variáveis
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];

    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Leitura dos dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado (sigla com 1 letra): ");
    scanf(" %c", &estado1);

    printf("Código da Carta: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf("%s", nomeCidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de R$): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado (sigla com 1 letra): ");
    scanf(" %c", &estado2);

    printf("Código da Carta: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf("%s", nomeCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de R$): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    float pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    int opcao;
    printf("\n--- Menu de Atributos para Comparação ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("6. PIB per capita\n");
    printf("Escolha o atributo para comparar (1 a 6): ");
    scanf("%d", &opcao);

    printf("\nComparando %s (%c) vs %s (%c)\n", nomeCidade1, estado1, nomeCidade2, estado2);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %lu\n", nomeCidade1, populacao1);
            printf("%s: %lu\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (area2 > area1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("%s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            if (pib1 > pib2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (MENOR vence)\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6:
            printf("Atributo: PIB per capita\n");
            printf("%s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("%s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2)
                printf("Vencedor: %s\n", nomeCidade1);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("Vencedor: %s\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Por favor, selecione entre 1 e 6.\n");
    }

    return 0;
}