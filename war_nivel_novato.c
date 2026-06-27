// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================


#include <stdio.h>   /* printf, scanf, fgets */
#include <string.h>  /* strcspn              */
#include <locale.h>  /* setlocale            */

// --- Constantes ---
#define NUM_TERRITORIOS 5   /* Numero de territorios no mapa      */
#define MAX_NOME        30  /* Tamanho maximo do nome             */
#define MAX_COR         10  /* Tamanho maximo da cor do exercito  */

// --- Estrutura de Dados ---
// Agrupa as informacoes de um territorio
typedef struct {
    char nome[MAX_NOME];  /* Nome do territorio          */
    char cor[MAX_COR];    /* Cor do exercito dominante   */
    int  tropas;          /* Numero de tropas            */
} Territorio;

// ============================================================================
// --- Funcao Principal ---
// ============================================================================
int main(void) {

    // Habilita caracteres especiais do portugues (acentos, cedilha etc.)
    setlocale(LC_ALL, "Portuguese");

    // Declara o vetor estatico de territorios
    Territorio mapa[NUM_TERRITORIOS];

    int i; // variavel de controle do loop

    // -------------------------------------------------------------------------
    // ETAPA 1: Cadastro dos territorios
    // -------------------------------------------------------------------------
    printf("============================================\n");
    printf("Vamos cadastrar os %d territorios iniciais do nosso mundo.\n", NUM_TERRITORIOS);

    for (i = 0; i < NUM_TERRITORIOS; i++) {

        printf("\n--- Cadastrando Territorio %d ---\n", i + 1);

        // Leitura do nome (fgets suporta nomes com espaco)
        printf("Nome do Territorio: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; /* Remove o '\n' deixado pelo fgets */

        // Leitura da cor do exercito
        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(mapa[i].cor, MAX_COR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0'; /* Remove o '\n' deixado pelo fgets */

        // Leitura do numero de tropas
        printf("Numero de Tropas: ");
        scanf("%d", &mapa[i].tropas);

        // Limpa o '\n' residual do scanf para nao sujar o proximo fgets
        while (getchar() != '\n');
    }

    // -------------------------------------------------------------------------
    // ETAPA 2: Exibicao do mapa cadastrado
    // -------------------------------------------------------------------------
    printf("\n============================================\n");
    printf("         ESTADO ATUAL DO MAPA              \n");
    printf("============================================\n");
    printf("| %-2s | %-18s | %-8s | %-6s |\n",
           "No", "Territorio", "Exercito", "Tropas");
    printf("|----|--------------------|-----------|---------|\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("| %-2d | %-18s | %-9s | %-6d |\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    printf("============================================\n");

    return 0;
}