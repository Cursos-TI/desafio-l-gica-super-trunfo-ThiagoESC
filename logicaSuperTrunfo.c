#include <stdio.h>
#include <string.h>

//Função para exibir carta e calcular densidade populacional
float exibirCarta (char estado, char codigo[], char cidade[], unsigned long int populacao, float area,
float pib, int turismo){
    float densidade = (float) populacao / area;
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f Km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", turismo);
    printf("Densidade Populacional: %.2f hab/Km²\n", densidade);
    printf("-----------------------------------------\n\n\n");
    return densidade;
}

//Função para comparar valores da carta
int compararValores (float valor1, float valor2){
    int resultado = 0;
    if (valor1 == valor2) {
        resultado = 2;
    } else if (valor1 > valor2) {
        resultado = 1;
    }
    return resultado;
}

//Função para comparar os valores do primeiro e segundo atributo
void exibirResultado(int resultado){
    if (resultado == 2){
        printf("As Cartas EMPATARAM!\n");
    } else {
        (resultado == 1) ? printf("A Carta do Jogador venceu nesse atributo\n") : 
                           printf("A Carta da Máquina venceu nesse atributo\n");
    }
}

int main(){

    //Declaração de variáveis e Cadastro Automático das Cartas
    char estado1 = 'A', estado2 = 'B';
    char codigo1[4] = "A01", codigo2[4] = "B01";
    char cidade1[50] = "São Paulo", cidade2[50] = "Rio de Janeiro";
    unsigned long int populacao1 = 12325000, populacao2 = 6748000;
    int turismo1 = 45, turismo2 = 50, opcao1, opcao2, resultado;
    float area1 = 1521.11, area2 = 1200.25, pib1 = 699.28, pib2 = 300.50;
    float densidade1, densidade2, somaJogador, somaPC;

    //Imprimindo informações da Carta 1 - Jogador
    printf("--------------- Sua Carta ---------------\n");
    densidade1 = exibirCarta(estado1, codigo1, cidade1, populacao1, area1, pib1, turismo1);

    //Menu para escolha do primeiro atributo
    printf("***** Escolha o primeiro atributo da sua carta *****\n");
    printf("Opção 1 - População\n");
    printf("Opção 2 - Área\n");
    printf("Opção 3 - PIB\n");
    printf("Opção 4 - Pontos Turísticos\n");
    printf("Opção 5 - Densidade Populacional\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao1);
    
    if ((opcao1 < 1) || (opcao1 > 5)) {
        printf("\nOpção inválida - Jogo Finalizado!");
        return 0;
    }

    //Menu para escolha do segundo atributo (diferente do primeiro atributo)
    printf("\n\n***** Escolha o segundo atributo da sua carta *****\n");
    if (opcao1 != 1) printf("Opção 1 - População\n");
    if (opcao1 != 2) printf("Opção 2 - Área\n");
    if (opcao1 != 3) printf("Opção 3 - PIB\n");
    if (opcao1 != 4) printf("Opção 4 - Pontos Turísticos\n");
    if (opcao1 != 5) printf("Opção 5 - Densidade Populacional\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao2); 

    if ((opcao2 < 1) || (opcao2 > 5)){
        printf("\nOpção inválida - Jogo Finalizado!");
        return 0;
    } else if (opcao1 == opcao2){
        printf("\nAs duas opções são iguais - Jogo Finalizado!");
        return 0;
    }

    //Imprimindo informações da Carta 2 - Computador
    printf("\n\n\n--------------- Carta Oponente ---------------\n");
    densidade2 = exibirCarta(estado2, codigo2, cidade2, populacao2, area2, pib2, turismo2);

    //Primeiro atributo escolhido
    printf("Primeiro atributo escolhido: \n");
    switch (opcao1) {
    case 1:
        somaJogador = (float) populacao1;
        somaPC = (float) populacao2;
        resultado = compararValores(somaJogador, somaPC);
        printf("Carta do Jogador - População: %lu habitantes\n", populacao1);
        printf("Carta da Máquina - População: %lu habitantes\n", populacao2);
        break;
    case 2:
        somaJogador = area1;
        somaPC = area2;
        resultado = compararValores(area1, area2);
        printf("Carta do Jogador - Área: %.2f Km²\n", area1);
        printf("Carta da Máquina - Área: %.2f Km²\n", area2);
        break;
    case 3:
        somaJogador = pib1;
        somaPC = pib2;
        resultado = compararValores(pib1, pib2);
        printf("Carta do Jogador - PIB: %.2f bilhões de reais\n", pib1);
        printf("Carta da Máquina - PIB: %.2f bilhões de reais\n", pib2);
        break;
    case 4:
        somaJogador = (float) turismo1;
        somaPC = (float) turismo2;
        resultado = compararValores(somaJogador, somaPC);
        printf("Carta do Jogador - Pontos Turísticos: %d\n", turismo1);
        printf("Carta da Máquina - Pontos Turísticos: %d\n", turismo2);
        break;
    case 5:
        somaJogador = 1.0 / densidade1;
        somaPC = 1.0 / densidade2;
        resultado = compararValores(somaJogador, somaPC);
        printf("Carta do Jogador - Densidade Populacional: %.2f hab/Km²\n", densidade1);
        printf("Carta da Máquina - Densidade Populacional: %.2f hab/Km²\n", densidade2);
        break;
    }

    exibirResultado(resultado);

    //Segundo atributo escolhido
    printf("\nSegundo atributo escolhido: \n");
    switch (opcao2) {
    case 1:
        somaJogador += (float) populacao1;
        somaPC += (float) populacao2;
        resultado = compararValores((float) populacao1, (float) populacao2);
        printf("Carta do Jogador - População: %lu habitantes\n", populacao1);
        printf("Carta da Máquina - População: %lu habitantes\n", populacao2);
        break;
    case 2:
        somaJogador += area1;
        somaPC += area2;
        resultado = compararValores(area1, area2);
        printf("Carta do Jogador - Área: %.2f Km²\n", area1);
        printf("Carta da Máquina - Área: %.2f Km²\n", area2);
        break;
    case 3:
        somaJogador += pib1;
        somaPC += pib2;
        resultado = compararValores(pib1, pib2);
        printf("Carta do Jogador - PIB: %.2f bilhões de reais\n", pib1);
        printf("Carta da Máquina - PIB: %.2f bilhões de reais\n", pib2);
        break;
    case 4:
        somaJogador += (float) turismo1;
        somaPC += (float) turismo2;
        resultado = compararValores((float) turismo1, (float) turismo2);
        printf("Carta do Jogador - Pontos Turísticos: %d\n", turismo1);
        printf("Carta da Máquina - Pontos Turísticos: %d\n", turismo2);
        break;
    case 5:
        somaJogador += 1.0 / densidade1;
        somaPC += 1.0 / densidade2;
        resultado = compararValores(1.0 / densidade1, 1.0 / densidade2);
        printf("Carta do Jogador - Densidade Populacional: %.2f hab/Km²\n", densidade1);
        printf("Carta da Máquina - Densidade Populacional: %.2f hab/Km²\n", densidade2);
        break;
    }

    exibirResultado(resultado);

    //Resultado final
    printf("\nSoma dos atributos escolhidos - Jogador: %.4f\n", somaJogador);
    printf("Soma dos atributos escolhidos - Máquina: %.4f\n", somaPC);
    if (somaJogador == somaPC){
        printf("EMPATE!!!\n");
    } else if (somaJogador > somaPC){
        printf("Parabéns, você ganhou :)\n");
    } else {
        printf("Infelizmente você perdeu :(\n");
    }

    return 0;
}