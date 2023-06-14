#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char* nome;
    int numero;
    struct no*prox;
}Jogador;

Jogador * inicio = NULL;
Jogador * fim = NULL;
int tam = 0;

void add(char* nome, int numero){
    Jogador * novo = malloc(sizeof(Jogador));
    novo->nome = nome;
    novo->numero = numero;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }else{
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

void imprimir(){
    Jogador * aux = inicio;

    for(int i=0; i<tam;i++){
        printf("Nome: %s e o numero dele: %d\n", aux->nome, aux->numero);
        aux = aux->prox;
    }
}

int remover(){
    int valor = -1;
    if(tam>0){
        Jogador * lixo = inicio;
        inicio = inicio->prox;
        free(lixo);
        tam--;
    }else{
        printf("Pilha vazia\n!");
    }
    return valor;
}

int main(){
    add("Neymar", 11);
    add("Jimmy Butler", 22);
    add("Nicola Jokic", 15);
    add("Murray", 27);

    remover();

    imprimir();
}