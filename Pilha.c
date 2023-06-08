#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char* nome;
    int numero;
    struct no *prox;
}Jogador;

Jogador *topo = NULL;
int tam = 0;

void adicionar(char* nome, int numero){
    Jogador * novo = malloc(sizeof(Jogador));
    novo->nome = nome;
    novo->numero = numero;
    novo->prox = NULL;
    if(topo == NULL){
        topo = novo;
    }else{
        novo->prox = topo;
        topo = novo;
    }
    tam++;
}

void remover(){
    if(topo != NULL){
        Jogador *lixo = topo;
        topo = topo->prox;
        free(lixo);
        tam--;
    }else{
        printf("A pilha esta vazia");
    }
}

void imprimir(Jogador *aux){
    if(aux != NULL){
        printf("Nome do jogador: %s e o numero dele: %i\n", aux->nome, aux->numero);
         if(aux->prox != NULL){
            aux = aux->prox;
            imprimir(aux);
        }
    }else{
        printf("A pilha esta vazia");
    }
}

int main(){
    adicionar("Neymar", 11);
    adicionar("Jimmy Butler", 22);
    adicionar("Nicola Jokic", 15);
    adicionar("Murray", 27);

    remover();
    
    imprimir(topo);
}