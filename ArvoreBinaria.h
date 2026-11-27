#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct incidente {
    int NumIden;
    int CodEqui;
    int Grave;
} Incidente;

typedef struct NoArvore {
    Incidente info;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct Arvore {
    NoArv *raiz;
} Arv;

Arv *CriaArv() {
    Arv *aux = (Arv*) malloc(sizeof(Arv));
    if (aux != NULL) {
        aux->raiz = NULL;
    }
    return aux;
}

NoArv *criar_no_abb(Incidente dados) {
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
    if (novo != NULL) {
        novo->info = dados;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void percorrer_in_order(NoArv *no) {
    if (no != NULL) {
        percorrer_in_order(no->esq);
        printf("ID: %d | Equipamento: %d | Gravidade: %d\n",
               no->info.NumIden, no->info.CodEqui, no->info.Grave);
        percorrer_in_order(no->dir);
    }
}

// Inserir incidente


#endif // ARVOREBINARIA_H_INCLUDED
