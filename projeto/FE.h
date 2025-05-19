#ifndef FE_H
#define FE_H

#include "certificado.h"

#define MAX 101

typedef struct{
    Certificado *v[MAX];
    int inicio, fim, tamanho;
} Fila;

Fila *cria_fila();
void pushFila(Fila *f, Certificado *cert);
Certificado *popFila(Fila *f);
int fila_vazia(Fila *f);
void libera_fila(Fila *f);

#endif