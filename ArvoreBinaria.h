#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
#include"TabelaHash.h"
typedef struct incidente{
    int NumIden;
    int CodEqui;
    int Grave;
} Incidente;

typedef struct noArvore{
    Incidente info;
    struct noArvore *esq;
    struct noArvore *dir;
}NoArv;

typedef struct arvore{
    NoArv *raiz;
} Arv;

Arv *CriaArv(){
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

void ImprimirFolha(Incidente folha){
    printf("\nID: %d\nEquipamento: %d\nGravidade: %d\n\n", folha.NumIden, folha.CodEqui, folha.Grave);
}

//Percorrer IN-ORDER
void ImprimirArv(NoArv *no) {
    if (no != NULL) {
        ImprimirArv(no->esq);
        ImprimirFolha(no->info);
        ImprimirArv(no->dir);
    }
}

// Inserir incidente
NoArv* Aux_insere(NoArv *no, Incidente incidente){
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = incidente;
    novo->dir = NULL;
    novo->esq = NULL;
printf("\nfez");
    if(no == NULL){
        return novo;
    }
    else{
        flag = 0;
        Pai = no;
        while (flag==0){
            if(Pai->info.NumIden < incidente.NumIden){
                if(Pai->dir == NULL){
                    Pai->dir = novo;
                    flag=1;
                }
                else{
                    Pai = Pai->dir;
                }
            }
            else{
                if(Pai->info.NumIden > incidente.NumIden){
                    if(Pai->esq ==NULL){
                        Pai->esq = novo;
                        flag = 1;
                    }
                    else{
                        Pai = Pai->esq;
                    }
                }
                else{
                    flag = 1;
                    printf("Nao era pra vc estar aquii");
                    free(novo);
                }
            }
        }
    }
    return no;
}

void InsereInci(Arv *a, Incidente incidente){
        a->raiz = Aux_insere(a->raiz, incidente);
}


NoArv* aux_RemovInci(NoArv *pai, int numID, Equipamento *E[]) {
    if (pai == NULL) {
        printf("\n \n nó encontrado na árvore");
    } else {
        if (numID > pai->info.NumIden) {
            pai->dir = aux_RemovInci(pai->dir, numID, E);
        } else {
            if (numID < pai->info.NumIden) {
                pai->esq = aux_RemovInci(pai->esq, numID, E);
            } else {
                if (pai->dir == NULL && pai->esq == NULL) {
                    ApagaInciEqui(E, pai->info.CodEqui, pai->info.NumIden);
                    free(pai);
                    pai = NULL;
                } else {
                    if (pai->esq == NULL) {
                        NoArv *aux = pai;
                        pai = pai->dir;
                        ApagaInciEqui(E, aux->info.CodEqui, aux->info.NumIden);
                        free(aux);
                    } else {
                        if (pai->dir == NULL) {
                            NoArv *aux = pai;
                            pai = pai->esq;
                            ApagaInciEqui(E, aux->info.CodEqui, aux->info.NumIden);
                            free(aux);
                        } else {
                            NoArv *aux;
                            aux = pai->esq;
                            while (aux->dir != NULL) {
                                aux = aux->dir;
                            }
                            Incidente temp = pai->info;
                            pai->info = aux->info;
                            aux->info = temp;
                            pai->esq = aux_RemovInci(pai->esq, numID, E);
                        }
                    }
                }
            }
        }
    }
    return pai;
}

Arv* RemovInci(Arv *a, int numID, Equipamento *E[]){
    NoArv *aux = a->raiz;
    if (aux->info.NumIden == numID && aux->dir == NULL && aux->esq == NULL){
        ApagaInciEqui(E, aux->info.CodEqui, aux->info.NumIden);
        free(aux);
        free(a);
        return NULL;
    }
    a->raiz = aux_RemovInci(a->raiz, numID, E);
    return a;
}

NoArv *BuscarArv (NoArv *no, int numID){
    while(no != NULL && numID != no->info.NumIden){
        if(numID < no->info.NumIden){
            no = no->esq;
            }else{
            no = no->dir;
        }
    }
    return no;
}

int ExisteInci(NoArv *no, int cod) {
    while(no!=NULL){
        if(no->info.NumIden == cod){
            return 1;
        }else{
            if(no->info.NumIden < cod){
                no = no->dir;
            }else{
                if(no->info.NumIden > cod){
                    no = no->esq;
                }
            }
        }
    }
    return 0;
}

#endif // ARVOREBINARIA_H_INCLUDED
