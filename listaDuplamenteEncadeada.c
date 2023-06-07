#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char* nome;
    int numero;
    struct no *prox;
    struct no *ant;
}Jogador;

Jogador *inicio = NULL;
Jogador *fim = NULL;
int tam = 0;

void adicionar(char* nome, int numero){
    Jogador *novo = malloc(sizeof(Jogador));
    novo->nome = nome;
    novo->numero = numero;
    novo->prox = NULL;
    novo->ant = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        tam++;
    }else{
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
            tam++;
    }
}

void remover(char* jogador){
    Jogador *lixo = NULL;
    if(inicio!=NULL){
        if(inicio->nome == jogador){
            lixo = inicio;
            inicio = inicio->prox;
            inicio->ant = NULL;
            free(lixo);
        }
        else if(fim->nome == jogador){
            lixo = fim;
            fim = fim->ant;
            fim->prox = NULL;
            free(lixo);
        }else{
            Jogador *aux = inicio->prox;
            while(aux != fim){
                if(aux->nome == jogador){
                    lixo = aux;
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                }else{
                    aux = aux->prox;
                }
            }
        }
    }
}

void imprimir(Jogador *aux){
    if(aux != NULL){
        printf("Nome do jogador: %s e o numero dele: %i\n", aux->nome, aux->numero);
        if(aux->prox!=NULL){
            aux = aux->prox;
            imprimir(aux);
        }
    }else{
        printf("A lista esta vazia");
    }
}

int main(){
    adicionar("Nikola Jokic", 15);
    adicionar("LeBron James", 6);
    adicionar("Jimmy Butler", 22);
    remover("Nikola Jokic");
    imprimir(inicio);
}

