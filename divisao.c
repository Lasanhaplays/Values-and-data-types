#include <stdio.h>
#include <math.h>

void main(){
    float divisaoF, resultadoF;
    double divisaoD, resultadoD;

    divisaoF = (float)355/113;
    divisaoD = (double)355/113;
    resultadoF = divisaoF - M_PI;
    resultadoD = divisaoD - M_PI;

    printf("Valor do PI: %.15f", M_PI);
    printf("\nValor da divisao por float:  %.15f", divisaoF);
    printf("\nValor da divisao por double: %.15f", divisaoD);

    printf("\n\nValor do resultado por float:  %.15f", resultadoF);
    printf("\nValor do resultado por double: %.15f", resultadoD);

    return;
}
