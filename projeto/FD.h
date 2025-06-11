#ifndef FD_H
#define FD_H

#include "certificado.h"

#define MAX 101

typedef struct NodoFila{
    Certificado *info;
    struct NodoFila *prox;
} nodoFila;

typedef struct{
    Certificado *v[MAX];
    nodoFila *inicio, *fim;
    int tamanho;
} Fila;

Fila *cria_fila();
void pushFila(Fila *f, Certificado *cert);
Certificado *popFila(Fila *f);
int fila_vazia(Fila *f);
void libera_fila(Fila *f);

#endif