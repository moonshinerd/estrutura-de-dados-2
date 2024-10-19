#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>


int main() {
    int total_disciplinas;
    scanf("%d", &total_disciplinas);
    int notas_por_disciplina[total_disciplinas];
    for (int i = 0; i < total_disciplinas; i++) {
        notas_por_disciplina[i] = 0;
    }
    int ano, semestre, quantidade_disciplinas;
    while(scanf("%d %d %d", &ano, &semestre, &quantidade_disciplinas) != EOF){
        for (int i = 0; i < quantidade_disciplinas; i++){
            int cod_disciplina, matriculados, aprovados;
            scanf("%d %d %d", &cod_disciplina, &matriculados, &aprovados);
            notas_por_disciplina[cod_disciplina] += matriculados - aprovados; // soma o numero de reprovados
        }
        
        int maior_valor = notas_por_disciplina[0];
        for (int i = 1; i < total_disciplinas; i++) {
            if (notas_por_disciplina[i] > maior_valor) {
                maior_valor = notas_por_disciplina[i];
            }
        }
        printf("%d/%d\n", ano, semestre);
        for (int i = 0; i < total_disciplinas; i++) {
            if (notas_por_disciplina[i] == maior_valor) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
        for (int i = 0; i < total_disciplinas; i++) {
            notas_por_disciplina[i] = 0;
        }
    }
    return 0;
}
