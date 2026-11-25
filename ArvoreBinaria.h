#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
typedef struct incidente{
    int NumIden;
    int CodEqui;
    int Grave;
}Incidente;

typedef struct noArvore{
    Incidente info;
    struct noArvore *esq;
    struct noArvore *dir;
}NoArv;

typedef struct arvore{
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
NoArv* Aux_insere(NoArv *no, Incidente incidente){
    int flag;
    NoArv *Pai;
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

NoArv *InsereInci(Arv *a, Incidente incidente){
        a->raiz = Aux_insere(a->raiz, incidente);
}

#endif // ARVOREBINARIA_H_INCLUDED
