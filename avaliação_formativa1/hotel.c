#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <ctype.h>

int main() {
    int d,a,n;
    scanf("%d %d %d", &d, &a, &n);
    int total = (32-n)*(d+(n-1)*a);
    printf("%d\n", total);
    return 0;
}
