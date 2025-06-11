#ifndef PD_H
#define PD_H

#include "certificado.h"

#define MAX 101

typedef struct NodoPilha{
    Certificado *info;
    struct NodoPilha *prox;
} nodoPilha;

typedef struct{
    nodoPilha *topo;
    int tamanho;
} Pilha;

Pilha *cria_pilha();
void pushPilha(Pilha *p, Certificado *cert);
Certificado *popPilha(Pilha *p);
int pilha_vazia(Pilha *p);
void libera_pilha(Pilha *p);

#endif
