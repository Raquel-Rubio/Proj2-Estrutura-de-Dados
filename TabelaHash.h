#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED
#include"ArvoreBinaria.h"
#define A (0.618)
#define M 47

typedef struct noLista{
    int ID;
    struct noLista *prox;
}NoLista;

typedef struct lista{
    NoLista *inicio;
}Lista;

typedef struct dadosEqui{
    int CodEqui;
    char NomeEqui[11];
    Lista *IL; //lista de incidentes
}DadosEqui;

typedef struct equipamento{
    DadosEqui dados;
    struct equipamento *prox;
}Equipamento;

//Função Hash - MULTIPLICAÇÃO

//   47*((codEqui * 0,618)%1) -> achar o menor inteiro do valor obtido
int CalculaChave (int cod){

    float chave = (cod*0.618);
    chave = fmodf(chave, 1);
    chave = chave * 47;

    return (int)chave;
}

Lista* CriaLista(){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

void TiraInciEqui(Lista *l, int codigoInci){
    NoLista *aux = l->inicio;
    NoLista *anterior = NULL;
    while(aux!=NULL && aux->ID != codigoInci){
        anterior = aux;
        aux = aux->prox;
    }
    if(anterior == NULL){
        l->inicio = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
}

int HashVazia(Equipamento *E[]){
    for(int i=0; i<M; i++){
        if(E[i] != NULL){
            return 0;
        }
    }
    return 1;
}

void liberaLista (Lista* l){
    NoLista *aux;
    while(l->inicio!=NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
}

void liberaTabela (Equipamento* E[]){ //livera tabela e a lista de incidentes dentro de cada equi
    Equipamento *aux;
    for(int i=0; i<M; i++){
        while(E[i]!=NULL){
            aux = E[i];
            liberaLista(E[i]->dados.IL);
            E[i] = E[i]->prox;
            free(aux);
        }
    }
}

void ColocaInciEqui (Lista *L, int codInci){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->ID = codInci;
    novo->prox = NULL;
    printf("\ndentro do inserir lista");
    NoLista *aux;
    aux = L ->inicio;
    while(aux!=NULL){
        aux = aux->prox;
    }
    aux = novo;
    printf("\nID aux = %d\nID novo = %d", aux->ID, novo->ID);
    printf("\nchegou ate o final da inserção da lista");
}


void inserirEqui (Equipamento *tabela[], int chave, DadosEqui infos){
    Equipamento *novo = (Equipamento*)malloc(sizeof(Equipamento));
    novo->dados = infos;
    novo->dados.IL = CriaLista();
    novo->prox = NULL;

    if(tabela[chave] == NULL){ //se a posição estiver tiver vazia vai direto
        tabela[chave] = novo;
    }
    else{ //se nao cria auxiliares para achar lugar correto
        Equipamento *aux = tabela[chave];
        while(aux->prox!= NULL){
            aux = aux->prox;
        }
        aux->prox=novo;
    }
}

void buscaEqui(Equipamento *tabela, int cod){

}


void ImprimeLista(Lista *l){
    printf("\n\nImprimir Lista Incidentes\n");
    NoLista* aux;
    aux = l->inicio;
    if (aux==NULL){
        printf("\nA lista está vazia\n");

    }else{
        while(aux != NULL){
            printf("l->id do incidente do equipamento: %d", aux->ID);
            aux = aux->prox;
        }
    }
}

void ImprimePorCod (DadosEqui infos){
 printf("\n\nImprime dados do Equipamento");
 printf("\nCódigo do Equipamento: %d", infos.CodEqui);
 printf("\nNome do Equipamento: %s", infos.NomeEqui);
 ImprimeLista(infos.IL);
}

void ImprimeEqui (Equipamento *E[], int cod){
    int chave = CalculaChave(cod);
    Equipamento *aux = E[chave];
    while(aux != NULL){
        if(aux->dados.CodEqui == cod){
            ImprimePorCod(aux->dados);
        }
        aux = aux->prox;
    }
}

int ExisteEqui (Equipamento *E[], int chave, int cod){
    Equipamento *aux = E[chave];
    while(aux != NULL){
        if(aux->dados.CodEqui == cod){
            printf("\nExiste um equipamento com esse código\n");
            ImprimePorCod(aux->dados);
            return 0;
        }
        aux = aux->prox;
    }
    printf("\nNão existe um equipamento com esse código\n");
    return 1;
}

void InserirInciEqui(Equipamento *E[], int codEqui, int codInci){
    printf("\nentrou no InserirINCIEqui");
    int chave = CalculaChave(codEqui);
    Equipamento *colocador = E[chave];
    printf("\nCalculou chave %d, e achou o lugar na tabela", chave);
    while(colocador!=NULL){
        if(colocador->dados.CodEqui == codEqui){
           ColocaInciEqui(colocador->dados.IL, codInci);
        }
        colocador = colocador->prox;
    }
}

void ApagaInciEqui(Equipamento *E[], int codEqui, int codInci){
    int chave = CalculaChave(codEqui);
    Equipamento *aux = E[chave];

    while(aux!=NULL){
        if(aux->dados.CodEqui == codEqui){
           TiraInciEqui(aux->dados.IL, codInci);
        }
        aux = aux->prox;
    }
    ImprimePorCod(aux->dados);
}


int RemoveEqui(Equipamento *tab[], int cod){
    int chave = CalculaChave(cod);
    Equipamento *p = tab[chave];
    Equipamento *ant = NULL;

    while(p != NULL && p->dados.CodEqui != cod){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return 0;
    }
    if(ant  == NULL){
        tab[chave] = p->prox;
    } else {
        ant->prox = p->prox;
    }

    liberaLista(p->dados.IL);
    free(p);
    return 1;
}

#endif // TABELAHASH_H_INCLUDED
