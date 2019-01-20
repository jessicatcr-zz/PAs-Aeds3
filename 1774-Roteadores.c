#include <stdio.h>
#define INFINITO 10001

#define MAXTAM 60

int minVertice(int estaNaArvore[MAXTAM], int grafo[MAXTAM][MAXTAM], int tamGrafo, int *soma){
    int i, j, vertice = -1, menorAresta = INFINITO;

    for(i = 0; i < tamGrafo; i++){
        if(estaNaArvore[i]){
            for(j = 0; j < tamGrafo; j++){
                if(!estaNaArvore[j] && grafo[i][j] < menorAresta){
                    menorAresta = grafo[i][j];
                    vertice = j;
                }
            }
        }
    }
    *soma = *soma + menorAresta;
    return vertice;
}

int main(int argc, char const *argv[]){
    int rot, cabos, rot1, rot2, preco, i, j, procura, soma = 0, minV;

    scanf("%d %d", &rot, &cabos);
    int grafo[MAXTAM][MAXTAM];
    int estaNaArvore[MAXTAM];

    for(i = 0; i < rot; i++){
        estaNaArvore[i] = 0;
    }

    for(i = 0; i < rot; i++){
        for(j = 0; j < rot; j++){
            grafo[i][j] = INFINITO;
        }
    }

    for(i = 0; i < cabos; i++){
        scanf("%d %d %d", &rot1, &rot2, &preco);
        grafo[rot1-1][rot2-1] = preco;
        grafo[rot2-1][rot1-1] = preco;
    }

    estaNaArvore[0] = 1;
    procura = 0;
    while(procura < rot-1){
        minV = minVertice(estaNaArvore, grafo, rot, &soma);
        estaNaArvore[minV] = 1;
        procura++;
    }

    printf("%d\n", soma);


    return 0;
}