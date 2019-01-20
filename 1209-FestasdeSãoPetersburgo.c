#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int item;    
    struct celula *prox;    
} Celula;

typedef struct Fila{
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Fila* criaFilaVazia(void) {
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

int filaVazia(Fila *f) {
    return (f->primeiro == NULL);
}

void enfileira(Fila *f, int item) {
    Celula *novaCelula = malloc(sizeof(Celula));
    novaCelula->item = item;
    novaCelula->prox = NULL;

    if(filaVazia(f)){
        f->primeiro = novaCelula;
        f->ultimo = f->primeiro; 
    }else{
        f->ultimo->prox = novaCelula;
        f->ultimo = novaCelula;
    }
}

int desenfileira(Fila *f) {
    int item = NULL;
    Celula *aux;
    if(!filaVazia(f)){
        item = f->primeiro->item;
        aux = f->primeiro;
        f->primeiro = f->primeiro->prox;
        free(aux);
    }

    return item;
}

void liberaFila(Fila *f) {
    Celula *aux;
    while(!filaVazia(f)){
        aux = f->primeiro->prox;
        free(f->primeiro);
        f->primeiro = aux;
    }
    free(f);
}

typedef struct vertice{
    int *amigos;
    int nAmigos;
    int visitado;
} Vertice;


int main(int argc, char const *argv[]){
    Vertice *grafo;
    Fila *f;
    int N, M, K, i, u, v, cont, conv;

    while(scanf("%d%d%d", &N, &M, &K) != EOF){
        cont = 0;
        conv = 0;
        grafo = malloc(N*sizeof(Vertice));
        for(i = 0; i < N; i++){
            grafo[i].amigos = calloc(N, sizeof(int));
            grafo[i].nAmigos = 0;
            grafo[i].visitado = 0;
        }
    

        for(i = 0; i < M; i++){
            scanf("%d%d", &u, &v);
            grafo[u-1].amigos[v-1] = 1;
            grafo[v-1].amigos[u-1] = 1;
            grafo[u-1].nAmigos++;
            grafo[v-1].nAmigos++;
        }
    
        f = criaFilaVazia();
        for(i = 0; i < N; i++){
            if(grafo[i].nAmigos < K){
                enfileira(f, i);
            }
        }

        while(!filaVazia(f)){
            v = desenfileira(f);
            if(!grafo[v].visitado){
                grafo[v].visitado = 1;
                cont++;
                for(i = 0; i < N; i++){
                    if(grafo[v].amigos[i]){
                        grafo[i].nAmigos--;
                        if(grafo[i].nAmigos < K){
                            enfileira(f, i);
                        }
                    }
                }
            }
        }
        free(f);
        if(cont == N){
            printf("%d", 0);
        }else{
            for(i = 0; i < N; i++){
                if(!grafo[i].visitado){
                    printf("%d", i+1);
                    conv++;
                    if(conv != (N-cont)) printf(" ");
                }
            }
        }
        printf("\n");       
        
        for(i = 0; i < N; i++){
            free(grafo[i].amigos);
        }
        free(grafo);
    }
    
    return 0;
}