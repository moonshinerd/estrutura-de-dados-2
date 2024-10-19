#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>

int main() {
    int tamanho_maximo = 100000+1; // + 1 para o caractere nulo
    char *str = (char*) malloc(tamanho_maximo * sizeof(char));
    scanf("%100000s", str);
    char sigla[4]; // + 1 para o caractere nulo
    scanf("%3s", sigla);
    bool achou = false;

    // Percorre cada caractere da string
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);  // Converte para maiúsculo
    }
    int max;

    if (sigla[2] == 'X') max = 2; 
    else max = 3;
    int i = 0;
    for (char *p = str; *p; p++) {
        if (*p == sigla[i]) {
            i++;
            if (i == max) {
                achou = true;
                break;
            }

        }

        
    }
    if(achou){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    free(str);
    return 0;
}
