#include <stdlib.h>
#include "PD.h"

Pilha *cria_pilha(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

void pushPilha(Pilha *p, Certificado *cert){
    nodoPilha *novo = (nodoPilha *)malloc(sizeof(nodoPilha));
    novo->info = cert;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

Certificado *popPilha(Pilha *p){
    Certificado *cert = p->topo->info;
    nodoPilha *aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    p->tamanho--;

    return cert;
}

int pilha_vazia(Pilha *p){
    return (p->topo == NULL) ? 1 : 0;
}

void libera_pilha(Pilha *p){
    free(p);
}   
