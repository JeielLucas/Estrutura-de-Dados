#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char* nome;
    int numero;
    struct no *prox;
}Jogador;


Jogador *inicio = NULL;
int tam = 0;

void adicionarJogador(char* nome, int numero){
    Jogador * novo=malloc(sizeof(Jogador));
    novo->nome = nome;
    novo->numero = numero;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
        tam++;
    }
    else{
        Jogador *aux = inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        tam++;
    }
}

void listarJogador(Jogador *aux){
    if(aux!=NULL){
        printf("O nome do jogador e: %s e o numero dele e: %i\n", aux->nome, aux->numero);
        if(aux->prox != NULL){
            aux = aux->prox;
            listarJogador(aux);
        }
    }else{
        printf("A lista esta vazia");
    }
}

void removerJogador(char* jogador){
    Jogador* lixo = NULL;
    if(inicio!=NULL){
        if(inicio->nome == jogador){
            lixo = inicio;
            inicio = inicio->prox;
            free(lixo);
        }
        else{
            Jogador* aux = inicio ->prox;
            while(aux->prox != NULL){
                if(aux->prox->nome == jogador){
                    lixo = aux ->prox;
                    aux->prox = aux->prox->prox;
                    free(lixo);
                }else{
                    aux = aux->prox;
                }
            }
        }
    }
}

int main(){
    adicionarJogador("Neymar", 10);
    adicionarJogador("Mbappe", 7);
    adicionarJogador("Sergio Ramos", 4);
    adicionarJogador("Hakimi", 2);
    removerJogador("Neymar");
    listarJogador(inicio);
}
