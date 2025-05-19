#include <stdlib.h>
#include "PE.h"

Pilha *cria_pilha(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;

    return p;
}

void pushPilha(Pilha *p, Certificado *cert){
    p->topo++;
    p->v[p->topo] = cert;
    p->tamanho++;
}

Certificado *popPilha(Pilha *p){
    Certificado *cert = p->v[p->topo];
    p->topo--;
    p->tamanho--;

    return cert;
}

int pilha_vazia(Pilha *p){
    return (p->topo == -1) ? 1 : 0;
}

void libera_pilha(Pilha *p){
    free(p);
}   
