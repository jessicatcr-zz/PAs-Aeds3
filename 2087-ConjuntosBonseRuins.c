#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct no{
    struct no *nos[26];
    int terminaPalavra;
}No;

No *criaNo(){
    int i;
    No *novoNo;
    novoNo = malloc(sizeof(No));
    for(i = 0; i < 26; i++) novoNo->nos[i] = NULL;
    novoNo->terminaPalavra = 0;
    return novoNo;
}

int insere(No *noRaiz, char palavra[MAX]){
    int i = 0, acheiPrefixo = 0;
    No *atual;
    atual = noRaiz;

    while(palavra[i] != '\0' && !acheiPrefixo){
        int pos = palavra[i]%'a';
        if(atual->nos[pos] == NULL){
            atual->nos[pos] = criaNo();
            atual = atual->nos[pos];
        }else{
            if(atual->nos[pos]->terminaPalavra == 0){
                atual = atual->nos[pos];
                if(palavra[i+1] == '\0')
                    acheiPrefixo = 1; //Palavra é prefixo de outra já inserida
            }else{
                acheiPrefixo = 1;
            }
        }
        i++;
    }
    atual->terminaPalavra = 1;
    return acheiPrefixo;
}


void liberaNo(No *noRaiz){
    int i;
    if(noRaiz == NULL) return;

    for(i = 0; i < 26; i++)
        liberaNo(noRaiz->nos[i]);
    free(noRaiz);
}

int main(int argc, char const *argv[]){
    int N, i, acheiPrefixo;
    char palavra[MAX];
    No *raiz;

    scanf("%d", &N);
    while(N != 0){
        raiz = criaNo();
        acheiPrefixo = 0;
        for(i = 0; i < N; i++){
            scanf("%100s", palavra);
            if(!acheiPrefixo){
                acheiPrefixo = insere(raiz, palavra);
            }
        }
        liberaNo(raiz);
        
        if(!acheiPrefixo){
            printf("Conjunto Bom\n");
        }else{
            printf("Conjunto Ruim\n");
        }

        scanf("%d", &N);
    }

    return 0;
}