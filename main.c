/*
   Aluno: Guilherme Pinheiro Paganelli
   Trabalho N2_Algoritmos II
   "APLICAÇÃO_ORDENADOR DE CHEQUES"
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Define a quantidade de chques que vai ser gerado
#define MAX_TAM 50
//Define o valor maximo que pode ser gerado os cheques(pelo projeto passado pelo professor somente ate 100 mas pode alterar)
#define LIMITADOR 100

// Função para gerar números aleatórios
int random(int n) {
    return rand() % n;
}

// Verifica se o número já existe no vetor para nao repetir
int existe(int n, int vet[], int k) {
    int i;
    for (i = 0; i < n; i++) {
        if (vet[i] == k) {
            return 1;
        }
    }
    return 0;
}

// Procedimento para ordenar os números dos cheques usando Bubble Sort
void bubbleSort(int vet[], int tam) {
    int a, b, troca;
        for (a = 0; a < tam - 1; a++) {
            for (b = 0; b < tam - 1 - a; b++) {
                if (vet[b] > vet[b + 1]) {
                // Compara os números vizinhos e troca se o da esquerda for maior que o da direita
                troca = vet[b];
                vet[b] = vet[b + 1];
                vet[b + 1] = troca;
            }
        }
    }
}

// Procedimento para mostrar o vetor
void cheques(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vet[MAX_TAM];
    int ordenado = 0;
    int opcao;

    srand((unsigned) time(NULL));

    // Gera os cheques aleatoriamente
    for (int i = 0; i < MAX_TAM; i++) {
        int num;
        do {
            num = 1 + random(LIMITADOR);
        } while (existe(i, vet, num));
        vet[i] = num;
    }

    printf("CHEQUES GERADOS DO DIA:\n");
    printf("\------------------------------------------------------------------------------------------------------------------------");
    cheques(vet, MAX_TAM);
    printf("\------------------------------------------------------------------------------------------------------------------------\n\n");

    // Menu interativo para o usuario exibir e ordenar os números
    do {
        printf("\n=======================================\n");
        printf("===== MENU - ORDENADOR DE CHEQUES =====\n");
        printf("=======================================\n");
        printf("1 - EXIBIR CHEQUES GERADOS\n");
        printf("2 - ORDENAR OS CHEQUES\n");
        printf("3 - EXIBIR CHEQUES ORDENADOS\n");
        printf("0 - SAIR\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCHEQUES GERADOS DO DIA:\n");
                printf("\------------------------------------------------------------------------------------------------------------------------");
                cheques(vet, MAX_TAM);
                printf("\------------------------------------------------------------------------------------------------------------------------\n\n");
                break;

            case 2:
                bubbleSort(vet, MAX_TAM);
                ordenado = 1;
                printf("\n\n\---------------------------------");
                printf("\nCHEQUES ORDENADOS COM SUCESSO!!\n");
                printf("\---------------------------------\n\n");
                break;

            case 3:
                if (!ordenado) {
                    printf("\nERRO!! Você precisa selecionar para ordenar os cheques primeiro.\n");
                } else {
                    printf("\nCHQUES ORDENADOS:\n");
                    printf("\------------------------------------------------------------------------------------------------------------------------");
                    cheques(vet, MAX_TAM);
                    printf("\------------------------------------------------------------------------------------------------------------------------\n\n");
                }
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOPÇÃO INVALIDA!! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
