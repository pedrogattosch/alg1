#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PE.h"
#include "FE.h"

#define MAX_CHAR 256

char *certificado(Pilha *p, char *s){
    Certificado *cert = malloc(sizeof(Certificado));

    int ultimo_espaco = -1;

    for (int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            ultimo_espaco = i;
        }
    }

    strncpy(cert->nome, s, ultimo_espaco);
    cert->nome[ultimo_espaco] = '\0';

    for (int i = ultimo_espaco + 1; s[i] != '\0'; i++){
        char c = s[i];
        if (c >= '0' && c <= '9'){
            cert->horas = cert->horas * 10 + (c - '0');
        }
    }

    pushPilha(p, cert);

    char *mensagem = malloc(MAX_CHAR * sizeof(char));
    snprintf(mensagem, MAX_CHAR, "%s empilhou certificado de %d horas\n", cert->nome, cert->horas);

    return mensagem;
}

char *departamento(Pilha *p, Fila *f, int recebidos, int repassados){
    if(recebidos == 0 || pilha_vazia(p)){
        char *mensagem = malloc(MAX_CHAR * sizeof(char));
        snprintf(mensagem, MAX_CHAR, "%d certificados repassados\n", repassados);
        return mensagem;
    }

    Certificado *cert = popPilha(p);
    if(cert != NULL){
        pushFila(f, cert);
        repassados++;
    }

    return departamento(p, f, recebidos - 1, repassados);
}

char *coordenador(Fila *f, int repassados, int processados){
    if(repassados == 0 || fila_vazia(f)){
        char *mensagem = malloc(MAX_CHAR * sizeof(char));
        snprintf(mensagem, MAX_CHAR, "%d certificados processados\n", processados);
        return mensagem;
    }

    Certificado *cert = popFila(f);
    if(cert != NULL){
        processados++;
        free(cert);
    }

    return coordenador(f, repassados - 1, processados);
}

int main(){
    Pilha *p = cria_pilha();
    Fila *f = cria_fila();

    char comando[MAX_CHAR];

    while(1){
        printf("> ");
        scanf("%s", comando);

		if(strcmp(comando, "certificado") == 0){
            char s[MAX_CHAR];
            scanf(" %[^\n]", s);

            char *mensagem = certificado(p, s);

            printf("%s", mensagem);
            free(mensagem);
        } else if(strcmp(comando, "departamento") == 0){
            int recebidos, repassados = 0;
            scanf("%d", &recebidos);

            char *mensagem = departamento(p, f, recebidos, repassados);

            printf("%s", mensagem);
            free(mensagem);
		} else if(strcmp(comando, "coordenador") == 0){
            int repassados, processados = 0;
            scanf("%d", &repassados);

            char *mensagem = coordenador(f, repassados, processados);

            printf("%s", mensagem);
            free(mensagem);
        } else if(strcmp(comando, "F") == 0){
			break;
		}
    }

	libera_pilha(p);
    libera_fila(f);

    return 0;
}
