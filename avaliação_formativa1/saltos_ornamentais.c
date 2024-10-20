#include <stdio.h>

int main() {
    double dificuldade, notas[7];
    
    // Lê a dificuldade
    scanf("%lf", &dificuldade);
    
    // Lê as 7 notas
    for (int i = 0; i < 7; i++) {
        scanf("%lf", &notas[i]);
    }
    
    // Encontrar a maior e a menor nota
    double maior = notas[0], menor = notas[0];
    double soma = 0;
    
    for (int i = 0; i < 7; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }
    
    // Subtrai a maior e a menor da soma total
    soma -= (maior + menor);
    
    // Calcula a média das 5 notas restantes
    double media = soma / 5;
    
    // Multiplica pelo grau de dificuldade
    double nota_final = media * dificuldade;
    
    // Imprime o resultado com 1 casa decimal
    printf("%.1f\n", nota_final);
    
    return 0;
}
