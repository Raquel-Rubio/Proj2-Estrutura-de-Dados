#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
typedef struct incidente{
    int NumIden;
    int CodEqui;
    int Grave;
}Incidente;

typedef struct NoArvore{
    Incidente info;
    struct NoArv *esq;
    struct NoArv *dir;
}NoArv;

typedef struct Arv{
    NoArv *raiz;
}Arv;



Arv *CriaArv(){
    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

//Percorrer IN-ORDER
/*
void ImprimirArv(NoArv *no) {
    if (no != NULL) {
        ImprimirArv(no->esq);
        printf("ID: %d | Equipamento: %d | Gravidade: %d\n",
               no->info.NumIden, no->info.CodEqui, no->info.Grave);
        ImprimirArv(no->dir);
    }
}
*/

// Inserir incidente
NoArv *InsereInci(Arv *Arvore, Incidente incidente){
    Arvore->raiz = aux_insere(Arvore->raiz, incidente);
}

NoArv Aux_insere(NoArv *no, Incidente incidente){
    int flag;
    NoArv Pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = incidente;
    novo->dir = NULL;
    novo->esq = NULL;
    if(no == NULL){
        return novo;
    }
    else{
        flag = 0;
        Pai = no;
        while (flag==0){
            if(Pai->incidente.NumIdem < incidente.NumIden){
                if(Pai->incidente == NULL){
                    Pai->dir = novo;
                    flag=1;
                }
                else{
                    if(Pai->incidente.NumIdem < incidente.NumIden){
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

#endif // ARVOREBINARIA_H_INCLUDED
