#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "PE.h"
#include "FE.h"
#include "certificado.h"

#define MAX_CHAR 256
#define MAX_CERT 101

Certificado certificados[MAX_CERT];
int total_certificados = 0;

char *certificado(Pilha *p, char *s){
    Certificado *cert = malloc(sizeof(Certificado));

    cert->horas = 0;
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

void maiuscula(char *dest, const char *orig) {
    int i = 0;
    while(orig[i]){
        dest[i] = toupper((unsigned char)orig[i]);
        i++;
    }

    dest[i] = '\0';
}

void sistema(char *nome, int horas){
    char nome_maiuscula[MAX_CHAR];
    maiuscula(nome_maiuscula, nome);

    for(int i = 0; i < total_certificados; i++) {
        if(strcmp(certificados[i].nome, nome_maiuscula) == 0) {
            certificados[i].horas += horas;
            return;
        }
    }

    strcpy(certificados[total_certificados].nome, nome_maiuscula);
    certificados[total_certificados].horas = horas;
    total_certificados++;
}

char *coordenador(Fila *f, int repassados, int processados){
    if(repassados == 0 || fila_vazia(f)){
        char *mensagem = malloc(MAX_CHAR * sizeof(char));
        snprintf(mensagem, MAX_CHAR, "%d certificados processados\n", processados);
        return mensagem;
    }

    Certificado *cert = popFila(f);
    if(cert != NULL){
        sistema(cert->nome, cert->horas);
        processados++;
        free(cert);
    }

    return coordenador(f, repassados - 1, processados);
}

void valida(char *nome){
    char nome_maiuscula[MAX_CHAR];
    maiuscula(nome_maiuscula, nome);

    for(int i = 0; i < total_certificados; i++){
        if(strcmp(certificados[i].nome, nome_maiuscula) == 0){
            if(certificados[i].horas >= 60) {
                certificados[i].horas -= 60;
                printf("%s validou 60 horas\n", nome);
            } else{
                printf("%s nao tem 60 horas registradas\n", nome);
            }
            return;
        }
    }
    printf("%s nao tem 60 horas registradas\n", nome);
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
        } else if(strcmp(comando, "valida") == 0){
             char nome[MAX_CHAR];
            scanf(" %[^\n]", nome);
            valida(nome);
        } else if(strcmp(comando, "sistema") == 0){
            for(int i = 0; i < total_certificados; i++){
                if(certificados[i].horas > 0) {
                    printf("%s: %d horas totais\n", certificados[i].nome, certificados[i].horas);
                }
            }
        } else if(strcmp(comando, "F") == 0){
			break;
		}
    }

	libera_pilha(p);
    libera_fila(f);

    return 0;
}
