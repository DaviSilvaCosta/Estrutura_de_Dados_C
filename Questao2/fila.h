struct Nodefila{
    int conteudo;
    struct Nodefila *prox;
};

typedef struct Nodefila nodefila;

int EMPTY(nodefila *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}
void ENQUEUE(nodefila *FILA,int tam){
    nodefila *novo=(nodefila *) malloc(sizeof(nodefila));
    novo->prox = NULL;
    
    printf("Novo item da Fila: ");
    scanf("%d", &novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox=novo;
    }
    else{
        nodefila *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void DEQUEUE(nodefila *FILA, int tam){
	if(FILA->prox == NULL){
	   printf("Fila esta vazia\n");
      return;
	}else{
    nodefila *tmp = FILA->prox;
    FILA->prox = tmp->prox;
    tam--;
    free(tmp);
  }
}

void IMPRIMEMAIOR(nodefila *FILA) {
    if (EMPTY(FILA)) {
        printf("A Fila está vazia!\n");
        return;
    }
    
    int maior = FILA->prox->conteudo;
    nodefila *tmp = FILA->prox->prox;
    
    while (tmp != NULL) {
        if (tmp->conteudo > maior) {
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    
    if (maior == FILA->prox->conteudo) {
        printf("\nO primeiro elemento da Fila é o maior: %d\n", maior);
    } else {
        printf("\nMaior elemento da Fila: %d\n", maior);
    }
}

void IMPRIMEMENOR(nodefila *FILA) {
    if (EMPTY(FILA)) {
        printf("A Fila está vazia!\n");
        return;
    }
    
    int menor = FILA->prox->conteudo;
    nodefila *tmp = FILA->prox->prox;
    
    while (tmp != NULL) {
        if (tmp->conteudo < menor) {
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    
    if (menor == FILA->prox->conteudo) {
        printf("\nO primeiro elemento da Fila é o menor: %d\n", menor);
    } else {
        printf("\nMenor elemento da Fila: %d\n", menor);
    }
}

void IMPRIMIRFILA(nodefila *FILA, int tam){
    if(EMPTY(FILA)){
        printf("\nA Pilha está vazia!\n\n");
        return ;
    }
    nodefila *tmp = FILA -> prox;
    
    printf("\n Pilha: ");
    
    while (tmp != NULL){
        printf("%3d",tmp -> conteudo);
        tmp = tmp ->prox;
        tam++;
    }
    
    printf("\n Tamanho da fila é de: %d",tam);
    printf("\n");
}

void LIMPARFILA(nodefila *FILA) {
    while (FILA != NULL) {
        nodefila *temp = FILA;
        FILA = FILA->prox;
        free(temp);
    }
    printf("\nA Pilha foi limpa com sucesso!\n\n");
}
