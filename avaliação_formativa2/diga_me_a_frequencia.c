#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho_ascii 131

typedef struct no{
    int x; //codigo ascii em decimal
    char c; //caractere em si
    int qtd; //quantidade de vezes que o caractere aparece
    struct no *prox;
}no;

typedef struct TH{
    no **tabela;
    int tamanho;
}TH;

TH *cria_tabela(){
    TH *tabela = malloc(sizeof(TH));
    tabela->tabela = calloc(tamanho_ascii, sizeof(no *));
    tabela->tamanho = tamanho_ascii;
    return tabela;
}

void insere_no(no **lista, int x, char c){
    no *novo = malloc(sizeof(no));
    novo->x = x;
    novo->c = c;
    novo->qtd = 1;
    novo->prox = *lista;
    *lista = novo;
}

void insere_tabela(TH *tabela, char c){
    int x = (int)c; // calcula o codigo ascii do caractere
    int indice = x % tabela->tamanho;
    no *atual = tabela->tabela[indice];
    while(atual != NULL){
        if(atual->x == x){
            return;
        }
        atual = atual->prox;
    }
    insere_no(&tabela->tabela[indice], x, c);
}

int busca_e_incrementa(TH *tabela, char c){
    int x = (int)c; // calcula o codigo ascii do caractere
    int indice = x % tabela->tamanho;
    no *atual = tabela->tabela[indice];
    while(atual != NULL){
        if(atual->x == x){
            atual->qtd++;
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

void imprime_crescente(TH *tabela){
    int max_qtd = 0;
    for (int i = 0; i < tabela->tamanho; i++){
        no *atual = tabela->tabela[i];
        while(atual != NULL){
            if(atual->qtd > max_qtd){
                max_qtd = atual->qtd;
            }
            atual = atual->prox;
        }
    }

    for (int qtd = 1; qtd <= max_qtd; qtd++){
        for (int i = 0; i < tabela->tamanho; i++){
            no *atual = tabela->tabela[i];
            while(atual != NULL){
                if(atual->qtd == qtd){
                    printf("%d %d\n", atual->x, atual->qtd);
                }
                atual = atual->prox;
            }
        }
    }
}

void destroi_tabela(TH *tabela){
    for (int i = 0; i < tabela->tamanho; i++){
        no *atual = tabela->tabela[i];
        while(atual != NULL){
            no *prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(tabela->tabela);
    free(tabela);
}

int main(){
    char entrada[1000];
    TH *tabela = cria_tabela();
    while(scanf("%s", entrada) != EOF){
        for (int i = 0; i < strlen(entrada); i++){
            if(busca_e_incrementa(tabela, entrada[i]) == 0){
                insere_tabela(tabela, entrada[i]);
            }
        }
        imprime_crescente(tabela);
        printf("\n");
        destroi_tabela(tabela);
        tabela = cria_tabela();
    }
}