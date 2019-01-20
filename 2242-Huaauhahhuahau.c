#include <stdio.h>

int ePalindromo(char palavra[51], int tamanho){
    int i, j;

    for(i = 0; i < tamanho/2; i++){
        if(palavra[i] != palavra[tamanho-1-i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[]){
    char risada[51], vogais [51];
    int i = 0, j = 0, numVogais = 0;


    scanf("%50s", risada);
    while(risada[i] != '\0'){
        if((risada[i] == 'a') || (risada[i] == 'e') || (risada[i] == 'i') || (risada[i] == 'o') || (risada[i] == 'u')){
            vogais[j] = risada [i];
            j++;
        }
        i++;
    }
    numVogais = j;
    if(ePalindromo(vogais, numVogais)){
        printf("S\n");
    }else{
        printf("N\n");
    }

    return 0;
}