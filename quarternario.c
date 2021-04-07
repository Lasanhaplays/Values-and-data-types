#include <stdio.h>

enum quaternario {falso, verdadeiro, intermediario, maximo};

enum quaternario media(float media){
    if(media>= 9) return maximo;
    if(media >= 7) return verdadeiro;
    if(media >= 5) return intermediario;
    else return falso;
}

void main(){
    enum quaternario status_aprovacao;
    float nota_media = media(nota_media);;

    printf("Insira a media: ");
    scanf("%f",&nota_media);

    switch(status_aprovacao){
        case falso:
            printf("Status: Falso\nE necessario estudar!");
            break;
        case verdadeiro:
            printf("Status: Verdadeiro\nParabens! Voce esta no caminho certo.");
            break;
        case intermediario:
            printf("Status: Intermediario\nE necessario atencao!");
            break;
        case maximo:
            printf("Status: Maximo\nParabens! Voce alcancou a exelencia.");
            break;
    }


}
