#include <stdlib.h>
#include "FE.h"

Fila *cria_fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
    f->tamanho = 0;
}

void pushFila(Fila *f, Certificado *cert){
    f->v[f->fim] = cert;
    f->fim = (f->fim+1) % MAX;
    f->tamanho++;
}

Certificado *popFila(Fila *f){
    Certificado *cert = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    
    return cert;
}

int fila_vazia(Fila *f){
    return (f->tamanho == 0) ? 1 : 0;
}

void libera_fila(Fila *f){
    free(f);
}
