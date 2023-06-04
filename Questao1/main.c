#include <stdio.h>
#include "funcoes.h"

int main() {
    
    int vetor[] = {9, 6, 3, 1, 10};
    int n = sizeof(vetor)/ sizeof(vetor[0]);
    int opcao;

    printf("╔═════════════════════╗\n");
    printf("║ VETOR: 9,6,3,1,10   ║\n");
    printf("╠═════════════════════╣\n");
    printf("║Selecione uma opção: ║\n");
    printf("║                     ║\n");
    printf("║ [1] - BubbleSort    ║\n");
    printf("║ [2] - insertionSort ║\n");
    printf("║                     ║\n");
    printf("║                     ║\n");
    printf("╚═════════════════════╝\n");
    printf("Opção:");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
        
            bubbleSort(vetor, n);
            printf("Resultado do vetor usando Bubble Sort: ");
            imprimirVetor(vetor, n);
            
            break;
            
        case 2:
        
            insertionSort(vetor, n);
            printf("Resultado do vetor usando Insertion Sort: ");
            imprimirVetor(vetor, n);
            
            break;
            
        default:
        
            printf("Opção inválida\n");
            break;
    }
    
    return 0;
}

funcoes.h

void bubbleSort(int vetor[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                // Troca os elementos adjacentes
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void insertionSort(int vetor[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void imprimirVetor(int vetor[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
