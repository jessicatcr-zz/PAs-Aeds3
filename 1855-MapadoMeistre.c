#include <stdio.h>

char analiseMapa(char mapa[100][100], int largura, int altura){
    char resultado = ' ', direcao = ' ';
    int i = 0, j = 0, eDirecao;

    while(resultado == ' '){
        eDirecao = 0;
        eDirecao = eDirecao || mapa[i][j] == '>' || mapa[i][j] == '<';
        eDirecao = eDirecao || mapa[i][j] == '^' || mapa[i][j] == 'v';
        
        if(eDirecao){
            direcao = mapa[i][j];
            mapa[i][j] = 'p';
        }else if(mapa[i][j] == '*'){
            resultado = '*';
        }else if(mapa[i][j] == 'p'){
            resultado = '!';
        }

        if(resultado == ' '){
            switch(direcao){
                case '>':
                    j++;
                    break;
                case '<':
                    j--;
                    break;
                case '^':
                    i--;
                    break;
                case 'v':
                    i++;
                    break;
            }
            if(i < 0 || i >= altura || j < 0 || j >= largura){
                resultado = '!';
            }
        }
    }
    return resultado;
}

int main(int argc, char const *argv[]){
    int largura, altura, i, j;
    char mapa[100][100], barraN;

    scanf("%d", &largura);
    scanf("%d", &altura);
    scanf("%c", &barraN);

    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            scanf("%c", &mapa[i][j]);
        }
        scanf("%c", &barraN);
    }

    char resultado = analiseMapa(mapa, largura, altura);

    printf("%c\n", resultado);
    
    return 0;
}