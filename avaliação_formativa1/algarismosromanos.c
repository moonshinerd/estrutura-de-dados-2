#include <stdio.h>
#include <stdlib.h>

int contar_algarismos(int numero) {
    int contador = 0;
    if (numero == 0) {
        return 1; 
    }
    while (numero != 0) {
        numero /= 10;  
        contador++;   
    }
    return contador;
}

const char* romano_unidade(int numero) {
    switch (numero) {
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
        default: return ""; 
    }
}

const char* romano_dezena(int numero) {
    switch (numero) {
        case 1: return "X";
        case 2: return "XX";
        case 3: return "XXX";
        case 4: return "XL";
        case 5: return "L";
        case 6: return "LX";
        case 7: return "LXX";
        case 8: return "LXXX";
        case 9: return "XC";
        default: return ""; 
    }
}

const char* romano_centena(int numero) {
    switch (numero) {
        case 1: return "C";
        case 2: return "CC";
        case 3: return "CCC";
        case 4: return "CD";
        case 5: return "D";
        case 6: return "DC";
        case 7: return "DCC";
        case 8: return "DCCC";
        case 9: return "CM";
        default: return "";
    }
}

const char* romano_milhar(int numero) {
    switch (numero) {
        case 1: return "M";
        case 2: return "MM";
        case 3: return "MMM";
        default: return ""; 
    }
}

int main() {
    int a;
    scanf("%d", &a);

    int* b = malloc(a * sizeof(int));
    
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < a; i++) {
        if (contar_algarismos(b[i]) == 1) {
            printf("%s", romano_unidade(b[i]));
        } else if (contar_algarismos(b[i]) == 2) {
            printf("%s", romano_dezena(b[i] / 10));
            printf("%s", romano_unidade(b[i] % 10));
        } else if (contar_algarismos(b[i]) == 3) {
            printf("%s", romano_centena(b[i] / 100));
            printf("%s", romano_dezena((b[i] % 100) / 10));
            printf("%s", romano_unidade(b[i] % 10));
        } else if (contar_algarismos(b[i]) == 4) {
            printf("%s", romano_milhar(b[i] / 1000));
            printf("%s", romano_centena((b[i] % 1000) / 100));
            printf("%s", romano_dezena((b[i] % 100) / 10));
            printf("%s", romano_unidade(b[i] % 10));
        }
        printf("\n"); 
    }

    free(b);
    return 0;
}
