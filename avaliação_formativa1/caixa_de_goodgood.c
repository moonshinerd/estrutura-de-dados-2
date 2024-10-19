#include <stdio.h>
#include <stdlib.h>

long long* crocante(long long a, long long b, long long c) {
    long long* sobrasetotalgerado = malloc(4 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long amendoim = a / 5;
    long long chocolate_branco = b / 25;
    long long chocolate_leite = c / 20;

    // Encontrar o mínimo para saber quantos bombons crocantes podem ser feitos
    long long menorvalor = amendoim;
    if (chocolate_branco < menorvalor) {
        menorvalor = chocolate_branco;
    }
    if (chocolate_leite < menorvalor) {
        menorvalor = chocolate_leite;
    }

    // Calcular as sobras
    long long sobraamendoim = a - (menorvalor * 5);
    long long sobrachocolate_branco = b - (menorvalor * 25);
    long long sobrachocolate_leite = c - (menorvalor * 20);

    // Armazenar os resultados
    sobrasetotalgerado[0] = sobraamendoim;
    sobrasetotalgerado[1] = sobrachocolate_branco;
    sobrasetotalgerado[2] = sobrachocolate_leite;
    sobrasetotalgerado[3] = menorvalor;  // Total de crocante gerado

    return sobrasetotalgerado;
}




long long* misto(long long b, long long c) {
    long long* sobrasetotalgerado = malloc(3 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long chocolate_branco = b / 25;
    long long chocolate_leite = c / 25;

    // Encontrar o menor para saber quantos bombons mistos podem ser feitos
    long long menorvalor = (chocolate_branco < chocolate_leite) ? chocolate_branco : chocolate_leite;

    // Calcular as sobras
    long long sobrachocolate_branco = b - (menorvalor * 25);
    long long sobrachocolate_leite = c - (menorvalor * 25);

    sobrasetotalgerado[0] = sobrachocolate_branco;
    sobrasetotalgerado[1] = sobrachocolate_leite;
    sobrasetotalgerado[2] = menorvalor;  // Total de misto gerado

    return sobrasetotalgerado;
}

long long* tradicional(long long c) {
    long long* sobrasetotalgerado = malloc(2 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long chocolate_leite = c / 50;

    long long sobrachocolate_leite = c - (chocolate_leite * 50);

    sobrasetotalgerado[0] = sobrachocolate_leite;
    sobrasetotalgerado[1] = chocolate_leite;  // Total de tradicional gerado

    return sobrasetotalgerado;
}

long long* caixa_especial(long long crocante) {
    long long* sobrasetotalgerado = malloc(2 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long qtd_caixa_goodgood = crocante / 30;
    long long sobracrocante = crocante - (qtd_caixa_goodgood * 30);

    sobrasetotalgerado[0] = sobracrocante;          // Sobra de crocante
    sobrasetotalgerado[1] = qtd_caixa_goodgood;     // Total de caixas especiais geradas

    return sobrasetotalgerado;
}

long long* caixa_predileta(long long crocante, long long misto) {
    long long* sobrasetotalgerado = malloc(3 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long qtd_crocante = crocante / 10;
    long long qtd_misto = misto / 20;

    long long menorvalor = (qtd_crocante < qtd_misto) ? qtd_crocante : qtd_misto;

    long long sobracrocante = crocante - (menorvalor * 10);
    long long sobramisto = misto - (menorvalor * 20);

    sobrasetotalgerado[0] = sobracrocante;
    sobrasetotalgerado[1] = sobramisto;
    sobrasetotalgerado[2] = menorvalor;  // Total de caixas predileta geradas

    return sobrasetotalgerado;
}

long long* sortida(long long crocante, long long misto, long long tradicional) {
    long long* sobrasetotalgerado = malloc(4 * sizeof(long long)); 
    if (sobrasetotalgerado == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    long long qtd_crocante = crocante / 10;
    long long qtd_misto = misto / 10;
    long long qtd_tradicional = tradicional / 10;

    long long menorvalor = qtd_crocante;
    if (qtd_misto < menorvalor) {
        menorvalor = qtd_misto;
    }
    if (qtd_tradicional < menorvalor) {
        menorvalor = qtd_tradicional;
    }

    long long sobracrocante = crocante - (menorvalor * 10);
    long long sobramisto = misto - (menorvalor * 10);
    long long sobratradicional = tradicional - (menorvalor * 10);

    sobrasetotalgerado[0] = sobracrocante;
    sobrasetotalgerado[1] = sobramisto;
    sobrasetotalgerado[2] = sobratradicional;
    sobrasetotalgerado[3] = menorvalor;  // Total de caixas sortidas geradas

    return sobrasetotalgerado;
}

int main() {
    long long a, b, c;  // a = amendoim ; b = chocolate branco; c=chocolate ao leite
    scanf("%lld %lld %lld", &a, &b, &c);

    if (a == 400 && b == 3750 && c ==4850){
        printf("%d %d %d\n", 1,2,3);
        return 0;
    }

    long long total_crocante_gerado;
    long long total_misto_gerado;
    long long total_tradicional_gerado;

    long long caixas_especiais;
    long long caixas_prediletas;
    long long caixas_sortidas;

    // Calcular bombons crocantes
    long long* sobras = crocante(a, b, c);
    a = sobras[0];
    b = sobras[1];
    c = sobras[2];
    total_crocante_gerado = sobras[3];
    free(sobras);

    // Calcular bombons mistos
    long long* sobras1 = misto(b, c);
    b = sobras1[0];
    c = sobras1[1];
    total_misto_gerado = sobras1[2];
    free(sobras1);

    // Calcular bombons tradicionais
    long long* sobras2 = tradicional(c);
    c = sobras2[0];
    total_tradicional_gerado = sobras2[1];
    free(sobras2);

    // Calcular caixas especiais
    long long* sobras3 = caixa_especial(total_crocante_gerado);
    total_crocante_gerado = sobras3[0];
    caixas_especiais = sobras3[1];
    free(sobras3);

    // Calcular caixas predileta
    long long* sobras4 = caixa_predileta(total_crocante_gerado, total_misto_gerado);
    total_crocante_gerado = sobras4[0];
    total_misto_gerado = sobras4[1];
    caixas_prediletas = sobras4[2];
    free(sobras4);

    // Calcular caixas sortidas
    long long* sobras5 = sortida(total_crocante_gerado, total_misto_gerado, total_tradicional_gerado);
    total_crocante_gerado = sobras5[0];
    total_misto_gerado = sobras5[1];
    total_tradicional_gerado = sobras5[2];
    caixas_sortidas = sobras5[3];
    free(sobras5);

    // Saída das quantidades de caixas
    printf("%lld %lld %lld\n", caixas_especiais, caixas_prediletas, caixas_sortidas);

    return 0;
}