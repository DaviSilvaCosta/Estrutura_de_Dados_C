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

