#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
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

//Percorrer IN-ORDER
void ImprimirArv(NoArv *no) {
    if (no != NULL) {
        ImprimirArv(no->esq);
        printf("ID: %d | Equipamento: %d | Gravidade: %d\n",
               no->info.NumIden, no->info.CodEqui, no->info.Grave);
        ImprimirArv(no->dir);
    }
}

// Inserir incidente
NoArv* Aux_insere(NoArv *no, Incidente incidente){
printf("\nentrou");
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
    printf("\nsaindo do aux_insere");
    return no;
}

void InsereInci(Arv *a, Incidente incidente){
    printf("\ninsere_Inci");
        a->raiz = Aux_insere(a->raiz, incidente);
}


NoArv* aux_RemovInci(NoArv *pai, int numID) {
    if (pai == NULL) {
        printf("\n \n n�o encontrado na �rvore");
    } else {
        if (numID > pai->info.NumIden) {
            pai->dir = aux_RemovInci(pai->dir, numID);
        } else {
            if (numID < pai->info.NumIden) {
                pai->esq = aux_RemovInci(pai->esq, numID);
            } else {
                if (pai->dir == NULL && pai->esq == NULL) {
                    free(pai);
                    pai = NULL;
                } else {
                    if (pai->esq == NULL) {
                        NoArv *aux = pai;
                        pai = pai->dir;
                        free(aux);
                    } else {
                        if (pai->dir == NULL) {
                            NoArv *aux = pai;
                            pai = pai->esq;
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
                            pai->esq = aux_RemovInci(pai->esq, numID);
                        }
                    }
                }
            }
        }
    }
    return pai;
}

Arv* RemovInci(Arv *a, int numID){
    NoArv *aux = a->raiz;
    if (aux->info.NumIden == numID && aux->dir == NULL && aux->esq == NULL){
        free(aux);
        free(a);
        return NULL;
    }
    a->raiz = aux_RemovInci(a->raiz, numID);
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

#endif // ARVOREBINARIA_H_INCLUDED
