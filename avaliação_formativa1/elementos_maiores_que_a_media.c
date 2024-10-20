#include <stdio.h>

int main()
{
    int n;
    long long int soma = 0;
    int numero;
    int temMaior = 0;
    int primeiroPrint = 1;

    scanf("%d", &n);
    if (n <= 0) { // Verifica se o número de elementos é positivo
        printf("0\n");
        return 0;
    }

    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        vetor[i] = numero;
        soma += numero; // Adiciona o número à soma
    }
    long long int media = soma / n; // Calcula a média

    for (int i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            if (primeiroPrint)
            {
                printf("%d", vetor[i]);
                primeiroPrint = 0; // Muda a flag após o primeiro número
            }
            else
            {
                printf(" %d", vetor[i]);
            }
            temMaior = 1; // Marca que encontramos um número maior que a média
        }
    }

    if (!temMaior)
        printf("0"); // Se nenhum número maior foi encontrado
    printf("\n");
    return 0;
}
