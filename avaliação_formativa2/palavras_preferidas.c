#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define tamanho_hash 1048583 // primo mais proximo de 2^20	

typedef struct no {
    char *palavra;
    int votos;
    struct no *prox;
} no;

typedef struct tabela_hash {
    struct no **tabela;
    int tamanho;
}tabela_hash;



unsigned int string_para_inteiro(char *string){
    unsigned int valor = 0;
    for(int i = 0; string[i] != '\0'; i++){
        valor = valor * 10 + (string[i] - '0');
    }
    return valor;
} 

int funcao_hash(char *palavra){
    int hash = 0;
    hash = string_para_inteiro(palavra) % tamanho_hash;
    return hash;
}

tabela_hash *cria_tabela(){
    tabela_hash *tabela = malloc(sizeof(tabela_hash));
    tabela->tabela = calloc(tamanho_hash, sizeof(struct no *));
    tabela->tamanho = tamanho_hash;
    return tabela;
}



void trata_entrada(tabela_hash *tabela, char *palavra, int comando){
    int posicao = funcao_hash(palavra);
    no *cabeca = tabela->tabela[posicao];
    no *novo = malloc(sizeof(no));
    switch (comando){
        case 1: // C = 1: você deve computar mais um voto para a palavra P
            while(cabeca != NULL){
                if(strcmp(cabeca->palavra, palavra) == 0){
                    cabeca->votos++;
                    return;
                }
                cabeca = cabeca->prox;
            }
            // Se a palavra não existir na tabela
            novo->palavra = strdup(palavra);
            novo->votos = 1;
            novo->prox = tabela->tabela[posicao];
            tabela->tabela[posicao] = novo;
            break;
        case 2:// C = 2: você deve dizer quantas pessoas já reportaram a palavra P naquele momento. Há a garantia de ter pelo menos uma query deste tipo 
            while(cabeca != NULL){
                if(strcmp(cabeca->palavra, palavra) == 0){
                    printf("%d\n", cabeca->votos);
                    return;
                }
                cabeca = cabeca->prox;
            }
            printf("0\n");
            break;
        case 3: // C = 3: você deve resetar a quantidade de reportes da palavra P
            while(cabeca != NULL){
                if(strcmp(cabeca->palavra, palavra) == 0){
                    cabeca->votos = 0;
                    return;
                }
                cabeca = cabeca->prox;
            }
            break;
        default:
            free(novo);
            return;
    }
}

int main(){
    tabela_hash *tabela = cria_tabela();
    int comando;
    char *palavra = NULL;
    size_t len = 0;
    while (scanf("%d", &comando) != EOF && getline(&palavra, &len, stdin) != EOF) {
        trata_entrada(tabela, palavra, comando);
    }

    free(palavra);
    return 0;
}