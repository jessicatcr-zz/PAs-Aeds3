#include <stdio.h>
#include <string.h>

void estruturar(char str[10001], char cons[10001], char vogs[10001]){
    int i, v = 0, c = 0;

    for (i = 0; str[i] != '\0'; i++){
        if((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')){
            vogs[v] = str[i];
            str[i] = 'v';
            v++;
        }else{
            cons[c] = str[i];
            str[i] = 'c';
            c++;
        }
    }

    vogs[v] = '\0';
    cons[c] = '\0';
}

void desloca(char vet[10001], int n, int pos){
    int i;
    char aux[n];
    for(i = 0; i < n; i++)
        aux[(i+pos)%n] = vet[i];
    
    for(i = 0; i < n; i++)
        vet[i] = aux[i];

}

void imprimir(char str[10001], char cons[10001], char vogs[10001]){
    int i, v = 0, c = 0;

    for (i = 0; str[i] != '\0'; i++){
        if(str[i] == 'v'){
            printf("%c", vogs[v]);
            v++;
        }else{
            printf("%c", cons[c]);
            c++;
        }
    }   
    printf("\n");
}

int main(int argc, char const *argv[]){
    int i, j, T, Q, op, pos, tamC, tamV;
    char S[10001], consoantes[10001], vogais[10001];

    scanf("%d", &T); //Máximo 100 testes
    for(i = 0; i < T; i++){
        printf("Caso #%d:\n", i+1);
        scanf("%10000s", S);
        estruturar(S, consoantes, vogais);
        tamV = strlen(vogais);
        tamC = strlen(consoantes);

        int posC = 0, posV = 0;
        
        scanf("%d", &Q); //Máximo 100.000 operações
        for(j = 0; j < Q; j++){
            scanf("%d", &op);
            switch (op){
                case 0:
                    scanf("%d", &pos);
                    posV += pos;
                    break;
                case 1:
                    scanf("%d", &pos);
                    posC += pos;
                    break;
                case 2:
                    desloca(vogais, tamV, posV);
                    desloca(consoantes, tamC, posC);
                    posV = 0, posC = 0;                
                    imprimir(S, consoantes, vogais);
                    break;
            }
        }
    }

    return 0;
}