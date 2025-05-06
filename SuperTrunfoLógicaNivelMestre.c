#include <stdio.h>

int main() {
    // Declaração das variáveis
    char nomeCidade1[50], nomeCidade2[50];
    char estado1, estado2, codigo1[4], codigo2[4];

    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;

    // Entrada de dados
    printf("Carta 1:\n");
    printf("Estado: "); scanf(" %c", &estado1);
    printf("Código: "); scanf("%s", codigo1);
    printf("Nome da cidade: "); scanf("%s", nomeCidade1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos turísticos: "); scanf("%d", &pontos1);

    printf("\nCarta 2:\n");
    printf("Estado: "); scanf(" %c", &estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Nome da cidade: "); scanf("%s", nomeCidade2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos turísticos: "); scanf("%d", &pontos2);

    // Atributos derivados
    float dens1 = populacao1 / area1;
    float dens2 = populacao2 / area2;
    float pibpc1 = (pib1 * 1000000000) / populacao1;
    float pibpc2 = (pib2 * 1000000000) / populacao2;

    // Mostra os atributos derivados
    printf("\n--- Atributos Derivados ---\n");
    printf("%s: Densidade = %.2f | PIB per capita = R$ %.2f\n", nomeCidade1, dens1, pibpc1);
    printf("%s: Densidade = %.2f | PIB per capita = R$ %.2f\n", nomeCidade2, dens2, pibpc2);

    // Menu de atributos
    int escolha1 = 0, escolha2 = 0;
    float valor1_cartao1 = 0, valor1_cartao2 = 0;
    float valor2_cartao1 = 0, valor2_cartao2 = 0;
    char atributo1[30], atributo2[30];

    // Primeira escolha
    printf("\nEscolha o 1º atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade\n6 - PIB per capita\n> ");
    scanf("%d", &escolha1);

    // Segunda escolha (dinâmica)
    printf("\nEscolha o 2º atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i == escolha1) continue;
        switch (i) {
            case 1: printf("%d - População\n", i); break;
            case 2: printf("%d - Área\n", i); break;
            case 3: printf("%d - PIB\n", i); break;
            case 4: printf("%d - Pontos turísticos\n", i); break;
            case 5: printf("%d - Densidade\n", i); break;
            case 6: printf("%d - PIB per capita\n", i); break;
        }
    }
    printf("> ");
    scanf("%d", &escolha2);

    // Função para atribuir valores com base nas escolhas
    for (int i = 1; i <= 2; i++) {
        int esc = (i == 1) ? escolha1 : escolha2;

        float *v1 = (i == 1) ? &valor1_cartao1 : &valor2_cartao1;
        float *v2 = (i == 1) ? &valor1_cartao2 : &valor2_cartao2;
        char *nomeAttr = (i == 1) ? atributo1 : atributo2;

        switch (esc) {
            case 1:
                *v1 = populacao1;
                *v2 = populacao2;
                strcpy(nomeAttr, "População");
                break;
            case 2:
                *v1 = area1;
                *v2 = area2;
                strcpy(nomeAttr, "Área");
                break;
            case 3:
                *v1 = pib1;
                *v2 = pib2;
                strcpy(nomeAttr, "PIB");
                break;
            case 4:
                *v1 = pontos1;
                *v2 = pontos2;
                strcpy(nomeAttr, "Pontos Turísticos");
                break;
            case 5:
                *v1 = dens1;
                *v2 = dens2;
                strcpy(nomeAttr, "Densidade Demográfica");
                break;
            case 6:
                *v1 = pibpc1;
                *v2 = pibpc2;
                strcpy(nomeAttr, "PIB per capita");
                break;
            default:
                printf("Atributo inválido!\n");
                return 1;
        }
    }

    // Comparação + soma dos atributos
    printf("\n--- Comparação dos Atributos ---\n");

    printf("%s: %.2f x %.2f\n", atributo1, valor1_cartao1, valor1_cartao2);
    printf("%s: %.2f x %.2f\n", atributo2, valor2_cartao1, valor2_cartao2);

    // Regras: densidade vence o menor, os demais o maior
    float soma1 = 0, soma2 = 0;

    for (int i = 1; i <= 2; i++) {
        float v1 = (i == 1) ? valor1_cartao1 : valor2_cartao1;
        float v2 = (i == 1) ? valor1_cartao2 : valor2_cartao2;
        int atr = (i == 1) ? escolha1 : escolha2;

        soma1 += v1;
        soma2 += v2;

        if (atr == 5) {
            printf("-> %s vence em %s\n", (v1 < v2) ? nomeCidade1 : (v2 < v1) ? nomeCidade2 : "Empate", (i == 1) ? atributo1 : atributo2);
        } else {
            printf("-> %s vence em %s\n", (v1 > v2) ? nomeCidade1 : (v2 > v1) ? nomeCidade2 : "Empate", (i == 1) ? atributo1 : atributo2);
        }
    }

    // Resultado final
    printf("\n--- Resultado Final ---\n");
    printf("Soma %s: %.2f\n", nomeCidade1, soma1);
    printf("Soma %s: %.2f\n", nomeCidade2, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", nomeCidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}