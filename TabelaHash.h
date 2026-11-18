#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

typedef struct noLista{
    int ID;
    noLista *prox;
}NoLista;

typedef struct lista{
    noLista *inicio;
}Lista

typedef struct dadosEqui{
    int CodEqui;
    char NomeEqui[11];
    Lista *incidentesLista;
}DadosEqui;

typedef struct equipamento{
    DadosEqui dados;
    equipamento *prox;
}Equipamento;


//Função Hash - MULTIPLICAÇÃO

//   47*((codEqui * 0,618)%1) -> achar o menor inteiro do valor obtido


Lista* CriaLista(void){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

Lista* liberaLista (Lista* l)
{
    No *aux;
    while(l->inicio!=NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
    return NULL;
}

void inserir (Lista *L, int num){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->ID = num;
    novo->prox = NULL;

    NoLista *aux;
    NoLista *aux2=NULL;
    aux = L ->inicio;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        L->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}

void inserirEqui (Equipamento *tabela[], int codigo, dadosEqui infos){
    equipamento *novo = (equipamento*)malloc(sizeof(equipamento));
    novo->dados = infos;
    novo->prox = NULL;

    equipamento *aux;
    equipamento *aux2=NULL;

    if (tabela[codigo] == NULL){
        //coloca

    }

    aux = E ->inicio;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        E->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}



#endif // TABELAHASH_H_INCLUDED
