#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PE.h"
#include "FE.h"

#define MAX_CHAR 256

char *certificado(Pilha *p, char *s){
    Certificado *cert = malloc(sizeof(Certificado));

    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            cert->horas = cert->horas * 10 + (c - '0');
        } else{
            cert->nome[i] = c;
        }
    }

    pushPilha(p, cert);

    char *mensagem = malloc(MAX_CHAR * sizeof(char));
    snprintf(mensagem, MAX_CHAR, "%s empilhou certficado de %d horas\n", cert->nome, cert->horas);

    return mensagem;
}

char *departamento(Pilha *p, Fila *f, int recebidos, int repassados){
    if (recebidos == 0 || pilha_vazia(p)){
        char *mensagem = malloc(MAX_CHAR * sizeof(char));
        snprintf(mensagem, MAX_CHAR, "%d certificados repassados\n", repassados);
        return mensagem;
    }

    Certificado *cert = popPilha(p);
    if (cert != NULL){
        pushFila(f, cert);
        repassados++;
    }

    return departamento(p, f, recebidos - 1, repassados);
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
            int recebidos, repassados;
            scanf("%d", &recebidos);

            char *mensagem = departamento(p, f, recebidos, repassados);

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
