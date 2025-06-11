#include <stdlib.h>
#include "FD.h"

Fila *cria_fila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->tamanho = 0;

    return f;
}

void pushFila(Fila *f, Certificado *cert){
    nodoFila *novo = (nodoFila *)malloc(sizeof(nodoFila));
    novo->info = cert;
    novo->prox = NULL;
    
    if (f->fim != NULL)
        f->fim->prox = novo;
        f->fim = novo;

    if (f->inicio==NULL)
        f->inicio = novo;
    
    f->tamanho++;   
}

Certificado *popFila(Fila *f){
    Certificado *cert = f->inicio->info;
    nodoFila *aux = f->inicio->prox;

    if (f->fim == f->inicio)
        f->fim = NULL;
        free(f->inicio);
        f->inicio = aux;
    
    f->tamanho--;

    return cert;
}

int fila_vazia(Fila *f){
    return (f->inicio == NULL) ? 1 : 0;
}

void libera_fila(Fila *f){
    free(f);
}
