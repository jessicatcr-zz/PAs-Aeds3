#include <stdio.h>
#include <stdlib.h>

int comp(const void *A, const void *B){
    return (*(int *)A) - (*(int*)B); //Ordena asc
}

int main(){
    int N, A, i;
    double tamIntervalo, h, areaBaixo, areaTotal, areaCima;

    while(scanf("%d %d", &N, &A) && N != 0 && A != 0){
        areaTotal = 0, areaBaixo = 0;

        int C[N+1];
        C[N] = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &C[i]);
            areaTotal += C[i];
        }

        qsort(C, N+1, sizeof(int), comp);

        i = 1;
        areaCima = areaTotal - areaBaixo;
        if(areaCima == A){
            printf(":D\n");        
        } else if (areaCima < A) {
            printf("-.-\n");
        } else {
            while(i <= N && areaCima > (double)A){
                areaBaixo += (double)(C[i] - C[i-1])*(N+1-i);
                areaCima = areaTotal - areaBaixo;
                i++;
            }
            i--;
            h = C[i] + (areaTotal - (double)A - areaBaixo)/(double)(N+1-i);
            printf("%.4f\n", h);            
        }
    }

    return 0;
}