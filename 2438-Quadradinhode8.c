#include <stdio.h>

#define MAX 1000001


int main(int argc, char const *argv[]){
    long long int N, i, j;
    long long int cont[8] = {1, 0, 0, 0, 0, 0, 0, 0};
    long long int nManeiras = 0;

    scanf("%lld", &N);
    long long int vet[MAX];
    
    scanf("%lld", &vet[0]);
    vet[0] %= 8;
    cont[vet[0]]++;
    for(i = 1; i < N; i++){
        scanf("%lld", &vet[i]);

        vet[i] += vet[i-1]; //Somas parciais
        vet[i] %= 8;
        cont[vet[i]]++;
    }

    for(i = 0; i < 8; i++){
        nManeiras += ((cont[i])*(cont[i]-1))/2;
    }

    printf("%lld\n", nManeiras);

    return 0;
}