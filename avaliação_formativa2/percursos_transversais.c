#include <stdio.h>
#include <stdlib.h>

void imprime_posfixa(char *prefixo, char *infixo, int n) {
    if (n == 0) return;

    int raiz = 0;
    while (infixo[raiz] != prefixo[0]) raiz++;

    imprime_posfixa(prefixo + 1, infixo, raiz);
    imprime_posfixa(prefixo + raiz + 1, infixo + raiz + 1, n - raiz - 1);

    printf("%c", prefixo[0]);
}

int main(){
    int a;
    scanf("%d", &a);
    for(int i = 0;i<a;i++){
        int n; //numero de nós da arvore
        char prefixo[1000], infixo[1000];
        scanf("%d %s %s", &n, prefixo, infixo);
        imprime_posfixa(prefixo, infixo, n);
        printf("\n");
    }
}