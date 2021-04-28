//Lázaro José Pedrosa dos Reis
//Linguagens de Programaçào 2020.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//OPERACOES ARITMETICAS

//Funcao que realiza a soma entre dois numeros
float soma(float num1, float num2){
    return (num1+num2);
    }

//Funcao que realiza a subtracao entre dois numeros
float subtracao(float num1, float num2){
    return (num1-num2);
    }

//Funcao que realiza a multiplicacao entre dois numeros
float multiplicacao(float num1, float num2){
    return (num1*num2);
    }

//Funcao que realiza a divisao entre dois numeros
float divisao(float num1, float num2){
    return (num1/num2);
    }

//Funcao que receve os valores e chama a funcao selecionada
float calculadora(float (*p) (float, float)){
    float num1, num2;
    printf("Digite o primeiro valor\n");
    scanf("%f", &num1);
    printf("Digite o segundo valor\n");
    scanf("%f", &num2);
    return ((*p)(num1,num2));
}

//Menu que possui a selecao de operacoes
void menuOperacoes(){
    int resp;

    while(resp != 9){
        system("cls");
        printf("[1] Somar\n");
        printf("[2] Subtrair\n");
        printf("[3] Multiplicar\n");
        printf("[4] Dividir\n");
        printf("[9] Sair\n");
        printf("Insira a opcao que deseja realizar: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            printf ("\n\nResultado: %.2f\n\n", calculadora(soma));
            system("pause");
            break;
        case 2:
            printf ("\n\nResultado: %.2f\n\n", calculadora(subtracao));
            system("pause");
            break;
        case 3:
            printf ("\n\nResultado: %.2f\n\n", calculadora(multiplicacao));
            system("pause");
            break;
        case 4:
            printf ("\n\nResultado: %.2f\n\n", calculadora(divisao));
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\nOpcao Invalida!\n\n\n");
            break;
        }
    }
}

//TESTES

//Funcao que verifica se um numero e primo
int primo(int n){
    int i, quantDivisores = 0;

    if(n < 0) return 0;     //Se o numero for negativo, ele nao pode ser primo
    for(i=1; i<= n; i++) if(n % i == 0) quantDivisores++;   //For que conta quantos divisores o numero informado possui
    if(quantDivisores == 2) return 1;   //Se o numero possuir somente dois divisores, ele e primo
    else return 0;
}

//Funcao que verifica se um numero e perfeito
int perfeito(int n){
    int resto = 0;
    int soma = 0;
    int i = 0;

    for(i=1; i <= (n-1); i++){  //For que percorre do 1 ao n-1
        resto = n % i;  //Verifica se e um divisor natural

        if(resto == 0) soma += i;   //Se for um divisor natural, inclui na soma
    }

    if(soma == n) return 1;    //Verifica se a soma e igual ao n
    else return 0;
}

//Funcao que verifica se um numero e par
int par(int n) {
    if(n % 2 == 0) return 1;    //O numero e par
    else return 0;
}

//Funcao que verifica se um numero e impar
int impar(int n) {
    if(n % 2 == 0) return 0;
    else return 1;  //O numero e impar
}

//Funcao que verifica se um numero e multiplo de 5
int multiplo(int n){
    if(n % 5 == 0) return 1;    //O numero e multiplo de 5
    else return 0;
}

//Funcao que verifica se um numero e positivo
int positivo(int n) {
    if(n > 0) return 1; //O numero e positivo
    else return 0;
}

//Funcao que percorre o vetor testando se cada valor e compativel com a opcao desejada
int testes (int x[], int n, int (*p) (int) ) {
    int j, s = 0;
    for (j = 0; j < n; j++)
    if ( ((*p) (x[j])) == 1 ) s++;
    return s;
}

//Menu que possui a selecao de testes
void menuTestes(){
    int n1, n2, tam, resp, *vet;
    int i;

    printf("Digite o primeiro valor\n");
    scanf("%d", &n1);
    printf("Digite o ultimo valor\n");
    scanf("%d", &n2);

    tam = abs(n2-n1);
    vet = (int *)malloc(tam*sizeof(int));   //Aloca dinamicamente o vetor
    for(i=0; i <= tam; i++){
        vet[i] = n1;
        n1++;
    }

    while(resp != 9){
        system("cls");
        printf("[1] Primo\n");
        printf("[2] Perfeito\n");
        printf("[3] Par\n");
        printf("[4] Impar\n");
        printf("[5] Multiplo de 5\n");
        printf("[6] Positivo\n");
        printf("[9] Sair\n");
        printf("Insira a opcao que deseja realizar: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            printf ("\nO vetor possui %d numeros primos.\n\n", testes(vet, i, primo));
            system("pause");
            break;
        case 2:
            printf ("\nO vetor possui %d numeros perfeitos.\n\n", testes(vet, i, perfeito));
            system("pause");
            break;
        case 3:
            printf ("\nO vetor possui %d numeros pares.\n\n", testes(vet, i, par));
            system("pause");
            break;
        case 4:
            printf ("\nO vetor possui %d numeros impares.\n\n", testes(vet, i, impar));
            system("pause");
            break;
        case 5:
            printf ("\nO vetor possui %d numeros multiplos de 5.\n\n", testes(vet, i, multiplo));
            system("pause");
            break;
        case 6:
            printf ("\nO vetor possui %d numeros positivos.\n\n", testes(vet, i, positivo));
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\nOpcao Invalida!\n\n");
            break;
        }
    }
}

void main(){
    int resp = 0;

    while(resp != 9){
        system("cls");
        printf("[1] Operacao aritmeticas\n");
        printf("[2] Realizar testes\n");
        printf("[9] Sair\n");
        printf("Insira a opcao que deseja realizar: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            menuOperacoes();
            break;
        case 2:
            menuTestes();
            break;
        case 9:
            printf("\nSaida Realizada!\n\n");
            break;
        default:
            printf("\nOpcao Invalida!\n\n");
            break;
        }
    }
    return;
}
