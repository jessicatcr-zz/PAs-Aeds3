#include <stdio.h>

#define MAX 100001
typedef struct coordenadas{
    int x;
    int y;
} Coordenadas;

int main(void){
    int w, i, j = 0, count = 1, count0 = 0, op = 0; 
    Coordenadas vet[MAX];

    vet[0].x = 0;
    vet[0].y = 0;
    i = 1;
    while(i < MAX){
        //printf("%d %d\n", i, op);
        switch(op){
            case 0:
                for(j = 0; i < MAX && j < count; j++){
                    vet[i].y = vet[i-1].y + 1;
                    vet[i].x = vet[i-1].x;
                    i++;
                }
                break; 
            case 1:
                for(j = 0; i < MAX && j < count-1; j++){
                    vet[i].x = vet[i-1].x - 1;
                    vet[i].y = vet[i-1].y + 1;                       
                    i++;
                }
                break;
            case 2:
                for(j = 0; i < MAX && j < count; j++){
                    vet[i].x = vet[i-1].x - 1;
                    vet[i].y = vet[i-1].y;
                    i++;
                }
             
                break;
            case 3:
                for(j = 0; i < MAX && j < count; j++){
                    vet[i].y = vet[i-1].y - 1;
                    vet[i].x = vet[i-1].x;
                    i++;
                }
                break; 
            case 4:
                for(j = 0; i < MAX && j < count; j++){
                    vet[i].y = vet[i-1].y - 1;
                    vet[i].x = vet[i-1].x + 1;
                    i++;
                }
            
                break; 
            case 5:
                for(j = 0; i < MAX && j < count; j++){
                    vet[i].x = vet[i-1].x + 1;
                    vet[i].y = vet[i-1].y;
                    i++;
                }
                count++;
                break; 
        }
        op++;
        op %= 6;
    }

    while(scanf("%d", &w) == 1){
        printf("%d %d\n", vet[w-1].x, vet[w-1].y);
    } 
}