
struct NodePILHA{
    int item;
    struct NodePILHA *prox;
};
typedef struct NodePILHA nodepilha;

int vazia(nodepilha *PILHA){
    if(PILHA -> prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

nodepilha* PUSH(nodepilha *PILHA,int tam){
  nodepilha *novo=(nodepilha *) malloc(sizeof(nodepilha));
  novo->prox = NULL;
  
  printf("Novo item:");
  scanf("%d", &novo->item);
  
  if(vazia(PILHA))
  	PILHA ->prox = novo;
  else{
  	nodepilha *tmp = PILHA->prox;
  	while(tmp->prox != NULL){
  		tmp = tmp->prox;
  	}
  	  tmp->prox = novo;
  }
  tam++;
  return novo;
}
  
void IMPRIMIRPILHA(nodepilha *PILHA, int tam){
    if(vazia(PILHA)){
        printf("\nA Pilha está vazia!\n\n");
        return ;
    }
    nodepilha *tmp = PILHA -> prox;
    
    printf("\n Pilha: ");
    
    while (tmp != NULL){
        printf("%3d",tmp -> item);
        tmp = tmp ->prox;
        tam++;
    }
    
    printf("\n Tamanho da fila é de: %d",tam);
    printf("\n");
}

void POP(nodepilha *PILHA,int tam){
    if(PILHA -> prox == NULL){
        printf("\nA Pilha ja está vazia! \n\n");
        return;
    }else{
        nodepilha *ultimo = PILHA -> prox;
        nodepilha *penultimo = PILHA;
        
    while(ultimo -> prox !=NULL){
        penultimo = ultimo;
        ultimo = ultimo -> prox;
    }
    free(ultimo);
    penultimo -> prox = NULL;
    tam--;
    
    printf("\nÚltimo item da pilha removido com sucesso!\n\n");
    }
}


void LIMPARPILHA(nodepilha *PILHA) {
    while (PILHA != NULL) {
        nodepilha *temp = PILHA;
        PILHA = PILHA->prox;
        free(temp);
    }
    printf("\nA Pilha foi limpa com sucesso!\n\n");
}

void TOPOPILHA(nodepilha *PILHA){
    if(vazia(PILHA)){
        
        printf("\nA Pilha ja está vazia! \n\n");
        return ;
        
    }else{
        
        nodepilha *tmp = PILHA -> prox;
        
        printf("\nNumero no topo da pilha é:");
        while (tmp->prox != NULL){
            tmp = tmp -> prox;
        }   
    printf("%d",tmp -> item);
    printf("\n");
    }
}

