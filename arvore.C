typedef struct No {
  int chave;
  struct No *esquerda, *direita;
} No;

typedef struct {
  No *raiz;
  int tam;
} Arvb;

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if (valor < raiz->chave)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else if (valor > raiz->chave)
            raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    }
}

void imprime(No* raiz) {
    if (raiz != NULL) {
        imprime(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprime(raiz->direita);
    }
}

void imprimirDireitaEsquerda(No* raiz) {
    if (raiz != NULL) {
        imprimirDireitaEsquerda(raiz->direita);
        printf("%d ", raiz->chave);
        imprimirDireitaEsquerda(raiz->esquerda);
    }
}

void imprimeMaiorMenor(No* raiz) {
    if (raiz == NULL)
        return;

    No* atual = raiz;

    while (atual->direita != NULL)
        atual = atual->direita;

    printf("Maior valor: %d\n", atual->chave);

    atual = raiz;
    
    while (atual->esquerda != NULL)
        atual = atual->esquerda;

    printf("Menor valor: %d\n", atual->chave);
}

No* remover(No *raiz, int item){
  if(raiz == NULL){
    printf("Valor nao encontrado...\n");
    return NULL;
  }else{
    if(raiz -> chave == item){
      if(raiz -> esquerda == NULL && raiz -> direita == NULL){
        free(raiz);
        return NULL;  
      }
      else{
        if(raiz -> esquerda == NULL || raiz -> direita == NULL){
            No *temp;
            
          if(raiz -> esquerda != NULL){
            temp = raiz -> esquerda;
            free(raiz);
            return temp;
            
          }else{
            temp = raiz -> direita;
            free(raiz);
            return temp;
            
          }
          }else{
            No *temp = raiz -> esquerda;
          
            while(temp -> direita != NULL)
                temp = temp -> direita;
                
              raiz -> chave = temp -> chave;
              temp -> chave = item;
              raiz -> esquerda = remover(raiz -> esquerda, item);
          
          return raiz;
        }
      }
    }else{
        if(item < raiz -> chave){
            raiz -> esquerda = remover (raiz -> esquerda, item);
            return raiz;
        }else{
            raiz -> direita = remover(raiz -> direita, item);
            return raiz;
        }
    }
  }
}

void buscar(No* raiz) {
    int valorDesejado;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorDesejado);

    if (raiz == NULL) {
        printf("Valor não encontrado na árvore.\n");
    } else if (valorDesejado == raiz->chave) {
        printf("Valor encontrado na árvore.\n");
    } else if (valorDesejado < raiz->chave) {
        buscar(raiz->esquerda);
    } else {
        buscar(raiz->direita);
    }
}
No* input(No* raiz) {
    int valor;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);
    raiz = inserir(raiz, valor);
    return raiz;
}
