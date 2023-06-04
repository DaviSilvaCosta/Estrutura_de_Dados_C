#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"
#include "fila.h"
#include "arvore.h"

int main()
{
    int opcao, numero_pilha, numero_fila, variavel_arvore, inserir;
    int valor;

    nodepilha *PILHA = (nodepilha*)malloc(sizeof(nodepilha));
    PILHA->prox = NULL;
    int tam = 0;

    nodefila *FILA = (nodefila*)malloc(sizeof(nodefila));
    FILA->prox = NULL;

    Arvb arv;
    arv.raiz = NULL;
    No *raiz = NULL;

    printf("\n");
    printf("1- Pilha\n");
    printf("2- Fila\n");
    printf("3- Arvore\n");
    printf("0- Sair\n");

    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            do {
                printf("\n1- Empilhar\n");
                printf("2- Desempilhar\n");
                printf("3- Imprimir topo da pilha\n");
                printf("4- Imprimir pilha\n");
                printf("5- Limpar pilha\n");
                printf("0- Sair\n");
                printf("=> ");
                scanf("%d", &numero_pilha);

                switch (numero_pilha) {
                    case 1:
                        PUSH(PILHA, tam);
                        break;

                    case 2:
                        POP(PILHA, tam);
                        break;

                    case 3:
                        TOPOPILHA(PILHA);
                        break;

                    case 4:
                        IMPRIMIRPILHA(PILHA, tam);
                        break;

                    case 5:
                        LIMPARPILHA(PILHA);
                        break;

                    case 0:
                        break;

                    default:
                        printf("Digite uma opção valida!");
                        break;
                }
            } while (numero_pilha != 0);
            break;

        case 2:
            do {
                printf("\n1- Enfileirar\n");
                printf("2- Desenfileirar\n");
                printf("3- Imprimir maior numero\n");
                printf("4- Imprimir menor numero\n");
                printf("5- Imprimir a Fila\n");
                printf("6- Limpar a Fila\n");
                printf("0- Sair\n");
                scanf("%d", &numero_fila);

                switch (numero_fila) {
                    case 1:
                        ENQUEUE(FILA, tam);
                        break;

                    case 2:
                        DEQUEUE(FILA, tam);
                        break;

                    case 3:
                        IMPRIMEMAIOR(FILA);
                        break;

                    case 4:
                        IMPRIMEMENOR(FILA);
                        break;

                    case 5:
                        IMPRIMIRFILA(FILA, tam);
                        break;

                    case 6:
                        LIMPARFILA(FILA);
                        break;

                    case 0:
                        break;

                    default:
                        printf("Opção válida!");
                        break;
                }
            } while (numero_fila != 0);
            break;

                    case 3:
                        do {
                printf("\n1- Inserir um numero:\n");
                printf("2- Imprimir a arvore:\n");
                printf("3- Imprimir a arvore da direita para esquerda:\n");
                printf("4- Imprimir maior e o menor numero da arvore:\n");
                printf("5- Buscar numero na arvore:\n");
                printf("6- Deletar um numero na arvore:\n");
                printf("0- Sair\n");
                scanf("%d", &variavel_arvore);
            
                switch (variavel_arvore) {
                    case 1:
                        raiz = input(raiz);
                        break;
            
                    case 2:
                        imprime(raiz);
                        break;
            
                    case 3:
                        imprimirDireitaEsquerda(raiz);
                        break;
            
                    case 4:
                        imprimeMaiorMenor(raiz);
                        break;
            
                    case 5:
                        buscar(raiz);
                        break;
            
                    case 6:
                      printf("Digite o valor a ser removido da árvore: \n=>");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                      
                      break;
            
                    case 0:
                        break;
            
                    default:
                        break;
                }
              } while (variavel_arvore != 0);
            
                            break;
            
                            case 0:
                              break;
                      
                            default:
                                break;
                          }
            
             return 0;
  }
